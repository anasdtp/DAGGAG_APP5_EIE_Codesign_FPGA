/*
 * manual_calculateur.c
 *
 * Test manuel du calculateur cable via Nios II + PIOs.
 *
 * Ce programme permet de:
 * 1) choisir l'operation (add/sub/x2//2)
 * 2) saisir deux operandes (a, b)
 * 3) declencher le calcul en hardware
 * 4) lire et afficher resultat + overflow
 *
 * Mapping Qsys utilise:
 * - sensor_control @ 0x1020 (out, 8 bits)
 * - sensor_status  @ 0x1030 (in, 8 bits)
 * - sensor_data6   @ 0x10A0 (in, 8 bits) -> resultat calculateur
 * - kp             @ 0x10B0 (out, 12 bits) -> operande a (8 LSB)
 * - start_sl       @ 0x1110 (out, 1 bit)  -> impulsion start
 * - kd             @ 0x1120 (out, 12 bits) -> operande b (8 LSB)
 * - LEDs           @ 0x2010 (out, 8 bits)
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    *ovf = 0u;

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

    /* Les PIO kp/kd font 12 bits, on ecrit ici les 8 bits utiles */
    IOWR(KP_BASE, (uint32_t)a);
    IOWR(KD_BASE, (uint32_t)b);

    ctrl = (uint32_t)(op & CTRL_OP_MASK);
    if (use_sensor_operands != 0u) {
        ctrl |= CTRL_SRC_SENSOR;
    }

    IOWR(SENSOR_CONTROL_BASE, ctrl);

    /* Impulsion de start: front montant sur start_sl */
    IOWR(START_SL_BASE, 1u);
    IOWR(START_SL_BASE, 0u);
}

static int read_int_line(const char* prompt, int min_v, int max_v, int* out)
{
    char line[64];
    long val;
    char* endptr;

    printf("%s", prompt);
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    /* Quitter rapidement */
    if (line[0] == 'q' || line[0] == 'Q') {
        return -1;
    }

    val = strtol(line, &endptr, 10);
    if (endptr == line || val < min_v || val > max_v) {
        return 0;
    }

    *out = (int)val;
    return 1;
}

int main(void)
{
    int op_i;
    int a_i;
    int b_i;

    printf("=== Test manuel calculateur cable ===\n");
    printf("Operations: 0:add  1:sub  2:x2  3:/2\n");
    printf("Entrez q pour quitter.\n\n");

    IOWR(SENSOR_CONTROL_BASE, 0u);
    IOWR(START_SL_BASE, 0u);
    IOWR(LEDS_BASE, 0u);

    while (1) {
        uint8_t op;
        uint8_t a;
        uint8_t b;
        uint8_t hw_res;
        uint8_t hw_ovf;
        uint8_t sw_res;
        uint8_t sw_ovf;
        uint32_t st;
        uint32_t timeout = 2000000u;
        int rc;

        rc = read_int_line("Operation [0..3]: ", 0, 3, &op_i);
        if (rc < 0) {
            break;
        }
        if (rc == 0) {
            printf("Valeur operation invalide.\n\n");
            continue;
        }

        rc = read_int_line("Operande a [0..255]: ", 0, 255, &a_i);
        if (rc < 0) {
            break;
        }
        if (rc == 0) {
            printf("Valeur a invalide.\n\n");
            continue;
        }

        rc = read_int_line("Operande b [0..255]: ", 0, 255, &b_i);
        if (rc < 0) {
            break;
        }
        if (rc == 0) {
            printf("Valeur b invalide.\n\n");
            continue;
        }

        op = (uint8_t)op_i;
        a = (uint8_t)a_i;
        b = (uint8_t)b_i;

        /* use_sensor_operands = 0 => prend kp/kd comme entrees du calculateur */
        start_calc(op, 0u, a, b);

        do {
            st = IORD(SENSOR_STATUS_BASE);
            --timeout;
        } while (((st & STATUS_DONE_MASK) == 0u) && (timeout != 0u));

        if (timeout == 0u) {
            printf("TIMEOUT: calcul non termine. status=0x%02X\n\n", (unsigned)st);
            continue;
        }

        hw_res = (uint8_t)(IORD(SENSOR_DATA6_BASE) & 0xFFu);
        hw_ovf = (uint8_t)((st & STATUS_OVF_MASK) ? 1u : 0u);

        sw_res = ref_model(a, b, op, &sw_ovf);

        printf("HW  => result=%u, ovf=%u, sensor_ready=%u\n",
               hw_res,
               hw_ovf,
               (unsigned)((st & STATUS_SENSOR_RDY) ? 1u : 0u));
        printf("REF => result=%u, ovf=%u\n", sw_res, sw_ovf);
        printf("%s\n\n", ((hw_res == sw_res) && (hw_ovf == sw_ovf)) ? "OK" : "MISMATCH");

        IOWR(LEDS_BASE, (uint32_t)hw_res);
    }

    IOWR(LEDS_BASE, 0u);
    printf("Fin du test manuel.\n");
    return 0;
}
