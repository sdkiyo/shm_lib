#include "../include/shm_api.h"


int shm_simple_open(struct SharedMemoryInfo *shmInfo)
{
	if (strlen(shmInfo->shmName) > 8) {
		fprintf(stderr, "\033[33mThe name length for shared memory exceeds the allowed value, this may lead to undefined behavior.\033[0m\n");
	}

	errno = 0;
	int return_value = 0;

	shmInfo->pSemaphore = sem_open(shmInfo->shmName, O_CREAT, 0777, 1);
	check_sem_return_value(shmInfo->pSemaphore, "sem_open() failed. in shm_simple_open().");

	strcpy(shmInfo->shmInfoName, shmInfo->shmName);
	strcat(shmInfo->shmInfoName, SHM_INFO_SUFFIX);

	return_value = sem_wait(shmInfo->pSemaphore);
	check_return_value(return_value, "sem_wait() failed. in shm_simple_open().");

	shmInfo->shmInfoFileDescriptor = shm_open(shmInfo->shmInfoName, O_CREAT|O_RDWR, 0777);
	check_return_value(shmInfo->shmInfoFileDescriptor, "info shm_open() failed. in shm_simple_open().");

	return_value = ftruncate(shmInfo->shmInfoFileDescriptor, SHM_INFO_BASE_SIZE);
	check_return_value(return_value, "info ftruncate() failed. in shm_simple_open().");

	shmInfo->pMappedShmInfoAddr = mmap(nullptr, SHM_INFO_BASE_SIZE, PROT_WRITE|PROT_READ, MAP_SHARED, shmInfo->shmInfoFileDescriptor, 0);
	check_mmap_return_value(shmInfo->pMappedShmInfoAddr, "mmap() failed. in shm_open().");

	off_t old_shm_size = 0;
	memcpy(&old_shm_size, shmInfo->pMappedShmInfoAddr, SHM_INFO_BASE_SIZE);
	print_debug("get from info shm: \033[36m%ld\033[0m\n", old_shm_size);

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
	print_debug("shm_size = \033[36m%ld\033[0m ", shmInfo->shmByteSize);
	print_debug("old_size = \033[36m%ld\033[0m\n", old_shm_size);

	shmInfo->shmFileDescriptor = shm_open(shmInfo->shmName, O_CREAT|O_RDWR, 0777);
	check_return_value(shmInfo->shmFileDescriptor, "main shm_open() failed. in shm_simple_open().");

	return_value = ftruncate(shmInfo->shmFileDescriptor, shmInfo->shmByteSize);
	check_return_value(return_value, "main ftruncate() failed. in shm_simple_open().");

	shmInfo->pMappedShmAddr = mmap(nullptr, shmInfo->shmByteSize, PROT_WRITE|PROT_READ, MAP_SHARED, shmInfo->shmFileDescriptor, 0);
	check_mmap_return_value(shmInfo->pMappedShmAddr, "mmap() failed. in shm_open().");

	return_value = sem_post(shmInfo->pSemaphore);
	check_return_value(return_value, "sem_post() failed. in shm_simple_open().");
	return 0;
}


int shm_write(struct SharedMemoryInfo *shmInfo, const void const *data, const size_t data_byte_size)
{
	errno = 0;
	int return_value = 0;
	if (data_byte_size > shmInfo->shmByteSize)
	{
		shmInfo->shmByteSize = data_byte_size;
		sem_wait(shmInfo->pSemaphore);

		memcpy(shmInfo->pMappedShmInfoAddr, &shmInfo->shmByteSize, SHM_INFO_BASE_SIZE);

		return_value = ftruncate(shmInfo->shmFileDescriptor, data_byte_size);
		check_return_value(return_value, "ftruncate() failed. in shm_write().");

		shmInfo->pMappedShmAddr = mremap(shmInfo->pMappedShmAddr, shmInfo->shmByteSize, data_byte_size, 0, nullptr);
		check_mmap_return_value(shmInfo->pMappedShmAddr, "mremap() failed. in shm_write().");
	}

	memcpy(shmInfo->pMappedShmAddr, data, data_byte_size);

	sem_post(shmInfo->pSemaphore);
	return 0;
}


int shm_destroy(struct SharedMemoryInfo *shmInfo)
{
	int return_value = 0;
	sem_wait(shmInfo->pSemaphore);

	return_value = shm_unlink(shmInfo->shmName);
	check_return_value(return_value, "info shm_unlink() failed. in shm_write().");

	return_value = shm_unlink(shmInfo->shmInfoName);
	check_return_value(return_value, "main shm_unlink() failed. in shm_write().");

	return_value = sem_unlink(shmInfo->shmName);
	check_return_value(return_value, "sem_unlink() failed. in shm_write().");

	sem_post(shmInfo->pSemaphore);
	return 0;
}
