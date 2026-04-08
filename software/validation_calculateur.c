/*
 * validation_calculateur.c
 * Validation SW du calculateur cable via Nios II + PIOs Qsys.
 *
 * Mapping utilise (nios_system_sdram.sopcinfo):
 * - sensor_control @ 0x1020 (out, 8 bits)
 * - sensor_status  @ 0x1030 (in, 8 bits)
 * - sensor_data6   @ 0x10A0 (in, 8 bits) -> resultat calculateur
 * - kp             @ 0x10B0 (out, 12 bits) -> operande i (8 LSB)
 * - start_sl       @ 0x1110 (out, 1 bit)  -> impulsion start
 * - kd             @ 0x1120 (out, 12 bits) -> operande j (8 LSB)
 */

#include <stdint.h>
#include <stdio.h>

#define SENSOR_CONTROL_BASE 0x00001020u
#define SENSOR_STATUS_BASE  0x00001030u
#define SENSOR_DATA6_BASE   0x000010A0u
#define KP_BASE             0x000010B0u
#define START_SL_BASE       0x00001110u
#define KD_BASE             0x00001120u

#define LEDS_BASE           0x00002010u

#define CTRL_OP_MASK        0x03u
#define CTRL_SRC_SENSOR     0x04u /* bit2: 1=sensor0/1, 0=kp/kd */

#define STATUS_DONE_MASK    0x01u
#define STATUS_OVF_MASK     0x02u
#define STATUS_SENSOR_RDY   0x04u

#define IOWR(base, data) (*((volatile uint32_t*)(base)) = (uint32_t)(data))
#define IORD(base)       (*((volatile uint32_t*)(base)))

static uint8_t ref_model(uint8_t a, uint8_t b, uint8_t op, uint8_t* ovf)
{
  uint16_t tmp;
  *ovf = 0;

  switch (op & 0x3u) {
    case 0u: /* add */
      tmp = (uint16_t)a + (uint16_t)b;
      if (tmp > 255u) {
        *ovf = 1u;
        return 255u;
      }
      return (uint8_t)tmp;

    case 1u: /* sub with floor at 0 */
      if (a >= b) {
        return (uint8_t)(a - b);
      }
      *ovf = 1u;
      return 0u;

    case 2u: /* amp x2 */
      tmp = ((uint16_t)a << 1);
      if (tmp > 255u) {
        *ovf = 1u;
        return 255u;
      }
      return (uint8_t)tmp;

    default: /* att /2 */
      return (uint8_t)(a >> 1);
  }
}

static void start_calc(uint8_t op, uint8_t use_sensor_operands, uint8_t a, uint8_t b)
{
  uint32_t ctrl;

  IOWR(KP_BASE, (uint32_t)a);
  IOWR(KD_BASE, (uint32_t)b);

  ctrl = (uint32_t)(op & CTRL_OP_MASK);
  if (use_sensor_operands != 0u) {
    ctrl |= CTRL_SRC_SENSOR;
  }

  IOWR(SENSOR_CONTROL_BASE, ctrl);

  /* Rising edge expected by VHDL on start_sl */
  IOWR(START_SL_BASE, 1u);
  IOWR(START_SL_BASE, 0u);
}

int main(void)
{
  const uint8_t a_vals[] = {0u, 1u, 10u, 127u, 200u, 240u, 255u};
  const uint8_t b_vals[] = {0u, 1u,  5u,  64u, 100u, 200u, 255u};
  unsigned errors = 0u;

  printf("=== Validation calculateur cable via Nios/Qsys ===\n");

  IOWR(SENSOR_CONTROL_BASE, 0u);
  IOWR(START_SL_BASE, 0u);
  IOWR(LEDS_BASE, 0x00u);

  uint8_t op = 0u;
  for (op = 0u; op < 4u; ++op) {
    unsigned i = 0u;
    for (i = 0u; i < (sizeof(a_vals) / sizeof(a_vals[0])); ++i) {
      uint8_t a = a_vals[i];
      uint8_t b = b_vals[i];
      uint8_t sw_res;
      uint8_t sw_ovf;
      uint8_t hw_res;
      uint8_t hw_ovf;
      uint32_t st;
      uint32_t timeout;

      start_calc(op, 0u, a, b);

      timeout = 2000000u;
      do {
        st = IORD(SENSOR_STATUS_BASE);
        --timeout;
      } while (((st & STATUS_DONE_MASK) == 0u) && (timeout != 0u));

      if (timeout == 0u) {
        ++errors;
        printf("TIMEOUT op=%u a=%u b=%u (status=0x%02X)\n", op, a, b, (unsigned)st);
        continue;
      }

      hw_res = (uint8_t)(IORD(SENSOR_DATA6_BASE) & 0xFFu);
      hw_ovf = (uint8_t)((st & STATUS_OVF_MASK) ? 1u : 0u);

      sw_res = ref_model(a, b, op, &sw_ovf);
      if ((hw_res != sw_res) || (hw_ovf != sw_ovf)) {
        ++errors;
        printf("ERR op=%u a=%u b=%u | hw=(%u,%u) sw=(%u,%u)\n",
               op, a, b, hw_res, hw_ovf, sw_res, sw_ovf);
      }

      IOWR(LEDS_BASE, (uint32_t)hw_res);
    }
  }

  if (errors == 0u) {
    printf("OK: no HW/SW mismatch.\n");
    return 0;
  }

  printf("FAIL: %u mismatches detected.\n", errors);
  return 1;
}
