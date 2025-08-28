#include "../../include/shm_api.h"

#define print_test(a){fprintf(stderr, "\033[2m[t] " a "\033[0m\n");}
#define print_err(a){fprintf(stderr, "\033[31m[tE] " a "\033[0m\n");}

int main()
{
	print_test("start");

	SharedMemoryInfo shmInfo;
	strcpy(shmInfo.shmName, "12345678");
	shmInfo.shmByteSize = 54;

	print_test("opening the memory");
	if (shm_simple_open(&shmInfo) == -1)
	{
		print_err("shm_simple_open failed.");
	}

	printf("Get from old shared memory: \033[35m%s\033[0m\n", shmInfo.pMappedShmAddr);
	shm_write(&shmInfo, "hello world\n#### ######\n# ######### ## ## #### #########\nдывлаофыжвдо\ndlsfkjsdf.sldkfj\0", sizeof("hello world\n#### ######\n# ######### ## ## #### #########\nдывлаофыжвдо\ndlsfkjsdf.sldkfj\0"));
	printf("Get from shared memory: \033[35m%s\033[0m\n", shmInfo.pMappedShmAddr);
	printf("name = %s\n", shmInfo.shmInfoName);
	printf("main name = %s\n", shmInfo.shmName);

	//off_t a = 1234567;
	//shm_write(&ch, &a, sizeof(off_t));
	//off_t x = 0;
	//memcpy(&x, ch.addr, sizeof(off_t));
	//printf("get intenger: %d\n", x);
	//munmap(ch.addr, ch.mem_size);

	print_test("waiting sem..");
	if (sem_wait(shmInfo.pSemaphore) == -1) {
		print_err("sem_wait failed.");
	}
	printf("name = %s\n", shmInfo.shmInfoName);
	print_test("get sem.");

	scanf("%c");

	print_test("dropping the semaphore");
	if (sem_post(shmInfo.pSemaphore) == -1)
	{
		print_err("sem_post failed.");
	}

	shm_destroy(&shmInfo);
//	print_test("delete memory");
//	if (shm_unlink(shmInfo.shmName) == -1)
//	{
//		print_err("main shm_unlink failed.");
//	}
//	printf("name = %s\n", shmInfo.shmInfoName);
//	if (shm_unlink(shmInfo.shmInfoName) == -1)
//	{
//		print_err("info shm_unlink failed.");
//	}
//
//	print_test("delete semaphore");
//	if (sem_unlink(shmInfo.shmName) == -1)
//	{
//		print_err("sem_unlink failed.");
//	}

	print_test("end");
	return 0;
}
