/*
	refer to issue #575.
	to run correctly unicorn needs to be compiled for AArch64.
*/

#include "unicorn_test.h"
#include <stdio.h>

uint64_t trunc_page(uint64_t addr)
{
	return (addr & ~(4095));
}

/* Called before every test to set up a new instance */
static int init(void **state)
{
	printf("[+] Initializing Unicorn...\n");
	uc_engine *uc;

	if (uc_open(UC_ARCH_ARM64, UC_MODE_ARM, &uc) != UC_ERR_OK) {
		printf("Error on open. Be sure that your unicorn library supports AArch64.\n");
		return -1;
	}

	*state = uc;

	return 0;
}

/* Called after every test to clean up */
static int teardown(void **state)
{
	printf("[+] Exiting...\n");
	uc_engine *uc = *state;

	uc_close(uc);

	*state = NULL;
	return 0;
}

void ayy(void **state)
{
	uint32_t code[] = {
		0xd503201f, /* NOP */
		0xd503201f, /* NOP */
		0xd503201f, /* NOP */
		0xaa0103e0  /* MOV X0, X1 */
	};

	uc_engine *uc = *state;

	uint64_t x0 = 0;
	uint64_t x1 = 1;

	uint64_t addr = 0x13f0;
	uint64_t trunc_addr = trunc_page(addr);    // round down to nearest page

	uc_mem_map(uc, trunc_addr, 2 * 1024 * 1024, UC_PROT_ALL);

	if (uc_mem_write(uc, addr, &code, sizeof(code))) {
		printf("error on write\n");
		return;
	}

	uc_reg_write(uc, UC_ARM64_REG_X0, &x0);
	uc_reg_write(uc, UC_ARM64_REG_X1, &x1);

	if (uc_emu_start(uc, addr, addr + sizeof(code), 0, 0)) {
		printf("error on start\n");
		return;
	}

	uc_reg_read(uc, UC_ARM64_REG_X0, &x0);
	uc_reg_read(uc, UC_ARM64_REG_X1, &x1);

	printf("x0: %#llx\n", x0);
	printf("x1: %#llx\n", x1);
}

int main(int argc, const char * argv[]) {

	const struct CMUnitTest tests[] = {
		cmocka_unit_test_setup_teardown(ayy, init, teardown),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);;
}
