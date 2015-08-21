/* Unicorn Emulator Engine */
/* By Nguyen Anh Quynh & Dang Hoang Vu, 2015 */

/* Sample code to demonstrate how to emulate X86 code */

#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#include <unicorn/unicorn.h>


// code to be emulated
#define X86_CODE32 "\x41\x4a" // INC ecx; DEC dex
#define X86_CODE32_JUMP "\xeb\x02\x90\x90\x90\x90\x90\x90" // jmp 4; nop; nop; nop; nop; nop; nop
// #define X86_CODE32_SELF "\xeb\x1c\x5a\x89\xd6\x8b\x02\x66\x3d\xca\x7d\x75\x06\x66\x05\x03\x03\x89\x02\xfe\xc2\x3d\x41\x41\x41\x41\x75\xe9\xff\xe6\xe8\xdf\xff\xff\xff\x31\xd2\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x52\x53\x89\xe1\xca\x7d\x41\x41\x41\x41" 
//#define X86_CODE32 "\x51\x51\x51\x51" // PUSH ecx;
#define X86_CODE32_LOOP "\x41\x4a\xeb\xfe" // INC ecx; DEC dex; JMP self-loop
#define X86_CODE32_MEM_WRITE "\x89\x0D\xAA\xAA\xAA\xAA\x41\x4a" // mov [0xaaaaaaaa], ecx; INC ecx; dec edx
#define X86_CODE32_MEM_READ "\x8B\x0D\xAA\xAA\xAA\xAA\x41\x4a" // mov ecx,[0xaaaaaaaa]; INC ecx; DEC dex

#define X86_CODE32_JMP_INVALID "\xe9\xe9\xee\xee\xee\x41\x4a" //  JMP outside; INC ecx; DEC dex
#define X86_CODE32_INOUT "\x41\xE4\x3F\x4a\xE6\x46\x43" // INC ecx; IN AL, 0x3f; DEC edx; OUT 0x46, AL; INC ebx

//#define X86_CODE64 "\x41\xBC\x3B\xB0\x28\x2A \x49\x0F\xC9 \x90 \x4D\x0F\xAD\xCF\x49\x87\xFD\x90\x48\x81\xD2\x8A\xCE\x77\x35\x48\xF7\xD9" // <== still crash
//#define X86_CODE64 "\x41\xBC\x3B\xB0\x28\x2A\x49\x0F\xC9\x90\x4D\x0F\xAD\xCF\x49\x87\xFD\x90\x48\x81\xD2\x8A\xCE\x77\x35\x48\xF7\xD9" 
#define X86_CODE64 "\x41\xBC\x3B\xB0\x28\x2A\x49\x0F\xC9\x90\x4D\x0F\xAD\xCF\x49\x87\xFD\x90\x48\x81\xD2\x8A\xCE\x77\x35\x48\xF7\xD9\x4D\x29\xF4\x49\x81\xC9\xF6\x8A\xC6\x53\x4D\x87\xED\x48\x0F\xAD\xD2\x49\xF7\xD4\x48\xF7\xE1\x4D\x19\xC5\x4D\x89\xC5\x48\xF7\xD6\x41\xB8\x4F\x8D\x6B\x59\x4D\x87\xD0\x68\x6A\x1E\x09\x3C\x59" //\xc3"

// memory address where emulation starts
#define ADDRESS 0x1000000

// callback for tracing basic blocks
static void hook_block(uch handle, uint64_t address, uint32_t size, void *user_data)
{
    printf(">>> Tracing basic block at 0x%"PRIx64 ", block size = 0x%x\n", address, size);
}

// callback for tracing instruction
static void hook_code(uch handle, uint64_t address, uint32_t size, void *user_data)
{
    int eflags;
    printf(">>> Tracing instruction at 0x%"PRIx64 ", instruction size = 0x%x\n", address, size);

    uc_reg_read(handle, X86_REG_EFLAGS, &eflags);
    printf(">>> --- EFLAGS is 0x%x\n", eflags);

    // Uncomment below code to stop the emulation using uc_emu_stop()
    // if (address == 0x1000009)
    //    uc_emu_stop(handle);
}

// callback for tracing instruction
static void hook_code64(uch handle, uint64_t address, uint32_t size, void *user_data)
{
    uint64_t rip;

    uc_reg_read(handle, X86_REG_RIP, &rip);
    printf(">>> Tracing instruction at 0x%"PRIx64 ", instruction size = 0x%x\n", address, size);
    printf(">>> RIP is 0x%"PRIx64 "\n", rip);

    // Uncomment below code to stop the emulation using uc_emu_stop()
    // if (address == 0x1000009)
    //    uc_emu_stop(handle);
}

// callback for tracing memory access (READ or WRITE)
static bool hook_mem_invalid(uch handle, uc_mem_type type,
        uint64_t address, int size, int64_t value, void *user_data)
{
    switch(type) {
        default:
            // return false to indicate we want to stop emulation
            return false;
        case UC_MEM_WRITE:
                 printf(">>> Missing memory is being WRITE at 0x%"PRIx64 ", data size = %u, data value = 0x%"PRIx64 "\n",
                         address, size, value);
                 // map this memory in with 2MB in size
                 uc_mem_map(handle, 0xaaaa0000, 2 * 1024*1024);
                 // return true to indicate we want to continue
                 return true;
    }
}

static void hook_mem64(uch handle, uc_mem_type type,
        uint64_t address, int size, int64_t value, void *user_data)
{
    switch(type) {
        default: break;
        case UC_MEM_READ:
                 printf(">>> Memory is being READ at 0x%"PRIx64 ", data size = %u\n",
                         address, size);
                 break;
        case UC_MEM_WRITE:
                 printf(">>> Memory is being WRITE at 0x%"PRIx64 ", data size = %u, data value = 0x%"PRIx64 "\n",
                         address, size, value);
                 break;
    }
}

// callback for IN instruction (X86).
// this returns the data read from the port
static uint32_t hook_in(uch handle, uint32_t port, int size, void *user_data)
{
    uint32_t eip;

    uc_reg_read(handle, X86_REG_EIP, &eip);

    printf("--- reading from port 0x%x, size: %u, address: 0x%x\n", port, size, eip);

    switch(size) {
        default:
            return 0;   // should never reach this
        case 1:
            // read 1 byte to AL
            return 0xf1;
        case 2:
            // read 2 byte to AX
            return 0xf2;
            break;
        case 4:
            // read 4 byte to EAX
            return 0xf4;
    }
}

// callback for OUT instruction (X86).
static void hook_out(uch handle, uint32_t port, int size, uint32_t value, void *user_data)
{
    uint32_t tmp;
    uint32_t eip;

    uc_reg_read(handle, X86_REG_EIP, &eip);

    printf("--- writing to port 0x%x, size: %u, value: 0x%x, address: 0x%x\n", port, size, value, eip);

    // confirm that value is indeed the value of AL/AX/EAX
    switch(size) {
        default:
            return;   // should never reach this
        case 1:
            uc_reg_read(handle, X86_REG_AL, &tmp);
            break;
        case 2:
            uc_reg_read(handle, X86_REG_AX, &tmp);
            break;
        case 4:
            uc_reg_read(handle, X86_REG_EAX, &tmp);
            break;
    }

    printf("--- register value = 0x%x\n", tmp);
}

static void test_i386(void)
{
    uch handle;
    uc_err err;
    uint32_t tmp;
    uch trace1, trace2;

    int r_ecx = 0x1234;     // ECX register
    int r_edx = 0x7890;     // EDX register

    printf("Emulate i386 code\n");

    // Initialize emulator in X86-32bit mode
    err = uc_open(UC_ARCH_X86, UC_MODE_32, &handle);
    if (err) {
        printf("Failed on uc_open() with error returned: %u\n", err);
        return;
    }

    // map 2MB memory for this emulation
    uc_mem_map(handle, ADDRESS, 2 * 1024 * 1024);

    // write machine code to be emulated to memory
    if (uc_mem_write(handle, ADDRESS, (uint8_t *)X86_CODE32, sizeof(X86_CODE32) - 1)) {
        printf("Failed to write emulation code to memory, quit!\n");
        return;
    }

    // initialize machine registers
    uc_reg_write(handle, X86_REG_ECX, &r_ecx);
    uc_reg_write(handle, X86_REG_EDX, &r_edx);

    // tracing all basic blocks with customized callback
    uc_hook_add(handle, &trace1, UC_HOOK_BLOCK, hook_block, NULL, (uint64_t)1, (uint64_t)0);

    // tracing all instruction by having @begin > @end
    uc_hook_add(handle, &trace2, UC_HOOK_CODE, hook_code, NULL, (uint64_t)1, (uint64_t)0);

    // emulate machine code in infinite time
    err = uc_emu_start(handle, ADDRESS, ADDRESS + sizeof(X86_CODE32) - 1, 0, 0);
    if (err) {
        printf("Failed on uc_emu_start() with error returned %u: %s\n",
                err, uc_strerror(err));
    }

    // now print out some registers
    printf(">>> Emulation done. Below is the CPU context\n");

    uc_reg_read(handle, X86_REG_ECX, &r_ecx);
    uc_reg_read(handle, X86_REG_EDX, &r_edx);
    printf(">>> ECX = 0x%x\n", r_ecx);
    printf(">>> EDX = 0x%x\n", r_edx);

    // read from memory
    if (!uc_mem_read(handle, ADDRESS, (uint8_t *)&tmp, 4))
        printf(">>> Read 4 bytes from [0x%x] = 0x%x\n", ADDRESS, tmp);
    else
        printf(">>> Failed to read 4 bytes from [0x%x]\n", ADDRESS);

    uc_close(&handle);
}

static void test_i386_jump(void)
{
    uch handle;
    uc_err err;
    uch trace1, trace2;

    printf("===================================\n");
    printf("Emulate i386 code with jump\n");

    // Initialize emulator in X86-32bit mode
    err = uc_open(UC_ARCH_X86, UC_MODE_32, &handle);
    if (err) {
        printf("Failed on uc_open() with error returned: %u\n", err);
        return;
    }

    // map 2MB memory for this emulation
    uc_mem_map(handle, ADDRESS, 2 * 1024 * 1024);

    // write machine code to be emulated to memory
    if (uc_mem_write(handle, ADDRESS, (uint8_t *)X86_CODE32_JUMP,
          sizeof(X86_CODE32_JUMP) - 1)) {
        printf("Failed to write emulation code to memory, quit!\n");
        return;
    }

    // tracing 1 basic block with customized callback
    uc_hook_add(handle, &trace1, UC_HOOK_BLOCK, hook_block, NULL, (uint64_t)ADDRESS, (uint64_t)ADDRESS);

    // tracing 1 instruction at ADDRESS
    uc_hook_add(handle, &trace2, UC_HOOK_CODE, hook_code, NULL, (uint64_t)ADDRESS, (uint64_t)ADDRESS);

    // emulate machine code in infinite time
    err = uc_emu_start(handle, ADDRESS, ADDRESS + sizeof(X86_CODE32_JUMP) - 1, 0, 0);
    if (err) {
        printf("Failed on uc_emu_start() with error returned %u: %s\n",
                err, uc_strerror(err));
    }

    printf(">>> Emulation done. Below is the CPU context\n");

    uc_close(&handle);
}

// emulate code that loop forever
static void test_i386_loop(void)
{
    uch handle;
    uc_err err;

    int r_ecx = 0x1234;     // ECX register
    int r_edx = 0x7890;     // EDX register

    printf("===================================\n");
    printf("Emulate i386 code that loop forever\n");

    // Initialize emulator in X86-32bit mode
    err = uc_open(UC_ARCH_X86, UC_MODE_32, &handle);
    if (err) {
        printf("Failed on uc_open() with error returned: %u\n", err);
        return;
    }

    // map 2MB memory for this emulation
    uc_mem_map(handle, ADDRESS, 2 * 1024 * 1024);

    // write machine code to be emulated to memory
    if (uc_mem_write(handle, ADDRESS, (uint8_t *)X86_CODE32_LOOP, sizeof(X86_CODE32_LOOP) - 1)) {
        printf("Failed to write emulation code to memory, quit!\n");
        return;
    }

    // initialize machine registers
    uc_reg_write(handle, X86_REG_ECX, &r_ecx);
    uc_reg_write(handle, X86_REG_EDX, &r_edx);

    // emulate machine code in 2 seconds, so we can quit even
    // if the code loops
    err = uc_emu_start(handle, ADDRESS, ADDRESS + sizeof(X86_CODE32_LOOP) - 1, 2 * UC_SECOND_SCALE, 0);
    if (err) {
        printf("Failed on uc_emu_start() with error returned %u: %s\n",
                err, uc_strerror(err));
    }

    // now print out some registers
    printf(">>> Emulation done. Below is the CPU context\n");

    uc_reg_read(handle, X86_REG_ECX, &r_ecx);
    uc_reg_read(handle, X86_REG_EDX, &r_edx);
    printf(">>> ECX = 0x%x\n", r_ecx);
    printf(">>> EDX = 0x%x\n", r_edx);

    uc_close(&handle);
}

// emulate code that read invalid memory
static void test_i386_invalid_mem_read(void)
{
    uch handle;
    uc_err err;
    uch trace1, trace2;

    int r_ecx = 0x1234;     // ECX register
    int r_edx = 0x7890;     // EDX register

    printf("===================================\n");
    printf("Emulate i386 code that read from invalid memory\n");

    // Initialize emulator in X86-32bit mode
    err = uc_open(UC_ARCH_X86, UC_MODE_32, &handle);
    if (err) {
        printf("Failed on uc_open() with error returned: %u\n", err);
        return;
    }

    // map 2MB memory for this emulation
    uc_mem_map(handle, ADDRESS, 2 * 1024 * 1024);

    // write machine code to be emulated to memory
    if (uc_mem_write(handle, ADDRESS, (uint8_t *)X86_CODE32_MEM_READ, sizeof(X86_CODE32_MEM_READ) - 1)) {
        printf("Failed to write emulation code to memory, quit!\n");
        return;
    }

    // initialize machine registers
    uc_reg_write(handle, X86_REG_ECX, &r_ecx);
    uc_reg_write(handle, X86_REG_EDX, &r_edx);

    // tracing all basic blocks with customized callback
    uc_hook_add(handle, &trace1, UC_HOOK_BLOCK, hook_block, NULL, (uint64_t)1, (uint64_t)0);

    // tracing all instruction by having @begin > @end
    uc_hook_add(handle, &trace2, UC_HOOK_CODE, hook_code, NULL, (uint64_t)1, (uint64_t)0);

    // emulate machine code in infinite time
    err = uc_emu_start(handle, ADDRESS, ADDRESS + sizeof(X86_CODE32_MEM_READ) - 1, 0, 0);
    if (err) {
        printf("Failed on uc_emu_start() with error returned %u: %s\n",
                err, uc_strerror(err));
    }

    // now print out some registers
    printf(">>> Emulation done. Below is the CPU context\n");

    uc_reg_read(handle, X86_REG_ECX, &r_ecx);
    uc_reg_read(handle, X86_REG_EDX, &r_edx);
    printf(">>> ECX = 0x%x\n", r_ecx);
    printf(">>> EDX = 0x%x\n", r_edx);

    uc_close(&handle);
}

// emulate code that read invalid memory
static void test_i386_invalid_mem_write(void)
{
    uch handle, evh;
    uc_err err;
    uch trace1, trace2; //, trace3;
    uint32_t tmp;

    int r_ecx = 0x1234;     // ECX register
    int r_edx = 0x7890;     // EDX register

    printf("===================================\n");
    printf("Emulate i386 code that write to invalid memory\n");

    // Initialize emulator in X86-32bit mode
    err = uc_open(UC_ARCH_X86, UC_MODE_32, &handle);
    if (err) {
        printf("Failed on uc_open() with error returned: %u\n", err);
        return;
    }

    // map 2MB memory for this emulation
    uc_mem_map(handle, ADDRESS, 2 * 1024 * 1024);

    // write machine code to be emulated to memory
    if (uc_mem_write(handle, ADDRESS, (uint8_t *)X86_CODE32_MEM_WRITE, sizeof(X86_CODE32_MEM_WRITE) - 1)) {
        printf("Failed to write emulation code to memory, quit!\n");
        return;
    }

    // initialize machine registers
    uc_reg_write(handle, X86_REG_ECX, &r_ecx);
    uc_reg_write(handle, X86_REG_EDX, &r_edx);

    // tracing all basic blocks with customized callback
    uc_hook_add(handle, &trace1, UC_HOOK_BLOCK, hook_block, NULL, (uint64_t)1, (uint64_t)0);

    // tracing all instruction by having @begin > @end
    uc_hook_add(handle, &trace2, UC_HOOK_CODE, hook_code, NULL, (uint64_t)1, (uint64_t)0);

    // intercept invalid memory events
    uc_hook_add(handle, &evh, UC_HOOK_MEM_INVALID, hook_mem_invalid, NULL);

    // emulate machine code in infinite time
    err = uc_emu_start(handle, ADDRESS, ADDRESS + sizeof(X86_CODE32_MEM_WRITE) - 1, 0, 0);
    if (err) {
        printf("Failed on uc_emu_start() with error returned %u: %s\n",
                err, uc_strerror(err));
    }

    // now print out some registers
    printf(">>> Emulation done. Below is the CPU context\n");

    uc_reg_read(handle, X86_REG_ECX, &r_ecx);
    uc_reg_read(handle, X86_REG_EDX, &r_edx);
    printf(">>> ECX = 0x%x\n", r_ecx);
    printf(">>> EDX = 0x%x\n", r_edx);

    // read from memory
    if (!uc_mem_read(handle, 0xaaaaaaaa, (uint8_t *)&tmp, 4))
        printf(">>> Read 4 bytes from [0x%x] = 0x%x\n", 0xaaaaaaaa, tmp);
    else
        printf(">>> Failed to read 4 bytes from [0x%x]\n", 0xffffffaa);

    if (!uc_mem_read(handle, 0xffffffaa, (uint8_t *)&tmp, 4))
        printf(">>> Read 4 bytes from [0x%x] = 0x%x\n", 0xffffffaa, tmp);
    else
        printf(">>> Failed to read 4 bytes from [0x%x]\n", 0xffffffaa);

    uc_close(&handle);
}

// emulate code that jump to invalid memory
static void test_i386_jump_invalid(void)
{
    uch handle;
    uc_err err;
    uch trace1, trace2;

    int r_ecx = 0x1234;     // ECX register
    int r_edx = 0x7890;     // EDX register

    printf("===================================\n");
    printf("Emulate i386 code that jumps to invalid memory\n");

    // Initialize emulator in X86-32bit mode
    err = uc_open(UC_ARCH_X86, UC_MODE_32, &handle);
    if (err) {
        printf("Failed on uc_open() with error returned: %u\n", err);
        return;
    }

    // map 2MB memory for this emulation
    uc_mem_map(handle, ADDRESS, 2 * 1024 * 1024);

    // write machine code to be emulated to memory
    if (uc_mem_write(handle, ADDRESS, (uint8_t *)X86_CODE32_JMP_INVALID, sizeof(X86_CODE32_JMP_INVALID) - 1)) {
        printf("Failed to write emulation code to memory, quit!\n");
        return;
    }

    // initialize machine registers
    uc_reg_write(handle, X86_REG_ECX, &r_ecx);
    uc_reg_write(handle, X86_REG_EDX, &r_edx);

    // tracing all basic blocks with customized callback
    uc_hook_add(handle, &trace1, UC_HOOK_BLOCK, hook_block, NULL, (uint64_t)1, (uint64_t)0);

    // tracing all instructions by having @begin > @end
    uc_hook_add(handle, &trace2, UC_HOOK_CODE, hook_code, NULL, (uint64_t)1, (uint64_t)0);

    // emulate machine code in infinite time
    err = uc_emu_start(handle, ADDRESS, ADDRESS + sizeof(X86_CODE32_JMP_INVALID) - 1, 0, 0);
    if (err) {
        printf("Failed on uc_emu_start() with error returned %u: %s\n",
                err, uc_strerror(err));
    }

    // now print out some registers
    printf(">>> Emulation done. Below is the CPU context\n");

    uc_reg_read(handle, X86_REG_ECX, &r_ecx);
    uc_reg_read(handle, X86_REG_EDX, &r_edx);
    printf(">>> ECX = 0x%x\n", r_ecx);
    printf(">>> EDX = 0x%x\n", r_edx);

    uc_close(&handle);
}

static void test_i386_inout(void)
{
    uch handle;
    uc_err err;
    uch trace1, trace2;
    uch trace3, trace4;

    int r_eax = 0x1234;     // EAX register
    int r_ecx = 0x6789;     // ECX register

    printf("===================================\n");
    printf("Emulate i386 code with IN/OUT instructions\n");

    // Initialize emulator in X86-32bit mode
    err = uc_open(UC_ARCH_X86, UC_MODE_32, &handle);
    if (err) {
        printf("Failed on uc_open() with error returned: %u\n", err);
        return;
    }

    // map 2MB memory for this emulation
    uc_mem_map(handle, ADDRESS, 2 * 1024 * 1024);

    // write machine code to be emulated to memory
    if (uc_mem_write(handle, ADDRESS, (uint8_t *)X86_CODE32_INOUT, sizeof(X86_CODE32_INOUT) - 1)) {
        printf("Failed to write emulation code to memory, quit!\n");
        return;
    }

    // initialize machine registers
    uc_reg_write(handle, X86_REG_EAX, &r_eax);
    uc_reg_write(handle, X86_REG_ECX, &r_ecx);

    // tracing all basic blocks with customized callback
    uc_hook_add(handle, &trace1, UC_HOOK_BLOCK, hook_block, NULL, (uint64_t)1, (uint64_t)0);

    // tracing all instructions
    uc_hook_add(handle, &trace2, UC_HOOK_CODE, hook_code, NULL, (uint64_t)1, (uint64_t)0);

    // handle IN instruction
    uc_hook_add(handle, &trace3, UC_HOOK_INSN, hook_in, NULL, X86_INS_IN);
    // handle OUT instruction
    uc_hook_add(handle, &trace4, UC_HOOK_INSN, hook_out, NULL, X86_INS_OUT);

    // emulate machine code in infinite time
    err = uc_emu_start(handle, ADDRESS, ADDRESS + sizeof(X86_CODE32_INOUT) - 1, 0, 0);
    if (err) {
        printf("Failed on uc_emu_start() with error returned %u: %s\n",
                err, uc_strerror(err));
    }

    // now print out some registers
    printf(">>> Emulation done. Below is the CPU context\n");

    uc_reg_read(handle, X86_REG_EAX, &r_eax);
    uc_reg_read(handle, X86_REG_ECX, &r_ecx);
    printf(">>> EAX = 0x%x\n", r_eax);
    printf(">>> ECX = 0x%x\n", r_ecx);

    uc_close(&handle);
}

static void test_x86_64(void)
{
    uch handle;
    uc_err err;
    uch trace1, trace2, trace3, trace4;

    int64_t rax = 0x71f3029efd49d41d;
    int64_t rbx = 0xd87b45277f133ddb;
    int64_t rcx = 0xab40d1ffd8afc461;
    int64_t rdx = 0x919317b4a733f01;
    int64_t rsi = 0x4c24e753a17ea358;
    int64_t rdi = 0xe509a57d2571ce96;
    int64_t r8 = 0xea5b108cc2b9ab1f;
    int64_t r9 = 0x19ec097c8eb618c1;
    int64_t r10 = 0xec45774f00c5f682;
    int64_t r11 = 0xe17e9dbec8c074aa;
    int64_t r12 = 0x80f86a8dc0f6d457;
    int64_t r13 = 0x48288ca5671c5492;
    int64_t r14 = 0x595f72f6e4017f6e;
    int64_t r15 = 0x1efd97aea331cccc;

    int64_t rsp = ADDRESS + 0x200000;


    printf("Emulate x86_64 code\n");

    // Initialize emulator in X86-64bit mode
    err = uc_open(UC_ARCH_X86, UC_MODE_64, &handle);
    if (err) {
        printf("Failed on uc_open() with error returned: %u\n", err);
        return;
    }

    // map 2MB memory for this emulation
    uc_mem_map(handle, ADDRESS, 2 * 1024 * 1024);

    // write machine code to be emulated to memory
    if (uc_mem_write(handle, ADDRESS, (uint8_t *)X86_CODE64, sizeof(X86_CODE64) - 1)) {
        printf("Failed to write emulation code to memory, quit!\n");
        return;
    }

    // initialize machine registers
    uc_reg_write(handle, X86_REG_RSP, &rsp);

    uc_reg_write(handle, X86_REG_RAX, &rax);
    uc_reg_write(handle, X86_REG_RBX, &rbx);
    uc_reg_write(handle, X86_REG_RCX, &rcx);
    uc_reg_write(handle, X86_REG_RDX, &rdx);
    uc_reg_write(handle, X86_REG_RSI, &rsi);
    uc_reg_write(handle, X86_REG_RDI, &rdi);
    uc_reg_write(handle, X86_REG_R8, &r8);
    uc_reg_write(handle, X86_REG_R9, &r9);
    uc_reg_write(handle, X86_REG_R10, &r10);
    uc_reg_write(handle, X86_REG_R11, &r11);
    uc_reg_write(handle, X86_REG_R12, &r12);
    uc_reg_write(handle, X86_REG_R13, &r13);
    uc_reg_write(handle, X86_REG_R14, &r14);
    uc_reg_write(handle, X86_REG_R15, &r15);

    // tracing all basic blocks with customized callback
    uc_hook_add(handle, &trace1, UC_HOOK_BLOCK, hook_block, NULL, (uint64_t)1, (uint64_t)0);

    // tracing all instructions in the range [ADDRESS, ADDRESS+20]
    uc_hook_add(handle, &trace2, UC_HOOK_CODE, hook_code64, NULL, (uint64_t)ADDRESS, (uint64_t)(ADDRESS+20));

    // tracing all memory WRITE access (with @begin > @end)
    uc_hook_add(handle, &trace3, UC_HOOK_MEM_WRITE, hook_mem64, NULL, (uint64_t)1, (uint64_t)0);

    // tracing all memory READ access (with @begin > @end)
    uc_hook_add(handle, &trace4, UC_HOOK_MEM_READ, hook_mem64, NULL, (uint64_t)1, (uint64_t)0);

    // emulate machine code in infinite time (last param = 0), or when
    // finishing all the code.
    err = uc_emu_start(handle, ADDRESS, ADDRESS + sizeof(X86_CODE64) - 1, 0, 0);
    if (err) {
        printf("Failed on uc_emu_start() with error returned %u: %s\n",
                err, uc_strerror(err));
    }

    // now print out some registers
    printf(">>> Emulation done. Below is the CPU context\n");

    uc_reg_read(handle, X86_REG_RAX, &rax);
    uc_reg_read(handle, X86_REG_RBX, &rbx);
    uc_reg_read(handle, X86_REG_RCX, &rcx);
    uc_reg_read(handle, X86_REG_RDX, &rdx);
    uc_reg_read(handle, X86_REG_RSI, &rsi);
    uc_reg_read(handle, X86_REG_RDI, &rdi);
    uc_reg_read(handle, X86_REG_R8, &r8);
    uc_reg_read(handle, X86_REG_R9, &r9);
    uc_reg_read(handle, X86_REG_R10, &r10);
    uc_reg_read(handle, X86_REG_R11, &r11);
    uc_reg_read(handle, X86_REG_R12, &r12);
    uc_reg_read(handle, X86_REG_R13, &r13);
    uc_reg_read(handle, X86_REG_R14, &r14);
    uc_reg_read(handle, X86_REG_R15, &r15);

    printf(">>> RAX = 0x%" PRIx64 "\n", rax);
    printf(">>> RBX = 0x%" PRIx64 "\n", rbx);
    printf(">>> RCX = 0x%" PRIx64 "\n", rcx);
    printf(">>> RDX = 0x%" PRIx64 "\n", rdx);
    printf(">>> RSI = 0x%" PRIx64 "\n", rsi);
    printf(">>> RDI = 0x%" PRIx64 "\n", rdi);
    printf(">>> R8 = 0x%" PRIx64 "\n", r8);
    printf(">>> R9 = 0x%" PRIx64 "\n", r9);
    printf(">>> R10 = 0x%" PRIx64 "\n", r10);
    printf(">>> R11 = 0x%" PRIx64 "\n", r11);
    printf(">>> R12 = 0x%" PRIx64 "\n", r12);
    printf(">>> R13 = 0x%" PRIx64 "\n", r13);
    printf(">>> R14 = 0x%" PRIx64 "\n", r14);
    printf(">>> R15 = 0x%" PRIx64 "\n", r15);

    uc_close(&handle);
}

int main(int argc, char **argv, char **envp)
{
    if (argc == 2) {
        if (!strcmp(argv[1], "-32")) {
            test_i386();
            test_i386_inout();
            test_i386_jump();
            test_i386_loop();
            test_i386_invalid_mem_read();
            test_i386_invalid_mem_write();
            test_i386_jump_invalid();
        }

        if (!strcmp(argv[1], "-64")) {
            test_x86_64();
        }

        // test memleak
        if (!strcmp(argv[1], "-0")) {
            while(1) {
                test_i386();
                // test_x86_64();
            }
        }
    } else {
        printf("Syntax: %s <-32|-64>\n", argv[0]);
    }

    return 0;
}
