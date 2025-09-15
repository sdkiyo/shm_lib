#define _SHM_IN_DEV_
#include "../include/shm_api.h"


int8_t shm_close(const struct SharedMemoryInfo *const shmInfo)
{
	errno = 0;

	if (sem_wait(shmInfo->pSemaphore) == -1)
	{
		print_error("sem_wait failed");
		return -1;
	}

	if (munmap(shmInfo->pMappedShmAddr, shmInfo->shmByteSize) == -1)
	{
		print_error("munmap main failed");
		return -1;
	}

	if (munmap(shmInfo->pMappedShmInfoAddr, shmInfo->shmByteSize) == -1)
	{
		print_error("munmap info failed");
		return -1;
	}

	if (sem_post(shmInfo->pSemaphore) == -1)
	{
		print_error("sem_post failed");
		return -1;
	}

	if (sem_close(shmInfo->pSemaphore) == -1)
	{
		print_error("sem_close failed");
		return -1;
	}

	return 0;
}
