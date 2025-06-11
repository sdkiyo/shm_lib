#pragma once
#ifndef _SHM_API_BRIDGE_H_
#define _SHM_API_BRIDGE_H_

#include "shm_api.h"

typedef struct ShmBridge {
	sem_t *semaphore;
	int shm;
	uint32_t shm_base_size;
	char *shm_name;
	char *sem_name;
} ShmBridge;

struct ShmBridge create_shm_bridge( const char *bridge_name, const char *sem_name, const uint32_t base_size );

void destroy_shm_bridge( struct ShmBridge bridge );

#endif
