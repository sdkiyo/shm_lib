#define _SHM_IN_DEV_
#include "../../include/shm_api.h"

#define print_test(str){fprintf(stderr, "\033[2m[t] " str "\033[0m\n");}
#define print_err(str){fprintf(stderr, "\033[31m[tE] " str "\033[0m\n");}

int main()
{
	print_test("start");

	SharedMemoryInfo shmInfo = {};
	shmInfo.shmByteSize = 54;

	print_test("opening the memory");
	if (shm_simple_open(&shmInfo, "12345678") == -1)
	{
		print_err("shm_simple_open failed");
	}

	printf("Get from old shared memory: \033[35m%s\033[0m\n", shmInfo.pMappedShmAddr);
	shm_write(&shmInfo, "hello world\n#### ######\n# ######### ## ## #### #########\nдывлаофыжвдо\ndlsfkjsdf.sldkfj\0", sizeof("hello world\n#### ######\n# ######### ## ## #### #########\nдывлаофыжвдо\ndlsfkjsdf.sldkfj\0"));
	printf("Get from shared memory: \033[35m%s\033[0m\n", shmInfo.pMappedShmAddr);
	printf("name = %s\n", shmInfo.shmInfoName);
	printf("main name = %s\n", shmInfo.shmName);

	getchar();

	shm_destroy(&shmInfo);

	print_test("end\n");
	return 0;
}
