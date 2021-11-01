/* Unicorn Emulator Engine */
/* By Lazymio(@wtdcode), 2021 */

/* Sample code to demonstrate how to use uc_ctl */

#include <unicorn/unicorn.h>
#include <string.h>

// code to be emulated

// INC ecx; DEC edx; PXOR xmm0, xmm1
#define X86_CODE32 "\x41\x4a"
//   cmp eax, 0;
//   jg lb;
//   inc eax;
//   nop;
// lb:
//   inc ebx;
//   nop;
#define X86_JUMP_CODE "\x83\xf8\x00\x7f\x02\x40\x90\x43\x90"

// memory address where emulation starts
#define ADDRESS 0x10000

static void test_uc_ctl_read(void)
{
    uc_engine *uc;
    uc_err err;
    int mode, arch;
    uint32_t pagesize;
    uint64_t timeout;

    printf("Reading some properties by uc_ctl.\n");

    // Initialize emulator in X86-32bit mode
    err = uc_open(UC_ARCH_X86, UC_MODE_32, &uc);
    if (err) {
        printf("Failed on uc_open() with error returned: %u\n", err);
        return;
    }

    // Let's query some properties by uc_ctl.
    // Note uc_ctl_* is just tiny macro wrappers for uc_ctl().
    err = uc_ctl_get_mode(uc, &mode);
    if (err) {
        printf("Failed on uc_ctl() with error returned: %u\n", err);
        return;
    }

    err = uc_ctl_get_arch(uc, &arch);
    if (err) {
        printf("Failed on uc_ctl() with error returned: %u\n", err);
        return;
    }

    err = uc_ctl_get_timeout(uc, &timeout);
    if (err) {
        printf("Failed on uc_ctl() with error returned: %u\n", err);
        return;
    }

    err = uc_ctl_get_page_size(uc, &pagesize);
    if (err) {
        printf("Failed on uc_ctl() with error returned: %u\n", err);
        return;
    }

    printf(">>> mode = %d, arch = %d, timeout=%" PRIu64 ", pagesize=%" PRIu32
           "\n",
           mode, arch, timeout, pagesize);

    uc_close(uc);
}

void test_uc_ctl_exits()
{
    uc_engine *uc;
    uc_err err;
    int r_eax, r_ebx;
    uint64_t exits[] = {ADDRESS + 6, ADDRESS + 8};

    printf("Using multiple exits by uc_ctl.\n");

    // Initialize emulator in X86-32bit mode
    err = uc_open(UC_ARCH_X86, UC_MODE_32, &uc);
    if (err) {
        printf("Failed on uc_open() with error returned: %u\n", err);
        return;
    }

    err = uc_mem_map(uc, ADDRESS, 0x1000, UC_PROT_ALL);
    if (err) {
        printf("Failed on uc_mem_map() with error returned: %u\n", err);
        return;
    }

    // Write our code to the memory.
    err = uc_mem_write(uc, ADDRESS, X86_JUMP_CODE, sizeof(X86_JUMP_CODE) - 1);
    if (err) {
        printf("Failed on uc_mem_write() with error returned: %u\n", err);
        return;
    }

    // Enable multiple exits.
    err = uc_ctl_exits_enabled(uc, true);
    if (err) {
        printf("Failed on uc_ctl() with error returned: %u\n", err);
        return;
    }

    err = uc_ctl_set_exists(uc, exits, 2);
    if (err) {
        printf("Failed on uc_ctl() with error returned: %u\n", err);
        return;
    }

    // This should stop at ADDRESS + 6 and increase eax, even thouhg we don't
    // provide an exit.
    err = uc_emu_start(uc, ADDRESS, 0, 0, 0);
    if (err) {
        printf("Failed on uc_emu_start() with error returned: %u\n", err);
        return;
    }

    err = uc_reg_read(uc, UC_X86_REG_EAX, &r_eax);
    if (err) {
        printf("Failed on uc_reg_read() with error returned: %u\n", err);
        return;
    }
    err = uc_reg_read(uc, UC_X86_REG_EBX, &r_ebx);
    if (err) {
        printf("Failed on uc_reg_read() with error returned: %u\n", err);
        return;
    }
    printf(">>> eax = %" PRId32 " and ebx = %" PRId32
           " after the first emulation\n",
           r_eax, r_ebx);

    // This should stop at ADDRESS + 8, even thouhg we don't provide an exit.
    err = uc_emu_start(uc, ADDRESS, 0, 0, 0);
    if (err) {
        printf("Failed on uc_emu_start() with error returned: %u\n", err);
        return;
    }

    err = uc_reg_read(uc, UC_X86_REG_EAX, &r_eax);
    if (err) {
        printf("Failed on uc_reg_read() with error returned: %u\n", err);
        return;
    }
    err = uc_reg_read(uc, UC_X86_REG_EBX, &r_ebx);
    if (err) {
        printf("Failed on uc_reg_read() with error returned: %u\n", err);
        return;
    }
    printf(">>> eax = %" PRId32 " and ebx = %" PRId32
           " after the second emulation\n",
           r_eax, r_ebx);

    uc_close(uc);
}

int main(int argc, char **argv, char **envp)
{
    test_uc_ctl_read();
    printf("====================\n");
    test_uc_ctl_exits();

    return 0;
}
