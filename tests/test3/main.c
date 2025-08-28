#define _NOT_SHM_LIB_
#include "../../include/shm_api.h"
#include <string.h>

#define print_test(a){fprintf(stderr, "\033[2m[t] " a "\033[0m\n");}
#define print_err(a){fprintf(stderr, "\033[31m[tE] " a "\033[0m\n");}

int main()
{
	print_test("start");
	void *pShmLib = dlopen("./lib_SharedMemoryLibrary.so", RTLD_LAZY);
	shmWrite_t shm_write = dlsym(pShmLib, "shm_write");
	shmSimpleOpen_t shm_simple_open = dlsym(pShmLib, "shm_simple_open");
	shmDestroy_t shm_destroy = dlsym(pShmLib, "shm_destroy");

	SharedMemoryInfo shmInfo = {};
	strcpy(shmInfo.shmName, "12345678");
	shmInfo.shmByteSize = 64;

	shm_simple_open(&shmInfo);

	shm_write(&shmInfo, "test", sizeof("test"));


	shm_destroy(&shmInfo);

	dlclose(pShmLib);
	return 0;
}
