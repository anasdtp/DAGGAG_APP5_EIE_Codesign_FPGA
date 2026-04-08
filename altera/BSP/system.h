/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys_0' in SOPC Builder design 'nios_system_sdram'
 * SOPC Builder design path: C:/Users/mdaggag/Documents/Quartus/DAGGAG_APP5_EIE_Codesign_FPGA/nios_system_sdram.sopcinfo
 *
 * Generated: Wed Apr 08 15:51:32 CEST 2026
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x1820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1b
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x4000020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x1b
#define ALT_CPU_NAME "nios2_qsys_0"
#define ALT_CPU_RESET_ADDR 0x4000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x1820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x1b
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x4000020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x1b
#define NIOS2_RESET_ADDR 0x4000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_NIOS2_QSYS


/*
 * LEDs configuration
 *
 */

#define ALT_MODULE_CLASS_LEDs altera_avalon_pio
#define LEDS_BASE 0x2010
#define LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDS_CAPTURE 0
#define LEDS_DATA_WIDTH 8
#define LEDS_DO_TEST_BENCH_WIRING 0
#define LEDS_DRIVEN_SIM_VALUE 0
#define LEDS_EDGE_TYPE "NONE"
#define LEDS_FREQ 50000000
#define LEDS_HAS_IN 0
#define LEDS_HAS_OUT 1
#define LEDS_HAS_TRI 0
#define LEDS_IRQ -1
#define LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDS_IRQ_TYPE "NONE"
#define LEDS_NAME "/dev/LEDs"
#define LEDS_RESET_VALUE 0
#define LEDS_SPAN 16
#define LEDS_TYPE "altera_avalon_pio"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x2020
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x2020
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x2020
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_system_sdram"


/*
 * base_speed configuration
 *
 */

#define ALT_MODULE_CLASS_base_speed altera_avalon_pio
#define BASE_SPEED_BASE 0x10c0
#define BASE_SPEED_BIT_CLEARING_EDGE_REGISTER 0
#define BASE_SPEED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BASE_SPEED_CAPTURE 0
#define BASE_SPEED_DATA_WIDTH 12
#define BASE_SPEED_DO_TEST_BENCH_WIRING 0
#define BASE_SPEED_DRIVEN_SIM_VALUE 0
#define BASE_SPEED_EDGE_TYPE "NONE"
#define BASE_SPEED_FREQ 50000000
#define BASE_SPEED_HAS_IN 0
#define BASE_SPEED_HAS_OUT 1
#define BASE_SPEED_HAS_TRI 0
#define BASE_SPEED_IRQ -1
#define BASE_SPEED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BASE_SPEED_IRQ_TYPE "NONE"
#define BASE_SPEED_NAME "/dev/base_speed"
#define BASE_SPEED_RESET_VALUE 1856
#define BASE_SPEED_SPAN 16
#define BASE_SPEED_TYPE "altera_avalon_pio"


/*
 * dir_rot configuration
 *
 */

#define ALT_MODULE_CLASS_dir_rot altera_avalon_pio
#define DIR_ROT_BASE 0x10e0
#define DIR_ROT_BIT_CLEARING_EDGE_REGISTER 0
#define DIR_ROT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DIR_ROT_CAPTURE 0
#define DIR_ROT_DATA_WIDTH 1
#define DIR_ROT_DO_TEST_BENCH_WIRING 0
#define DIR_ROT_DRIVEN_SIM_VALUE 0
#define DIR_ROT_EDGE_TYPE "NONE"
#define DIR_ROT_FREQ 50000000
#define DIR_ROT_HAS_IN 0
#define DIR_ROT_HAS_OUT 1
#define DIR_ROT_HAS_TRI 0
#define DIR_ROT_IRQ -1
#define DIR_ROT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DIR_ROT_IRQ_TYPE "NONE"
#define DIR_ROT_NAME "/dev/dir_rot"
#define DIR_ROT_RESET_VALUE 0
#define DIR_ROT_SPAN 16
#define DIR_ROT_TYPE "altera_avalon_pio"


/*
 * fin_rot configuration
 *
 */

#define ALT_MODULE_CLASS_fin_rot altera_avalon_pio
#define FIN_ROT_BASE 0x10d0
#define FIN_ROT_BIT_CLEARING_EDGE_REGISTER 0
#define FIN_ROT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define FIN_ROT_CAPTURE 0
#define FIN_ROT_DATA_WIDTH 1
#define FIN_ROT_DO_TEST_BENCH_WIRING 0
#define FIN_ROT_DRIVEN_SIM_VALUE 0
#define FIN_ROT_EDGE_TYPE "NONE"
#define FIN_ROT_FREQ 50000000
#define FIN_ROT_HAS_IN 1
#define FIN_ROT_HAS_OUT 0
#define FIN_ROT_HAS_TRI 0
#define FIN_ROT_IRQ -1
#define FIN_ROT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIN_ROT_IRQ_TYPE "NONE"
#define FIN_ROT_NAME "/dev/fin_rot"
#define FIN_ROT_RESET_VALUE 0
#define FIN_ROT_SPAN 16
#define FIN_ROT_TYPE "altera_avalon_pio"


/*
 * fin_sl configuration
 *
 */

#define ALT_MODULE_CLASS_fin_sl altera_avalon_pio
#define FIN_SL_BASE 0x1100
#define FIN_SL_BIT_CLEARING_EDGE_REGISTER 0
#define FIN_SL_BIT_MODIFYING_OUTPUT_REGISTER 0
#define FIN_SL_CAPTURE 0
#define FIN_SL_DATA_WIDTH 1
#define FIN_SL_DO_TEST_BENCH_WIRING 0
#define FIN_SL_DRIVEN_SIM_VALUE 0
#define FIN_SL_EDGE_TYPE "NONE"
#define FIN_SL_FREQ 50000000
#define FIN_SL_HAS_IN 1
#define FIN_SL_HAS_OUT 0
#define FIN_SL_HAS_TRI 0
#define FIN_SL_IRQ -1
#define FIN_SL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIN_SL_IRQ_TYPE "NONE"
#define FIN_SL_NAME "/dev/fin_sl"
#define FIN_SL_RESET_VALUE 0
#define FIN_SL_SPAN 16
#define FIN_SL_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x2020
#define JTAG_UART_0_IRQ 5
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * kd configuration
 *
 */

#define ALT_MODULE_CLASS_kd altera_avalon_pio
#define KD_BASE 0x1120
#define KD_BIT_CLEARING_EDGE_REGISTER 0
#define KD_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KD_CAPTURE 0
#define KD_DATA_WIDTH 12
#define KD_DO_TEST_BENCH_WIRING 0
#define KD_DRIVEN_SIM_VALUE 0
#define KD_EDGE_TYPE "NONE"
#define KD_FREQ 50000000
#define KD_HAS_IN 0
#define KD_HAS_OUT 1
#define KD_HAS_TRI 0
#define KD_IRQ -1
#define KD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define KD_IRQ_TYPE "NONE"
#define KD_NAME "/dev/kd"
#define KD_RESET_VALUE 50
#define KD_SPAN 16
#define KD_TYPE "altera_avalon_pio"


/*
 * kp configuration
 *
 */

#define ALT_MODULE_CLASS_kp altera_avalon_pio
#define KP_BASE 0x10b0
#define KP_BIT_CLEARING_EDGE_REGISTER 0
#define KP_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KP_CAPTURE 0
#define KP_DATA_WIDTH 12
#define KP_DO_TEST_BENCH_WIRING 0
#define KP_DRIVEN_SIM_VALUE 0
#define KP_EDGE_TYPE "NONE"
#define KP_FREQ 50000000
#define KP_HAS_IN 0
#define KP_HAS_OUT 1
#define KP_HAS_TRI 0
#define KP_IRQ -1
#define KP_IRQ_INTERRUPT_CONTROLLER_ID -1
#define KP_IRQ_TYPE "NONE"
#define KP_NAME "/dev/kp"
#define KP_RESET_VALUE 1000
#define KP_SPAN 16
#define KP_TYPE "altera_avalon_pio"


/*
 * motor_left configuration
 *
 */

#define ALT_MODULE_CLASS_motor_left altera_avalon_pio
#define MOTOR_LEFT_BASE 0x1000
#define MOTOR_LEFT_BIT_CLEARING_EDGE_REGISTER 0
#define MOTOR_LEFT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define MOTOR_LEFT_CAPTURE 0
#define MOTOR_LEFT_DATA_WIDTH 14
#define MOTOR_LEFT_DO_TEST_BENCH_WIRING 0
#define MOTOR_LEFT_DRIVEN_SIM_VALUE 0
#define MOTOR_LEFT_EDGE_TYPE "NONE"
#define MOTOR_LEFT_FREQ 50000000
#define MOTOR_LEFT_HAS_IN 0
#define MOTOR_LEFT_HAS_OUT 1
#define MOTOR_LEFT_HAS_TRI 0
#define MOTOR_LEFT_IRQ -1
#define MOTOR_LEFT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MOTOR_LEFT_IRQ_TYPE "NONE"
#define MOTOR_LEFT_NAME "/dev/motor_left"
#define MOTOR_LEFT_RESET_VALUE 0
#define MOTOR_LEFT_SPAN 16
#define MOTOR_LEFT_TYPE "altera_avalon_pio"


/*
 * motor_right configuration
 *
 */

#define ALT_MODULE_CLASS_motor_right altera_avalon_pio
#define MOTOR_RIGHT_BASE 0x1010
#define MOTOR_RIGHT_BIT_CLEARING_EDGE_REGISTER 0
#define MOTOR_RIGHT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define MOTOR_RIGHT_CAPTURE 0
#define MOTOR_RIGHT_DATA_WIDTH 14
#define MOTOR_RIGHT_DO_TEST_BENCH_WIRING 0
#define MOTOR_RIGHT_DRIVEN_SIM_VALUE 0
#define MOTOR_RIGHT_EDGE_TYPE "NONE"
#define MOTOR_RIGHT_FREQ 50000000
#define MOTOR_RIGHT_HAS_IN 0
#define MOTOR_RIGHT_HAS_OUT 1
#define MOTOR_RIGHT_HAS_TRI 0
#define MOTOR_RIGHT_IRQ -1
#define MOTOR_RIGHT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MOTOR_RIGHT_IRQ_TYPE "NONE"
#define MOTOR_RIGHT_NAME "/dev/motor_right"
#define MOTOR_RIGHT_RESET_VALUE 0
#define MOTOR_RIGHT_SPAN 16
#define MOTOR_RIGHT_TYPE "altera_avalon_pio"


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x0
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "nios_system_sdram_onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 4096
#define ONCHIP_MEMORY2_0_SPAN 4096
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * sdram configuration
 *
 */

#define ALT_MODULE_CLASS_sdram altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x4000000
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/sdram"
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 15.625
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x18
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 9
#define SDRAM_SDRAM_DATA_WIDTH 16
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 13
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 0
#define SDRAM_SPAN 33554432
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_T_AC 5.5
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 20.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 20.0
#define SDRAM_T_WR 14.0


/*
 * sensor_control configuration
 *
 */

#define ALT_MODULE_CLASS_sensor_control altera_avalon_pio
#define SENSOR_CONTROL_BASE 0x1020
#define SENSOR_CONTROL_BIT_CLEARING_EDGE_REGISTER 0
#define SENSOR_CONTROL_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SENSOR_CONTROL_CAPTURE 0
#define SENSOR_CONTROL_DATA_WIDTH 8
#define SENSOR_CONTROL_DO_TEST_BENCH_WIRING 0
#define SENSOR_CONTROL_DRIVEN_SIM_VALUE 0
#define SENSOR_CONTROL_EDGE_TYPE "NONE"
#define SENSOR_CONTROL_FREQ 50000000
#define SENSOR_CONTROL_HAS_IN 0
#define SENSOR_CONTROL_HAS_OUT 1
#define SENSOR_CONTROL_HAS_TRI 0
#define SENSOR_CONTROL_IRQ -1
#define SENSOR_CONTROL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SENSOR_CONTROL_IRQ_TYPE "NONE"
#define SENSOR_CONTROL_NAME "/dev/sensor_control"
#define SENSOR_CONTROL_RESET_VALUE 0
#define SENSOR_CONTROL_SPAN 16
#define SENSOR_CONTROL_TYPE "altera_avalon_pio"


/*
 * sensor_data0 configuration
 *
 */

#define ALT_MODULE_CLASS_sensor_data0 altera_avalon_pio
#define SENSOR_DATA0_BASE 0x1040
#define SENSOR_DATA0_BIT_CLEARING_EDGE_REGISTER 0
#define SENSOR_DATA0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SENSOR_DATA0_CAPTURE 0
#define SENSOR_DATA0_DATA_WIDTH 8
#define SENSOR_DATA0_DO_TEST_BENCH_WIRING 0
#define SENSOR_DATA0_DRIVEN_SIM_VALUE 0
#define SENSOR_DATA0_EDGE_TYPE "NONE"
#define SENSOR_DATA0_FREQ 50000000
#define SENSOR_DATA0_HAS_IN 1
#define SENSOR_DATA0_HAS_OUT 0
#define SENSOR_DATA0_HAS_TRI 0
#define SENSOR_DATA0_IRQ -1
#define SENSOR_DATA0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SENSOR_DATA0_IRQ_TYPE "NONE"
#define SENSOR_DATA0_NAME "/dev/sensor_data0"
#define SENSOR_DATA0_RESET_VALUE 0
#define SENSOR_DATA0_SPAN 16
#define SENSOR_DATA0_TYPE "altera_avalon_pio"


/*
 * sensor_data1 configuration
 *
 */

#define ALT_MODULE_CLASS_sensor_data1 altera_avalon_pio
#define SENSOR_DATA1_BASE 0x1050
#define SENSOR_DATA1_BIT_CLEARING_EDGE_REGISTER 0
#define SENSOR_DATA1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SENSOR_DATA1_CAPTURE 0
#define SENSOR_DATA1_DATA_WIDTH 8
#define SENSOR_DATA1_DO_TEST_BENCH_WIRING 0
#define SENSOR_DATA1_DRIVEN_SIM_VALUE 0
#define SENSOR_DATA1_EDGE_TYPE "NONE"
#define SENSOR_DATA1_FREQ 50000000
#define SENSOR_DATA1_HAS_IN 1
#define SENSOR_DATA1_HAS_OUT 0
#define SENSOR_DATA1_HAS_TRI 0
#define SENSOR_DATA1_IRQ -1
#define SENSOR_DATA1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SENSOR_DATA1_IRQ_TYPE "NONE"
#define SENSOR_DATA1_NAME "/dev/sensor_data1"
#define SENSOR_DATA1_RESET_VALUE 0
#define SENSOR_DATA1_SPAN 16
#define SENSOR_DATA1_TYPE "altera_avalon_pio"


/*
 * sensor_data2 configuration
 *
 */

#define ALT_MODULE_CLASS_sensor_data2 altera_avalon_pio
#define SENSOR_DATA2_BASE 0x1060
#define SENSOR_DATA2_BIT_CLEARING_EDGE_REGISTER 0
#define SENSOR_DATA2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SENSOR_DATA2_CAPTURE 0
#define SENSOR_DATA2_DATA_WIDTH 8
#define SENSOR_DATA2_DO_TEST_BENCH_WIRING 0
#define SENSOR_DATA2_DRIVEN_SIM_VALUE 0
#define SENSOR_DATA2_EDGE_TYPE "NONE"
#define SENSOR_DATA2_FREQ 50000000
#define SENSOR_DATA2_HAS_IN 1
#define SENSOR_DATA2_HAS_OUT 0
#define SENSOR_DATA2_HAS_TRI 0
#define SENSOR_DATA2_IRQ -1
#define SENSOR_DATA2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SENSOR_DATA2_IRQ_TYPE "NONE"
#define SENSOR_DATA2_NAME "/dev/sensor_data2"
#define SENSOR_DATA2_RESET_VALUE 0
#define SENSOR_DATA2_SPAN 16
#define SENSOR_DATA2_TYPE "altera_avalon_pio"


/*
 * sensor_data3 configuration
 *
 */

#define ALT_MODULE_CLASS_sensor_data3 altera_avalon_pio
#define SENSOR_DATA3_BASE 0x1070
#define SENSOR_DATA3_BIT_CLEARING_EDGE_REGISTER 0
#define SENSOR_DATA3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SENSOR_DATA3_CAPTURE 0
#define SENSOR_DATA3_DATA_WIDTH 8
#define SENSOR_DATA3_DO_TEST_BENCH_WIRING 0
#define SENSOR_DATA3_DRIVEN_SIM_VALUE 0
#define SENSOR_DATA3_EDGE_TYPE "NONE"
#define SENSOR_DATA3_FREQ 50000000
#define SENSOR_DATA3_HAS_IN 1
#define SENSOR_DATA3_HAS_OUT 0
#define SENSOR_DATA3_HAS_TRI 0
#define SENSOR_DATA3_IRQ -1
#define SENSOR_DATA3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SENSOR_DATA3_IRQ_TYPE "NONE"
#define SENSOR_DATA3_NAME "/dev/sensor_data3"
#define SENSOR_DATA3_RESET_VALUE 0
#define SENSOR_DATA3_SPAN 16
#define SENSOR_DATA3_TYPE "altera_avalon_pio"


/*
 * sensor_data4 configuration
 *
 */

#define ALT_MODULE_CLASS_sensor_data4 altera_avalon_pio
#define SENSOR_DATA4_BASE 0x1080
#define SENSOR_DATA4_BIT_CLEARING_EDGE_REGISTER 0
#define SENSOR_DATA4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SENSOR_DATA4_CAPTURE 0
#define SENSOR_DATA4_DATA_WIDTH 8
#define SENSOR_DATA4_DO_TEST_BENCH_WIRING 0
#define SENSOR_DATA4_DRIVEN_SIM_VALUE 0
#define SENSOR_DATA4_EDGE_TYPE "NONE"
#define SENSOR_DATA4_FREQ 50000000
#define SENSOR_DATA4_HAS_IN 1
#define SENSOR_DATA4_HAS_OUT 0
#define SENSOR_DATA4_HAS_TRI 0
#define SENSOR_DATA4_IRQ -1
#define SENSOR_DATA4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SENSOR_DATA4_IRQ_TYPE "NONE"
#define SENSOR_DATA4_NAME "/dev/sensor_data4"
#define SENSOR_DATA4_RESET_VALUE 0
#define SENSOR_DATA4_SPAN 16
#define SENSOR_DATA4_TYPE "altera_avalon_pio"


/*
 * sensor_data5 configuration
 *
 */

#define ALT_MODULE_CLASS_sensor_data5 altera_avalon_pio
#define SENSOR_DATA5_BASE 0x1090
#define SENSOR_DATA5_BIT_CLEARING_EDGE_REGISTER 0
#define SENSOR_DATA5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SENSOR_DATA5_CAPTURE 0
#define SENSOR_DATA5_DATA_WIDTH 8
#define SENSOR_DATA5_DO_TEST_BENCH_WIRING 0
#define SENSOR_DATA5_DRIVEN_SIM_VALUE 0
#define SENSOR_DATA5_EDGE_TYPE "NONE"
#define SENSOR_DATA5_FREQ 50000000
#define SENSOR_DATA5_HAS_IN 1
#define SENSOR_DATA5_HAS_OUT 0
#define SENSOR_DATA5_HAS_TRI 0
#define SENSOR_DATA5_IRQ -1
#define SENSOR_DATA5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SENSOR_DATA5_IRQ_TYPE "NONE"
#define SENSOR_DATA5_NAME "/dev/sensor_data5"
#define SENSOR_DATA5_RESET_VALUE 0
#define SENSOR_DATA5_SPAN 16
#define SENSOR_DATA5_TYPE "altera_avalon_pio"


/*
 * sensor_data6 configuration
 *
 */

#define ALT_MODULE_CLASS_sensor_data6 altera_avalon_pio
#define SENSOR_DATA6_BASE 0x10a0
#define SENSOR_DATA6_BIT_CLEARING_EDGE_REGISTER 0
#define SENSOR_DATA6_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SENSOR_DATA6_CAPTURE 0
#define SENSOR_DATA6_DATA_WIDTH 8
#define SENSOR_DATA6_DO_TEST_BENCH_WIRING 0
#define SENSOR_DATA6_DRIVEN_SIM_VALUE 0
#define SENSOR_DATA6_EDGE_TYPE "NONE"
#define SENSOR_DATA6_FREQ 50000000
#define SENSOR_DATA6_HAS_IN 1
#define SENSOR_DATA6_HAS_OUT 0
#define SENSOR_DATA6_HAS_TRI 0
#define SENSOR_DATA6_IRQ -1
#define SENSOR_DATA6_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SENSOR_DATA6_IRQ_TYPE "NONE"
#define SENSOR_DATA6_NAME "/dev/sensor_data6"
#define SENSOR_DATA6_RESET_VALUE 0
#define SENSOR_DATA6_SPAN 16
#define SENSOR_DATA6_TYPE "altera_avalon_pio"


/*
 * sensor_status configuration
 *
 */

#define ALT_MODULE_CLASS_sensor_status altera_avalon_pio
#define SENSOR_STATUS_BASE 0x1030
#define SENSOR_STATUS_BIT_CLEARING_EDGE_REGISTER 0
#define SENSOR_STATUS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SENSOR_STATUS_CAPTURE 0
#define SENSOR_STATUS_DATA_WIDTH 8
#define SENSOR_STATUS_DO_TEST_BENCH_WIRING 0
#define SENSOR_STATUS_DRIVEN_SIM_VALUE 0
#define SENSOR_STATUS_EDGE_TYPE "NONE"
#define SENSOR_STATUS_FREQ 50000000
#define SENSOR_STATUS_HAS_IN 1
#define SENSOR_STATUS_HAS_OUT 0
#define SENSOR_STATUS_HAS_TRI 0
#define SENSOR_STATUS_IRQ -1
#define SENSOR_STATUS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SENSOR_STATUS_IRQ_TYPE "NONE"
#define SENSOR_STATUS_NAME "/dev/sensor_status"
#define SENSOR_STATUS_RESET_VALUE 0
#define SENSOR_STATUS_SPAN 16
#define SENSOR_STATUS_TYPE "altera_avalon_pio"


/*
 * start_rot configuration
 *
 */

#define ALT_MODULE_CLASS_start_rot altera_avalon_pio
#define START_ROT_BASE 0x10f0
#define START_ROT_BIT_CLEARING_EDGE_REGISTER 0
#define START_ROT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define START_ROT_CAPTURE 0
#define START_ROT_DATA_WIDTH 1
#define START_ROT_DO_TEST_BENCH_WIRING 0
#define START_ROT_DRIVEN_SIM_VALUE 0
#define START_ROT_EDGE_TYPE "NONE"
#define START_ROT_FREQ 50000000
#define START_ROT_HAS_IN 0
#define START_ROT_HAS_OUT 1
#define START_ROT_HAS_TRI 0
#define START_ROT_IRQ -1
#define START_ROT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define START_ROT_IRQ_TYPE "NONE"
#define START_ROT_NAME "/dev/start_rot"
#define START_ROT_RESET_VALUE 0
#define START_ROT_SPAN 16
#define START_ROT_TYPE "altera_avalon_pio"


/*
 * start_sl configuration
 *
 */

#define ALT_MODULE_CLASS_start_sl altera_avalon_pio
#define START_SL_BASE 0x1110
#define START_SL_BIT_CLEARING_EDGE_REGISTER 0
#define START_SL_BIT_MODIFYING_OUTPUT_REGISTER 0
#define START_SL_CAPTURE 0
#define START_SL_DATA_WIDTH 1
#define START_SL_DO_TEST_BENCH_WIRING 0
#define START_SL_DRIVEN_SIM_VALUE 0
#define START_SL_EDGE_TYPE "NONE"
#define START_SL_FREQ 50000000
#define START_SL_HAS_IN 0
#define START_SL_HAS_OUT 1
#define START_SL_HAS_TRI 0
#define START_SL_IRQ -1
#define START_SL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define START_SL_IRQ_TYPE "NONE"
#define START_SL_NAME "/dev/start_sl"
#define START_SL_RESET_VALUE 0
#define START_SL_SPAN 16
#define START_SL_TYPE "altera_avalon_pio"


/*
 * switches configuration
 *
 */

#define ALT_MODULE_CLASS_switches altera_avalon_pio
#define SWITCHES_BASE 0x2000
#define SWITCHES_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCHES_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCHES_CAPTURE 0
#define SWITCHES_DATA_WIDTH 8
#define SWITCHES_DO_TEST_BENCH_WIRING 0
#define SWITCHES_DRIVEN_SIM_VALUE 0
#define SWITCHES_EDGE_TYPE "NONE"
#define SWITCHES_FREQ 50000000
#define SWITCHES_HAS_IN 1
#define SWITCHES_HAS_OUT 0
#define SWITCHES_HAS_TRI 0
#define SWITCHES_IRQ -1
#define SWITCHES_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SWITCHES_IRQ_TYPE "NONE"
#define SWITCHES_NAME "/dev/switches"
#define SWITCHES_RESET_VALUE 0
#define SWITCHES_SPAN 16
#define SWITCHES_TYPE "altera_avalon_pio"

#endif /* __SYSTEM_H_ */
