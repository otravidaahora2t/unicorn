/* Unicorn Emulator Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2014-2017 */
/* This file is released under LGPL2.
   See COPYING.LGPL2 in root directory for more details
*/

#ifndef UNICORN_M68K_H
#define UNICORN_M68K_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER
#pragma warning(disable : 4201)
#endif

typedef enum uc_cpu_m68k {
    UC_CPU_M5206_CPU = 0,
    UC_CPU_M68000_CPU,
    UC_CPU_M68020_CPU,
    UC_CPU_M68030_CPU,
    UC_CPU_M68040_CPU,
    UC_CPU_M68060_CPU,
    UC_CPU_M5208_CPU,
    UC_CPU_CFV4E_CPU,
    UC_CPU_ANY_CPU,
} uc_cpu_m68k;

//> M68K registers
typedef enum uc_m68k_reg {
    UC_M68K_REG_INVALID = 0,

    UC_M68K_REG_A0,
    UC_M68K_REG_A1,
    UC_M68K_REG_A2,
    UC_M68K_REG_A3,
    UC_M68K_REG_A4,
    UC_M68K_REG_A5,
    UC_M68K_REG_A6,
    UC_M68K_REG_A7,

    UC_M68K_REG_D0,
    UC_M68K_REG_D1,
    UC_M68K_REG_D2,
    UC_M68K_REG_D3,
    UC_M68K_REG_D4,
    UC_M68K_REG_D5,
    UC_M68K_REG_D6,
    UC_M68K_REG_D7,

    UC_M68K_REG_SR,
    UC_M68K_REG_PC,

    UC_M68K_REG_ENDING, // <-- mark the end of the list of registers
} uc_m68k_reg;

#ifdef __cplusplus
}
#endif

#endif
