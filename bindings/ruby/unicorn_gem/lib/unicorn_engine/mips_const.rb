# For Unicorn Engine. AUTO-GENERATED FILE, DO NOT EDIT [mips_const.rb]

module UnicornEngine

	UC_CPU_MIPS32_4KC = 0
	UC_CPU_MIPS32_4KM = 1
	UC_CPU_MIPS32_4KECR1 = 2
	UC_CPU_MIPS32_4KEMR1 = 3
	UC_CPU_MIPS32_4KEC = 4
	UC_CPU_MIPS32_4KEM = 5
	UC_CPU_MIPS32_24KC = 6
	UC_CPU_MIPS32_24KEC = 7
	UC_CPU_MIPS32_24KF = 8
	UC_CPU_MIPS32_34KF = 9
	UC_CPU_MIPS32_74KF = 10
	UC_CPU_MIPS32_M14K = 11
	UC_CPU_MIPS32_M14KC = 12
	UC_CPU_MIPS32_P5600 = 13
	UC_CPU_MIPS32_MIPS32R6_GENERIC = 14
	UC_CPU_MIPS32_I7200 = 15

	UC_CPU_MIPS64_R4000 = 0
	UC_CPU_MIPS64_VR5432 = 1
	UC_CPU_MIPS64_5KC = 2
	UC_CPU_MIPS64_5KF = 3
	UC_CPU_MIPS64_20KC = 4
	UC_CPU_MIPS64_MIPS64R2_GENERIC = 5
	UC_CPU_MIPS64_5KEC = 6
	UC_CPU_MIPS64_5KEF = 7
	UC_CPU_MIPS64_I6400 = 8
	UC_CPU_MIPS64_I6500 = 9
	UC_CPU_MIPS64_LOONGSON_2E = 10
	UC_CPU_MIPS64_LOONGSON_2F = 11
	UC_CPU_MIPS64_MIPS64DSPR2 = 12

# MIPS registers

	UC_MIPS_REG_INVALID = 0

# General purpose registers
	UC_MIPS_REG_PC = 1
	UC_MIPS_REG_0 = 2
	UC_MIPS_REG_1 = 3
	UC_MIPS_REG_2 = 4
	UC_MIPS_REG_3 = 5
	UC_MIPS_REG_4 = 6
	UC_MIPS_REG_5 = 7
	UC_MIPS_REG_6 = 8
	UC_MIPS_REG_7 = 9
	UC_MIPS_REG_8 = 10
	UC_MIPS_REG_9 = 11
	UC_MIPS_REG_10 = 12
	UC_MIPS_REG_11 = 13
	UC_MIPS_REG_12 = 14
	UC_MIPS_REG_13 = 15
	UC_MIPS_REG_14 = 16
	UC_MIPS_REG_15 = 17
	UC_MIPS_REG_16 = 18
	UC_MIPS_REG_17 = 19
	UC_MIPS_REG_18 = 20
	UC_MIPS_REG_19 = 21
	UC_MIPS_REG_20 = 22
	UC_MIPS_REG_21 = 23
	UC_MIPS_REG_22 = 24
	UC_MIPS_REG_23 = 25
	UC_MIPS_REG_24 = 26
	UC_MIPS_REG_25 = 27
	UC_MIPS_REG_26 = 28
	UC_MIPS_REG_27 = 29
	UC_MIPS_REG_28 = 30
	UC_MIPS_REG_29 = 31
	UC_MIPS_REG_30 = 32
	UC_MIPS_REG_31 = 33

# DSP registers
	UC_MIPS_REG_DSPCCOND = 34
	UC_MIPS_REG_DSPCARRY = 35
	UC_MIPS_REG_DSPEFI = 36
	UC_MIPS_REG_DSPOUTFLAG = 37
	UC_MIPS_REG_DSPOUTFLAG16_19 = 38
	UC_MIPS_REG_DSPOUTFLAG20 = 39
	UC_MIPS_REG_DSPOUTFLAG21 = 40
	UC_MIPS_REG_DSPOUTFLAG22 = 41
	UC_MIPS_REG_DSPOUTFLAG23 = 42
	UC_MIPS_REG_DSPPOS = 43
	UC_MIPS_REG_DSPSCOUNT = 44

# ACC registers
	UC_MIPS_REG_AC0 = 45
	UC_MIPS_REG_AC1 = 46
	UC_MIPS_REG_AC2 = 47
	UC_MIPS_REG_AC3 = 48

# COP registers
	UC_MIPS_REG_CC0 = 49
	UC_MIPS_REG_CC1 = 50
	UC_MIPS_REG_CC2 = 51
	UC_MIPS_REG_CC3 = 52
	UC_MIPS_REG_CC4 = 53
	UC_MIPS_REG_CC5 = 54
	UC_MIPS_REG_CC6 = 55
	UC_MIPS_REG_CC7 = 56

# FPU registers
	UC_MIPS_REG_F0 = 57
	UC_MIPS_REG_F1 = 58
	UC_MIPS_REG_F2 = 59
	UC_MIPS_REG_F3 = 60
	UC_MIPS_REG_F4 = 61
	UC_MIPS_REG_F5 = 62
	UC_MIPS_REG_F6 = 63
	UC_MIPS_REG_F7 = 64
	UC_MIPS_REG_F8 = 65
	UC_MIPS_REG_F9 = 66
	UC_MIPS_REG_F10 = 67
	UC_MIPS_REG_F11 = 68
	UC_MIPS_REG_F12 = 69
	UC_MIPS_REG_F13 = 70
	UC_MIPS_REG_F14 = 71
	UC_MIPS_REG_F15 = 72
	UC_MIPS_REG_F16 = 73
	UC_MIPS_REG_F17 = 74
	UC_MIPS_REG_F18 = 75
	UC_MIPS_REG_F19 = 76
	UC_MIPS_REG_F20 = 77
	UC_MIPS_REG_F21 = 78
	UC_MIPS_REG_F22 = 79
	UC_MIPS_REG_F23 = 80
	UC_MIPS_REG_F24 = 81
	UC_MIPS_REG_F25 = 82
	UC_MIPS_REG_F26 = 83
	UC_MIPS_REG_F27 = 84
	UC_MIPS_REG_F28 = 85
	UC_MIPS_REG_F29 = 86
	UC_MIPS_REG_F30 = 87
	UC_MIPS_REG_F31 = 88
	UC_MIPS_REG_FCC0 = 89
	UC_MIPS_REG_FCC1 = 90
	UC_MIPS_REG_FCC2 = 91
	UC_MIPS_REG_FCC3 = 92
	UC_MIPS_REG_FCC4 = 93
	UC_MIPS_REG_FCC5 = 94
	UC_MIPS_REG_FCC6 = 95
	UC_MIPS_REG_FCC7 = 96

# AFPR128
	UC_MIPS_REG_W0 = 97
	UC_MIPS_REG_W1 = 98
	UC_MIPS_REG_W2 = 99
	UC_MIPS_REG_W3 = 100
	UC_MIPS_REG_W4 = 101
	UC_MIPS_REG_W5 = 102
	UC_MIPS_REG_W6 = 103
	UC_MIPS_REG_W7 = 104
	UC_MIPS_REG_W8 = 105
	UC_MIPS_REG_W9 = 106
	UC_MIPS_REG_W10 = 107
	UC_MIPS_REG_W11 = 108
	UC_MIPS_REG_W12 = 109
	UC_MIPS_REG_W13 = 110
	UC_MIPS_REG_W14 = 111
	UC_MIPS_REG_W15 = 112
	UC_MIPS_REG_W16 = 113
	UC_MIPS_REG_W17 = 114
	UC_MIPS_REG_W18 = 115
	UC_MIPS_REG_W19 = 116
	UC_MIPS_REG_W20 = 117
	UC_MIPS_REG_W21 = 118
	UC_MIPS_REG_W22 = 119
	UC_MIPS_REG_W23 = 120
	UC_MIPS_REG_W24 = 121
	UC_MIPS_REG_W25 = 122
	UC_MIPS_REG_W26 = 123
	UC_MIPS_REG_W27 = 124
	UC_MIPS_REG_W28 = 125
	UC_MIPS_REG_W29 = 126
	UC_MIPS_REG_W30 = 127
	UC_MIPS_REG_W31 = 128
	UC_MIPS_REG_HI = 129
	UC_MIPS_REG_LO = 130
	UC_MIPS_REG_P0 = 131
	UC_MIPS_REG_P1 = 132
	UC_MIPS_REG_P2 = 133
	UC_MIPS_REG_MPL0 = 134
	UC_MIPS_REG_MPL1 = 135
	UC_MIPS_REG_MPL2 = 136
	UC_MIPS_REG_CP0_CONFIG3 = 137
	UC_MIPS_REG_CP0_USERLOCAL = 138
	UC_MIPS_REG_CP0_STATUS = 139
	UC_MIPS_REG_ENDING = 140
	UC_MIPS_REG_ZERO = 2
	UC_MIPS_REG_AT = 3
	UC_MIPS_REG_V0 = 4
	UC_MIPS_REG_V1 = 5
	UC_MIPS_REG_A0 = 6
	UC_MIPS_REG_A1 = 7
	UC_MIPS_REG_A2 = 8
	UC_MIPS_REG_A3 = 9
	UC_MIPS_REG_T0 = 10
	UC_MIPS_REG_T1 = 11
	UC_MIPS_REG_T2 = 12
	UC_MIPS_REG_T3 = 13
	UC_MIPS_REG_T4 = 14
	UC_MIPS_REG_T5 = 15
	UC_MIPS_REG_T6 = 16
	UC_MIPS_REG_T7 = 17
	UC_MIPS_REG_S0 = 18
	UC_MIPS_REG_S1 = 19
	UC_MIPS_REG_S2 = 20
	UC_MIPS_REG_S3 = 21
	UC_MIPS_REG_S4 = 22
	UC_MIPS_REG_S5 = 23
	UC_MIPS_REG_S6 = 24
	UC_MIPS_REG_S7 = 25
	UC_MIPS_REG_T8 = 26
	UC_MIPS_REG_T9 = 27
	UC_MIPS_REG_K0 = 28
	UC_MIPS_REG_K1 = 29
	UC_MIPS_REG_GP = 30
	UC_MIPS_REG_SP = 31
	UC_MIPS_REG_FP = 32
	UC_MIPS_REG_S8 = 32
	UC_MIPS_REG_RA = 33
	UC_MIPS_REG_HI0 = 45
	UC_MIPS_REG_HI1 = 46
	UC_MIPS_REG_HI2 = 47
	UC_MIPS_REG_HI3 = 48
	UC_MIPS_REG_LO0 = 45
	UC_MIPS_REG_LO1 = 46
	UC_MIPS_REG_LO2 = 47
	UC_MIPS_REG_LO3 = 48
end