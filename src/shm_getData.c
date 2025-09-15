#define _SHM_IN_DEV_
#include "../include/shm_api.h"


int8_t shm_getData(const struct SharedMemoryInfo *const shmInfo, void* dest, const size_t byte_size, const size_t indent_bytes)
{
	sem_wait(shmInfo->pSemaphore);
	if (indent_bytes > (shmInfo->shmByteSize - 1))
	{
		fprintf(stderr, "\033[31mindent > memory size\033[0m\n");
		return -1;
	}

	memcpy(dest, shmInfo->pMappedShmAddr + indent_bytes, byte_size);

	sem_post(shmInfo->pSemaphore);
	return 0;
}
