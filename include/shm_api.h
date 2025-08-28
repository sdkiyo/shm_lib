#pragma once
#ifndef _SHM_API_H_
#define _SHM_API_H_


#ifndef _NOT_SHM_LIB_
#include "shm_includes.h"
#else
#include <dlfcn.h>
#include <sys/types.h>
#include <semaphore.h>
#include <stdint.h>
#include <stdio.h>
#include "shm_defines.h"
#endif

typedef struct SharedMemoryInfo {
	char shmName[SHM_NAME_LEN];
	char shmInfoName[SHM_NAME_LEN+INFO_SUFFIX_LEN];
	sem_t *pSemaphore;
	off_t shmByteSize;
	void *pMappedShmAddr;
	void *pMappedShmInfoAddr;
	int shmFileDescriptor;
	int shmInfoFileDescriptor;
} SharedMemoryInfo;


#ifndef _NOT_SHM_LIB_
int shm_simple_open(struct SharedMemoryInfo *shmInfo);

int shm_write(struct SharedMemoryInfo *shmInfo, const void const *data, const size_t data_byte_size);

int shm_destroy(struct SharedMemoryInfo *shmInfo);
#else
typedef void (*shmSimpleOpen_t)(struct SharedMemoryInfo *shmInfo);
typedef void (*shmWrite_t)(struct SharedMemoryInfo *shmInfo, const void const *data, const size_t data_byte_size);
typedef void (*shmDestroy_t)(struct SharedMemoryInfo *shmInfo);
#endif


#endif
