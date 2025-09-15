#pragma once
#ifndef _SHM_API_H_
#define _SHM_API_H_


#ifdef _SHM_IN_DEV_
#include "shm_includes.h"
#else
#include <dlfcn.h>
#include <sys/types.h>
#include <semaphore.h>
#include <stdint.h>
#include <stdio.h>
#endif

#define SHM_NAME_LEN 9
#define INFO_SUFFIX_LEN 6
#define SHM_INFO_NAME_LEN (SHM_NAME_LEN + INFO_SUFFIX_LEN - 1)

typedef struct SharedMemoryInfo {
	char shmName[SHM_NAME_LEN];
	char shmInfoName[SHM_INFO_NAME_LEN];
	sem_t *pSemaphore;
	off_t shmByteSize;
	size_t writed_bytes;
	void *pMappedShmAddr;
	void *pMappedShmInfoAddr;
	int shmFileDescriptor;
	int shmInfoFileDescriptor;
} SharedMemoryInfo;


#ifdef _SHM_IN_DEV_
int8_t shm_simple_open(struct SharedMemoryInfo *const shmInfo, const char *const name);

int8_t shm_write(struct SharedMemoryInfo *const shmInfo, const void *const data, const size_t data_byte_size, const size_t indent_bytes);

int8_t shm_rewrite(struct SharedMemoryInfo *const shmInfo, const void *const data, const size_t data_byte_size, const size_t indent_bytes);

int8_t shm_getData(const struct SharedMemoryInfo *const shmInfo, void* dest, const size_t byte_size, const size_t indent_bytes);

int8_t shm_close(const struct SharedMemoryInfo *const shmInfo);

int8_t shm_destroy(const struct SharedMemoryInfo *const shmInfo);
#else
// _fp = function pointer
typedef void (*shmOpen_fp)(struct SharedMemoryInfo *const shmInfo, const char *const name);
typedef void (*shmWrite_fp)(struct SharedMemoryInfo *const shmInfo, const void *const data, const size_t data_byte_size, const size_t indent_bytes);
typedef void (*shmGetData_fp)(const struct SharedMemoryInfo *const shmInfo, void* dest, const size_t byte_size, const size_t indent_bytes);
typedef void (*shmTerminate_fp)(const struct SharedMemoryInfo* const shmInfo);
#endif


#endif
