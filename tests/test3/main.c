#include "../../include/shm_api.h"

#define print_test(str){fprintf(stderr, "\033[2m[t] " str "\033[0m\n");}
#define print_err(str){fprintf(stderr, "\033[31m[tE] " str "\033[0m\n");}

int main()
{
	print_test("start");
	void *pShmLib = dlopen("./lib_SharedMemoryLibrary.so", RTLD_LAZY);
	shmOpen_fp shm_simple_open = dlsym(pShmLib, "shm_simple_open");
	shmWrite_fp shm_write = dlsym(pShmLib, "shm_write");
	shmWrite_fp shm_rewrite = dlsym(pShmLib, "shm_rewrite");
	shmGetData_fp shm_getData = dlsym(pShmLib, "shm_getData");
	shmTerminate_fp shm_close = dlsym(pShmLib, "shm_close");
	shmTerminate_fp shm_destroy = dlsym(pShmLib, "shm_destroy");

	SharedMemoryInfo shmInfo = {};
	shmInfo.shmByteSize = 2;

	shm_simple_open(&shmInfo, "12345678");

	shm_write(&shmInfo, "FFFFFFFFFF", sizeof("FFFFFFFFFF"), 0);
	shm_write(&shmInfo, "FFFFFFFFFF", sizeof("FFFFFFFFFF"), 0);

	shm_rewrite(&shmInfo, "**********************\n__\ndsfsdf..\n.", sizeof("**********************\n__\ndsfsdf..\n."), 10);
	shm_write(&shmInfo, "FFFFFFFFFF", sizeof("FFFFFFFFFF"), 0);

	char buf[255];
	shm_getData(&shmInfo, &buf, 12, 0);
	printf("get: %s\n", buf);

	printf("Get from shared memory: \033[35m%s\033[0m\n", shmInfo.pMappedShmAddr);
	printf("name = %s\n", shmInfo.shmInfoName);
	printf("main name = %s\n", shmInfo.shmName);

	getchar();

	shm_destroy(&shmInfo);
	//shm_close(&shmInfo);

	dlclose(pShmLib);

	print_test("end");
	return 0;
}
