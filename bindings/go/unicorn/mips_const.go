package unicorn
// For Unicorn Engine. AUTO-GENERATED FILE, DO NOT EDIT [mips_const.go]
const (

// MIPS32 CPUS

	CPU_MIPS32_4KC = 0
	CPU_MIPS32_4KM = 1
	CPU_MIPS32_4KECR1 = 2
	CPU_MIPS32_4KEMR1 = 3
	CPU_MIPS32_4KEC = 4
	CPU_MIPS32_4KEM = 5
	CPU_MIPS32_24KC = 6
	CPU_MIPS32_24KEC = 7
	CPU_MIPS32_24KF = 8
	CPU_MIPS32_34KF = 9
	CPU_MIPS32_74KF = 10
	CPU_MIPS32_M14K = 11
	CPU_MIPS32_M14KC = 12
	CPU_MIPS32_P5600 = 13
	CPU_MIPS32_MIPS32R6_GENERIC = 14
	CPU_MIPS32_I7200 = 15

// MIPS64 CPUS

	CPU_MIPS64_R4000 = 0
	CPU_MIPS64_VR5432 = 1
	CPU_MIPS64_5KC = 2
	CPU_MIPS64_5KF = 3
	CPU_MIPS64_20KC = 4
	CPU_MIPS64_MIPS64R2_GENERIC = 5
	CPU_MIPS64_5KEC = 6
	CPU_MIPS64_5KEF = 7
	CPU_MIPS64_I6400 = 8
	CPU_MIPS64_I6500 = 9
	CPU_MIPS64_LOONGSON_2E = 10
	CPU_MIPS64_LOONGSON_2F = 11
	CPU_MIPS64_MIPS64DSPR2 = 12

// MIPS registers

	MIPS_REG_INVALID = 0

// General purpose registers
	MIPS_REG_PC = 1
	MIPS_REG_0 = 2
	MIPS_REG_1 = 3
	MIPS_REG_2 = 4
	MIPS_REG_3 = 5
	MIPS_REG_4 = 6
	MIPS_REG_5 = 7
	MIPS_REG_6 = 8
	MIPS_REG_7 = 9
	MIPS_REG_8 = 10
	MIPS_REG_9 = 11
	MIPS_REG_10 = 12
	MIPS_REG_11 = 13
	MIPS_REG_12 = 14
	MIPS_REG_13 = 15
	MIPS_REG_14 = 16
	MIPS_REG_15 = 17
	MIPS_REG_16 = 18
	MIPS_REG_17 = 19
	MIPS_REG_18 = 20
	MIPS_REG_19 = 21
	MIPS_REG_20 = 22
	MIPS_REG_21 = 23
	MIPS_REG_22 = 24
	MIPS_REG_23 = 25
	MIPS_REG_24 = 26
	MIPS_REG_25 = 27
	MIPS_REG_26 = 28
	MIPS_REG_27 = 29
	MIPS_REG_28 = 30
	MIPS_REG_29 = 31
	MIPS_REG_30 = 32
	MIPS_REG_31 = 33

// DSP registers
	MIPS_REG_DSPCCOND = 34
	MIPS_REG_DSPCARRY = 35
	MIPS_REG_DSPEFI = 36
	MIPS_REG_DSPOUTFLAG = 37
	MIPS_REG_DSPOUTFLAG16_19 = 38
	MIPS_REG_DSPOUTFLAG20 = 39
	MIPS_REG_DSPOUTFLAG21 = 40
	MIPS_REG_DSPOUTFLAG22 = 41
	MIPS_REG_DSPOUTFLAG23 = 42
	MIPS_REG_DSPPOS = 43
	MIPS_REG_DSPSCOUNT = 44

// ACC registers
	MIPS_REG_AC0 = 45
	MIPS_REG_AC1 = 46
	MIPS_REG_AC2 = 47
	MIPS_REG_AC3 = 48

// COP registers
	MIPS_REG_CC0 = 49
	MIPS_REG_CC1 = 50
	MIPS_REG_CC2 = 51
	MIPS_REG_CC3 = 52
	MIPS_REG_CC4 = 53
	MIPS_REG_CC5 = 54
	MIPS_REG_CC6 = 55
	MIPS_REG_CC7 = 56

// FPU registers
	MIPS_REG_F0 = 57
	MIPS_REG_F1 = 58
	MIPS_REG_F2 = 59
	MIPS_REG_F3 = 60
	MIPS_REG_F4 = 61
	MIPS_REG_F5 = 62
	MIPS_REG_F6 = 63
	MIPS_REG_F7 = 64
	MIPS_REG_F8 = 65
	MIPS_REG_F9 = 66
	MIPS_REG_F10 = 67
	MIPS_REG_F11 = 68
	MIPS_REG_F12 = 69
	MIPS_REG_F13 = 70
	MIPS_REG_F14 = 71
	MIPS_REG_F15 = 72
	MIPS_REG_F16 = 73
	MIPS_REG_F17 = 74
	MIPS_REG_F18 = 75
	MIPS_REG_F19 = 76
	MIPS_REG_F20 = 77
	MIPS_REG_F21 = 78
	MIPS_REG_F22 = 79
	MIPS_REG_F23 = 80
	MIPS_REG_F24 = 81
	MIPS_REG_F25 = 82
	MIPS_REG_F26 = 83
	MIPS_REG_F27 = 84
	MIPS_REG_F28 = 85
	MIPS_REG_F29 = 86
	MIPS_REG_F30 = 87
	MIPS_REG_F31 = 88
	MIPS_REG_FCC0 = 89
	MIPS_REG_FCC1 = 90
	MIPS_REG_FCC2 = 91
	MIPS_REG_FCC3 = 92
	MIPS_REG_FCC4 = 93
	MIPS_REG_FCC5 = 94
	MIPS_REG_FCC6 = 95
	MIPS_REG_FCC7 = 96

// AFPR128
	MIPS_REG_W0 = 97
	MIPS_REG_W1 = 98
	MIPS_REG_W2 = 99
	MIPS_REG_W3 = 100
	MIPS_REG_W4 = 101
	MIPS_REG_W5 = 102
	MIPS_REG_W6 = 103
	MIPS_REG_W7 = 104
	MIPS_REG_W8 = 105
	MIPS_REG_W9 = 106
	MIPS_REG_W10 = 107
	MIPS_REG_W11 = 108
	MIPS_REG_W12 = 109
	MIPS_REG_W13 = 110
	MIPS_REG_W14 = 111
	MIPS_REG_W15 = 112
	MIPS_REG_W16 = 113
	MIPS_REG_W17 = 114
	MIPS_REG_W18 = 115
	MIPS_REG_W19 = 116
	MIPS_REG_W20 = 117
	MIPS_REG_W21 = 118
	MIPS_REG_W22 = 119
	MIPS_REG_W23 = 120
	MIPS_REG_W24 = 121
	MIPS_REG_W25 = 122
	MIPS_REG_W26 = 123
	MIPS_REG_W27 = 124
	MIPS_REG_W28 = 125
	MIPS_REG_W29 = 126
	MIPS_REG_W30 = 127
	MIPS_REG_W31 = 128
	MIPS_REG_HI = 129
	MIPS_REG_LO = 130
	MIPS_REG_P0 = 131
	MIPS_REG_P1 = 132
	MIPS_REG_P2 = 133
	MIPS_REG_MPL0 = 134
	MIPS_REG_MPL1 = 135
	MIPS_REG_MPL2 = 136
	MIPS_REG_CP0_CONFIG3 = 137
	MIPS_REG_CP0_USERLOCAL = 138
	MIPS_REG_CP0_STATUS = 139
	MIPS_REG_ENDING = 140
	MIPS_REG_ZERO = 2
	MIPS_REG_AT = 3
	MIPS_REG_V0 = 4
	MIPS_REG_V1 = 5
	MIPS_REG_A0 = 6
	MIPS_REG_A1 = 7
	MIPS_REG_A2 = 8
	MIPS_REG_A3 = 9
	MIPS_REG_T0 = 10
	MIPS_REG_T1 = 11
	MIPS_REG_T2 = 12
	MIPS_REG_T3 = 13
	MIPS_REG_T4 = 14
	MIPS_REG_T5 = 15
	MIPS_REG_T6 = 16
	MIPS_REG_T7 = 17
	MIPS_REG_S0 = 18
	MIPS_REG_S1 = 19
	MIPS_REG_S2 = 20
	MIPS_REG_S3 = 21
	MIPS_REG_S4 = 22
	MIPS_REG_S5 = 23
	MIPS_REG_S6 = 24
	MIPS_REG_S7 = 25
	MIPS_REG_T8 = 26
	MIPS_REG_T9 = 27
	MIPS_REG_K0 = 28
	MIPS_REG_K1 = 29
	MIPS_REG_GP = 30
	MIPS_REG_SP = 31
	MIPS_REG_FP = 32
	MIPS_REG_S8 = 32
	MIPS_REG_RA = 33
	MIPS_REG_HI0 = 45
	MIPS_REG_HI1 = 46
	MIPS_REG_HI2 = 47
	MIPS_REG_HI3 = 48
	MIPS_REG_LO0 = 45
	MIPS_REG_LO1 = 46
	MIPS_REG_LO2 = 47
	MIPS_REG_LO3 = 48
)