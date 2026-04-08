/*
 * validation_calculateur.c
 * Software validation for the arithmetic hardware block.
 *
 * Update BASE addresses with values generated in your own system.h.
 */

#include <stdint.h>
#include <stdio.h>

#define CALC_CTRL_BASE    0x000010B0u  /* bit0=start, bits2:1=op_sel */
#define CALC_DATA_I_BASE  0x000010C0u  /* data_ir[7:0] */
#define CALC_DATA_J_BASE  0x000010D0u  /* data_jr[7:0] */
#define CALC_RES_BASE     0x000010E0u  /* result[7:0] */
#define CALC_STAT_BASE    0x000010F0u  /* bit0=ready, bit1=overflow */

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

int main(void)
{
  const uint8_t a_vals[] = {0u, 1u, 10u, 127u, 200u, 240u, 255u};
  const uint8_t b_vals[] = {0u, 1u,  5u,  64u, 100u, 200u, 255u};
  unsigned errors = 0u;

  printf("=== Validation calculateur cable ===\n");
  IOWR(CALC_CTRL_BASE, 0u);

  for (uint8_t op = 0u; op < 4u; ++op) {
    for (unsigned i = 0u; i < (sizeof(a_vals) / sizeof(a_vals[0])); ++i) {
      uint8_t a = a_vals[i];
      uint8_t b = b_vals[i];
      uint8_t sw_res;
      uint8_t sw_ovf;
      uint8_t hw_res;
      uint8_t hw_ovf;
      uint32_t st;

      IOWR(CALC_DATA_I_BASE, a);
      IOWR(CALC_DATA_J_BASE, b);

      IOWR(CALC_CTRL_BASE, (uint32_t)((op << 1) | 0x1u));
      IOWR(CALC_CTRL_BASE, (uint32_t)(op << 1));

      do {
        st = IORD(CALC_STAT_BASE);
      } while ((st & 0x1u) == 0u);

      hw_res = (uint8_t)(IORD(CALC_RES_BASE) & 0xFFu);
      hw_ovf = (uint8_t)((st >> 1) & 0x1u);

      sw_res = ref_model(a, b, op, &sw_ovf);
      if ((hw_res != sw_res) || (hw_ovf != sw_ovf)) {
        ++errors;
        printf("ERR op=%u a=%u b=%u | hw=(%u,%u) sw=(%u,%u)\n",
               op, a, b, hw_res, hw_ovf, sw_res, sw_ovf);
      }
    }
  }

  if (errors == 0u) {
    printf("OK: no HW/SW mismatch.\n");
    return 0;
  }

  printf("FAIL: %u mismatches detected.\n", errors);
  return 1;
}
