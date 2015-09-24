// For Unicorn Engine. AUTO-GENERATED FILE, DO NOT EDIT

package unicorn;

public interface UnicornConst {

   public static final int UC_API_MAJOR = 0;
   public static final int UC_API_MINOR = 9;
   public static final int UC_SECOND_SCALE = 1000000;
   public static final int UC_MILISECOND_SCALE = 1000;
   public static final int UC_ARCH_ARM = 1;
   public static final int UC_ARCH_ARM64 = 2;
   public static final int UC_ARCH_MIPS = 3;
   public static final int UC_ARCH_X86 = 4;
   public static final int UC_ARCH_PPC = 5;
   public static final int UC_ARCH_SPARC = 6;
   public static final int UC_ARCH_M68K = 7;
   public static final int UC_ARCH_MAX = 8;

   public static final int UC_MODE_LITTLE_ENDIAN = 0;

   public static final int UC_MODE_ARM = 0;
   public static final int UC_MODE_16 = 2;
   public static final int UC_MODE_32 = 4;
   public static final int UC_MODE_64 = 8;
   public static final int UC_MODE_THUMB = 16;
   public static final int UC_MODE_MCLASS = 32;
   public static final int UC_MODE_V8 = 64;
   public static final int UC_MODE_MICRO = 16;
   public static final int UC_MODE_MIPS3 = 32;
   public static final int UC_MODE_MIPS32R6 = 64;
   public static final int UC_MODE_V9 = 16;
   public static final int UC_MODE_QPX = 16;
   public static final int UC_MODE_BIG_ENDIAN = 1073741824;
   public static final int UC_MODE_MIPS32 = 4;
   public static final int UC_MODE_MIPS64 = 8;

   public static final int UC_ERR_OK = 0;
   public static final int UC_ERR_NOMEM = 1;
   public static final int UC_ERR_ARCH = 2;
   public static final int UC_ERR_HANDLE = 3;
   public static final int UC_ERR_MODE = 4;
   public static final int UC_ERR_VERSION = 5;
   public static final int UC_ERR_READ_INVALID = 6;
   public static final int UC_ERR_WRITE_INVALID = 7;
   public static final int UC_ERR_FETCH_INVALID = 8;
   public static final int UC_ERR_CODE_INVALID = 9;
   public static final int UC_ERR_HOOK = 10;
   public static final int UC_ERR_INSN_INVALID = 11;
   public static final int UC_ERR_MAP = 12;
   public static final int UC_ERR_WRITE_PROT = 13;
   public static final int UC_ERR_READ_PROT = 14;
   public static final int UC_ERR_FETCH_PROT = 15;
   public static final int UC_ERR_ARG = 16;
   public static final int UC_ERR_READ_UNALIGNED = 17;
   public static final int UC_ERR_WRITE_UNALIGNED = 18;
   public static final int UC_ERR_FETCH_UNALIGNED = 19;
   public static final int UC_MEM_READ = 16;
   public static final int UC_MEM_WRITE = 17;
   public static final int UC_MEM_FETCH = 18;
   public static final int UC_MEM_READ_INVALID = 19;
   public static final int UC_MEM_WRITE_INVALID = 20;
   public static final int UC_MEM_FETCH_INVALID = 21;
   public static final int UC_MEM_WRITE_PROT = 22;
   public static final int UC_MEM_READ_PROT = 23;
   public static final int UC_MEM_FETCH_PROT = 24;
   public static final int UC_HOOK_INTR = 1;
   public static final int UC_HOOK_INSN = 2;
   public static final int UC_HOOK_CODE = 4;
   public static final int UC_HOOK_BLOCK = 8;
   public static final int UC_HOOK_MEM_READ_INVALID = 16;
   public static final int UC_HOOK_MEM_WRITE_INVALID = 32;
   public static final int UC_HOOK_MEM_FETCH_INVALID = 64;
   public static final int UC_HOOK_MEM_READ_PROT = 128;
   public static final int UC_HOOK_MEM_WRITE_PROT = 256;
   public static final int UC_HOOK_MEM_FETCH_PROT = 512;
   public static final int UC_HOOK_MEM_READ = 1024;
   public static final int UC_HOOK_MEM_WRITE = 2048;
   public static final int UC_HOOK_MEM_FETCH = 4096;

   public static final int UC_PROT_NONE = 0;
   public static final int UC_PROT_READ = 1;
   public static final int UC_PROT_WRITE = 2;
   public static final int UC_PROT_EXEC = 4;
   public static final int UC_PROT_ALL = 7;

}
