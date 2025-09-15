#define _SHM_IN_DEV_
#include "../include/shm_api.h"


int8_t shm_rewrite(struct SharedMemoryInfo *const shmInfo, const void *const data, const size_t data_byte_size, const size_t indent_bytes)
{
	sem_wait(shmInfo->pSemaphore);
	bool is_resize = false;

	if ((data_byte_size + indent_bytes) > shmInfo->shmByteSize)
	{
		is_resize = true;
		size_t old_byte_size = 0;

		old_byte_size = shmInfo->shmByteSize;
		shmInfo->shmByteSize = data_byte_size + indent_bytes;

		memcpy(shmInfo->pMappedShmInfoAddr, &shmInfo->shmByteSize, SHM_INFO_BASE_SIZE);
		ftruncate(shmInfo->shmFileDescriptor, shmInfo->shmByteSize);
		shmInfo->pMappedShmAddr = mremap(shmInfo->pMappedShmAddr, old_byte_size, shmInfo->shmByteSize, 0, nullptr);
	}

	memcpy(shmInfo->pMappedShmAddr + indent_bytes, data, data_byte_size);
	if (is_resize == true)
	{
		shmInfo->writed_bytes = shmInfo->shmByteSize;
	}
	else
	{
		shmInfo->writed_bytes = shmInfo->writed_bytes + data_byte_size + indent_bytes;
	}

	sem_post(shmInfo->pSemaphore);
	return 0;
}
