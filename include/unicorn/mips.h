#ifndef UNICORN_MIPS_H
#define UNICORN_MIPS_H

/* Unicorn Emulator Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2015 */

#ifdef __cplusplus
extern "C" {
#endif

// GCC MIPS toolchain has a default macro called "mips" which breaks
// compilation
#undef mips

#ifdef _MSC_VER
#pragma warning(disable:4201)
#endif

//> MIPS registers
typedef enum mips_reg {
	MIPS_REG_INVALID = 0,
	//> General purpose registers
	MIPS_REG_PC,

	MIPS_REG_0,
	MIPS_REG_1,
	MIPS_REG_2,
	MIPS_REG_3,
	MIPS_REG_4,
	MIPS_REG_5,
	MIPS_REG_6,
	MIPS_REG_7,
	MIPS_REG_8,
	MIPS_REG_9,
	MIPS_REG_10,
	MIPS_REG_11,
	MIPS_REG_12,
	MIPS_REG_13,
	MIPS_REG_14,
	MIPS_REG_15,
	MIPS_REG_16,
	MIPS_REG_17,
	MIPS_REG_18,
	MIPS_REG_19,
	MIPS_REG_20,
	MIPS_REG_21,
	MIPS_REG_22,
	MIPS_REG_23,
	MIPS_REG_24,
	MIPS_REG_25,
	MIPS_REG_26,
	MIPS_REG_27,
	MIPS_REG_28,
	MIPS_REG_29,
	MIPS_REG_30,
	MIPS_REG_31,

	//> DSP registers
	MIPS_REG_DSPCCOND,
	MIPS_REG_DSPCARRY,
	MIPS_REG_DSPEFI,
	MIPS_REG_DSPOUTFLAG,
	MIPS_REG_DSPOUTFLAG16_19,
	MIPS_REG_DSPOUTFLAG20,
	MIPS_REG_DSPOUTFLAG21,
	MIPS_REG_DSPOUTFLAG22,
	MIPS_REG_DSPOUTFLAG23,
	MIPS_REG_DSPPOS,
	MIPS_REG_DSPSCOUNT,

	//> ACC registers
	MIPS_REG_AC0,
	MIPS_REG_AC1,
	MIPS_REG_AC2,
	MIPS_REG_AC3,

	//> COP registers
	MIPS_REG_CC0,
	MIPS_REG_CC1,
	MIPS_REG_CC2,
	MIPS_REG_CC3,
	MIPS_REG_CC4,
	MIPS_REG_CC5,
	MIPS_REG_CC6,
	MIPS_REG_CC7,

	//> FPU registers
	MIPS_REG_F0,
	MIPS_REG_F1,
	MIPS_REG_F2,
	MIPS_REG_F3,
	MIPS_REG_F4,
	MIPS_REG_F5,
	MIPS_REG_F6,
	MIPS_REG_F7,
	MIPS_REG_F8,
	MIPS_REG_F9,
	MIPS_REG_F10,
	MIPS_REG_F11,
	MIPS_REG_F12,
	MIPS_REG_F13,
	MIPS_REG_F14,
	MIPS_REG_F15,
	MIPS_REG_F16,
	MIPS_REG_F17,
	MIPS_REG_F18,
	MIPS_REG_F19,
	MIPS_REG_F20,
	MIPS_REG_F21,
	MIPS_REG_F22,
	MIPS_REG_F23,
	MIPS_REG_F24,
	MIPS_REG_F25,
	MIPS_REG_F26,
	MIPS_REG_F27,
	MIPS_REG_F28,
	MIPS_REG_F29,
	MIPS_REG_F30,
	MIPS_REG_F31,

	MIPS_REG_FCC0,
	MIPS_REG_FCC1,
	MIPS_REG_FCC2,
	MIPS_REG_FCC3,
	MIPS_REG_FCC4,
	MIPS_REG_FCC5,
	MIPS_REG_FCC6,
	MIPS_REG_FCC7,

	//> AFPR128
	MIPS_REG_W0,
	MIPS_REG_W1,
	MIPS_REG_W2,
	MIPS_REG_W3,
	MIPS_REG_W4,
	MIPS_REG_W5,
	MIPS_REG_W6,
	MIPS_REG_W7,
	MIPS_REG_W8,
	MIPS_REG_W9,
	MIPS_REG_W10,
	MIPS_REG_W11,
	MIPS_REG_W12,
	MIPS_REG_W13,
	MIPS_REG_W14,
	MIPS_REG_W15,
	MIPS_REG_W16,
	MIPS_REG_W17,
	MIPS_REG_W18,
	MIPS_REG_W19,
	MIPS_REG_W20,
	MIPS_REG_W21,
	MIPS_REG_W22,
	MIPS_REG_W23,
	MIPS_REG_W24,
	MIPS_REG_W25,
	MIPS_REG_W26,
	MIPS_REG_W27,
	MIPS_REG_W28,
	MIPS_REG_W29,
	MIPS_REG_W30,
	MIPS_REG_W31,

	MIPS_REG_HI,
	MIPS_REG_LO,

	MIPS_REG_P0,
	MIPS_REG_P1,
	MIPS_REG_P2,

	MIPS_REG_MPL0,
	MIPS_REG_MPL1,
	MIPS_REG_MPL2,

	MIPS_REG_ENDING,	// <-- mark the end of the list or registers

	// alias registers
	MIPS_REG_ZERO = MIPS_REG_0,
	MIPS_REG_AT = MIPS_REG_1,
	MIPS_REG_V0 = MIPS_REG_2,
	MIPS_REG_V1 = MIPS_REG_3,
	MIPS_REG_A0 = MIPS_REG_4,
	MIPS_REG_A1 = MIPS_REG_5,
	MIPS_REG_A2 = MIPS_REG_6,
	MIPS_REG_A3 = MIPS_REG_7,
	MIPS_REG_T0 = MIPS_REG_8,
	MIPS_REG_T1 = MIPS_REG_9,
	MIPS_REG_T2 = MIPS_REG_10,
	MIPS_REG_T3 = MIPS_REG_11,
	MIPS_REG_T4 = MIPS_REG_12,
	MIPS_REG_T5 = MIPS_REG_13,
	MIPS_REG_T6 = MIPS_REG_14,
	MIPS_REG_T7 = MIPS_REG_15,
	MIPS_REG_S0 = MIPS_REG_16,
	MIPS_REG_S1 = MIPS_REG_17,
	MIPS_REG_S2 = MIPS_REG_18,
	MIPS_REG_S3 = MIPS_REG_19,
	MIPS_REG_S4 = MIPS_REG_20,
	MIPS_REG_S5 = MIPS_REG_21,
	MIPS_REG_S6 = MIPS_REG_22,
	MIPS_REG_S7 = MIPS_REG_23,
	MIPS_REG_T8 = MIPS_REG_24,
	MIPS_REG_T9 = MIPS_REG_25,
	MIPS_REG_K0 = MIPS_REG_26,
	MIPS_REG_K1 = MIPS_REG_27,
	MIPS_REG_GP = MIPS_REG_28,
	MIPS_REG_SP = MIPS_REG_29,
	MIPS_REG_FP = MIPS_REG_30, MIPS_REG_S8 = MIPS_REG_30,
	MIPS_REG_RA = MIPS_REG_31,

	MIPS_REG_HI0 = MIPS_REG_AC0,
	MIPS_REG_HI1 = MIPS_REG_AC1,
	MIPS_REG_HI2 = MIPS_REG_AC2,
	MIPS_REG_HI3 = MIPS_REG_AC3,

	MIPS_REG_LO0 = MIPS_REG_HI0,
	MIPS_REG_LO1 = MIPS_REG_HI1,
	MIPS_REG_LO2 = MIPS_REG_HI2,
	MIPS_REG_LO3 = MIPS_REG_HI3,
} mips_reg;

#ifdef __cplusplus
}
#endif

#endif
