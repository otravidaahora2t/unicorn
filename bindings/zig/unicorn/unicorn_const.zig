// For Unicorn Engine. AUTO-GENERATED FILE, DO NOT EDIT

pub const unicornConst = enum(c_int) {
	API_MAJOR = 2,

	API_MINOR = 0,
	API_PATCH = 2,
	API_EXTRA = 1,
	VERSION_MAJOR = 2,

	VERSION_MINOR = 0,
	VERSION_PATCH = 2,
	VERSION_EXTRA = 1,
	SECOND_SCALE = 1000000,
	MILISECOND_SCALE = 1000,
	ARCH_ARM = 1,
	ARCH_ARM64 = 2,
	ARCH_MIPS = 3,
	ARCH_X86 = 4,
	ARCH_PPC = 5,
	ARCH_SPARC = 6,
	ARCH_M68K = 7,
	ARCH_RISCV = 8,
	ARCH_S390X = 9,
	ARCH_TRICORE = 10,
	ARCH_MAX = 11,

	MODE_LITTLE_ENDIAN = 0,
	MODE_BIG_ENDIAN = 1073741824,

	MODE_ARM = 0,
	MODE_THUMB = 16,
	MODE_MCLASS = 32,
	MODE_V8 = 64,
	MODE_ARMBE8 = 1024,
	MODE_ARM926 = 128,
	MODE_ARM946 = 256,
	MODE_ARM1176 = 512,
	MODE_MICRO = 16,
	MODE_MIPS3 = 32,
	MODE_MIPS32R6 = 64,
	MODE_MIPS32 = 4,
	MODE_MIPS64 = 8,
	MODE_16 = 2,
	MODE_32 = 4,
	MODE_64 = 8,
	MODE_PPC32 = 4,
	MODE_PPC64 = 8,
	MODE_QPX = 16,
	MODE_SPARC32 = 4,
	MODE_SPARC64 = 8,
	MODE_V9 = 16,
	MODE_RISCV32 = 4,
	MODE_RISCV64 = 8,

	ERR_OK = 0,
	ERR_NOMEM = 1,
	ERR_ARCH = 2,
	ERR_HANDLE = 3,
	ERR_MODE = 4,
	ERR_VERSION = 5,
	ERR_READ_UNMAPPED = 6,
	ERR_WRITE_UNMAPPED = 7,
	ERR_FETCH_UNMAPPED = 8,
	ERR_HOOK = 9,
	ERR_INSN_INVALID = 10,
	ERR_MAP = 11,
	ERR_WRITE_PROT = 12,
	ERR_READ_PROT = 13,
	ERR_FETCH_PROT = 14,
	ERR_ARG = 15,
	ERR_READ_UNALIGNED = 16,
	ERR_WRITE_UNALIGNED = 17,
	ERR_FETCH_UNALIGNED = 18,
	ERR_HOOK_EXIST = 19,
	ERR_RESOURCE = 20,
	ERR_EXCEPTION = 21,
	MEM_READ = 16,
	MEM_WRITE = 17,
	MEM_FETCH = 18,
	MEM_READ_UNMAPPED = 19,
	MEM_WRITE_UNMAPPED = 20,
	MEM_FETCH_UNMAPPED = 21,
	MEM_WRITE_PROT = 22,
	MEM_READ_PROT = 23,
	MEM_FETCH_PROT = 24,
	MEM_READ_AFTER = 25,

	TCG_OP_SUB = 0,
	TCG_OP_FLAG_CMP = 1,
	TCG_OP_FLAG_DIRECT = 2,
	HOOK_INTR = 1,
	HOOK_INSN = 2,
	HOOK_CODE = 4,
	HOOK_BLOCK = 8,
	HOOK_MEM_READ_UNMAPPED = 16,
	HOOK_MEM_WRITE_UNMAPPED = 32,
	HOOK_MEM_FETCH_UNMAPPED = 64,
	HOOK_MEM_READ_PROT = 128,
	HOOK_MEM_WRITE_PROT = 256,
	HOOK_MEM_FETCH_PROT = 512,
	HOOK_MEM_READ = 1024,
	HOOK_MEM_WRITE = 2048,
	HOOK_MEM_FETCH = 4096,
	HOOK_MEM_READ_AFTER = 8192,
	HOOK_INSN_INVALID = 16384,
	HOOK_EDGE_GENERATED = 32768,
	HOOK_TCG_OPCODE = 65536,
	HOOK_TLB_FILL = 131072,
	HOOK_MEM_UNMAPPED = 112,
	HOOK_MEM_PROT = 896,
	HOOK_MEM_READ_INVALID = 144,
	HOOK_MEM_WRITE_INVALID = 288,
	HOOK_MEM_FETCH_INVALID = 576,
	HOOK_MEM_INVALID = 1008,
	HOOK_MEM_VALID = 7168,
	QUERY_MODE = 1,
	QUERY_PAGE_SIZE = 2,
	QUERY_ARCH = 3,
	QUERY_TIMEOUT = 4,

	CTL_IO_NONE = 0,
	CTL_IO_WRITE = 1,
	CTL_IO_READ = 2,
	CTL_IO_READ_WRITE = 3,

	TLB_CPU = 0,
	TLB_VIRTUAL = 1,

	CTL_UC_MODE = 0,
	CTL_UC_PAGE_SIZE = 1,
	CTL_UC_ARCH = 2,
	CTL_UC_TIMEOUT = 3,
	CTL_UC_USE_EXITS = 4,
	CTL_UC_EXITS_CNT = 5,
	CTL_UC_EXITS = 6,
	CTL_CPU_MODEL = 7,
	CTL_TB_REQUEST_CACHE = 8,
	CTL_TB_REMOVE_CACHE = 9,
	CTL_TB_FLUSH = 10,
	CTL_TLB_FLUSH = 11,
	CTL_TLB_TYPE = 12,

	PROT_NONE = 0,
	PROT_READ = 1,
	PROT_WRITE = 2,
	PROT_EXEC = 4,
	PROT_ALL = 7,

};
