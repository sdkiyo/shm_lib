#define _SHM_IN_DEV_
#include "../include/shm_api.h"


int8_t shm_simple_open(struct SharedMemoryInfo *const shmInfo, const char *const name)
{
	if (strlen(name) > SHM_NAME_LEN - 1)
	{
		fprintf(stderr, "\033[33mThe name length for shared memory exceeds the allowed value, this may lead to undefined behavior\033[0m\n");
	}

	strncpy(shmInfo->shmName, name, SHM_NAME_LEN - 1);
	shmInfo->shmName[SHM_NAME_LEN] = '\0';

	strncpy(shmInfo->shmInfoName, shmInfo->shmName, SHM_NAME_LEN - 1);
	strncat(shmInfo->shmInfoName, SHM_INFO_SUFFIX, SHM_INFO_NAME_LEN - 1);
	shmInfo->shmInfoName[SHM_INFO_NAME_LEN] = '\0';

	shmInfo->pSemaphore = sem_open(shmInfo->shmName, O_CREAT, 0777, 1);
	sem_wait(shmInfo->pSemaphore);

	shmInfo->shmInfoFileDescriptor = shm_open(shmInfo->shmInfoName, O_CREAT|O_RDWR, 0777);
	ftruncate(shmInfo->shmInfoFileDescriptor, SHM_INFO_BASE_SIZE);
	shmInfo->pMappedShmInfoAddr = mmap(nullptr, SHM_INFO_BASE_SIZE, PROT_WRITE|PROT_READ, MAP_SHARED, shmInfo->shmInfoFileDescriptor, 0);

	off_t old_shm_size = 0;
	memcpy(&old_shm_size, shmInfo->pMappedShmInfoAddr, SHM_INFO_BASE_SIZE);

	if (old_shm_size == 0)
	{
		memcpy(shmInfo->pMappedShmInfoAddr, &shmInfo->shmByteSize, SHM_INFO_BASE_SIZE);
	}
	else if (old_shm_size < shmInfo->shmByteSize)
	{
		memcpy(shmInfo->pMappedShmInfoAddr, &shmInfo->shmByteSize, SHM_INFO_BASE_SIZE);
	}
	else
	{
		shmInfo->shmByteSize = old_shm_size;
	}

	shmInfo->shmFileDescriptor = shm_open(shmInfo->shmName, O_CREAT|O_RDWR, 0777);
	ftruncate(shmInfo->shmFileDescriptor, shmInfo->shmByteSize);
	shmInfo->pMappedShmAddr = mmap(nullptr, shmInfo->shmByteSize, PROT_WRITE|PROT_READ, MAP_SHARED, shmInfo->shmFileDescriptor, 0);

	sem_post(shmInfo->pSemaphore);
	return 0;
}
