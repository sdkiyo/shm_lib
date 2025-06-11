#include "../include/shm_bridge.h"

struct ShmBridge create_shm_bridge( const char *shm_name, const char *sem_name, const uint32_t base_size ) {
	ShmBridge bridge;
	bridge.shm_base_size = base_size;
	bridge.shm_name = shm_name;
	bridge.sem_name = sem_name;

	errno = 0;
	bridge.semaphore = sem_open( sem_name, O_CREAT, 0777, 0 );
	if ( bridge.semaphore == SEM_FAILED ) {
		fprintf(stderr, "\033[31msem_open() failed. in create_shm_bridge(). errno: %s\033[0m\n", strerror(errno));
	}

	errno = 0;
	if ( (bridge.shm = shm_open( shm_name, O_CREAT|O_RDWR, 0777 )) == -1 ) {
		fprintf(stderr, "\033[31mshm_open() failed. in create_shm_bridge(). errno: %s\033[0m\n", strerror(errno));
	}
	if ( ftruncate( bridge.shm, base_size+1 ) == -1 ) {
		fprintf(stderr, "\033[31mftruncate() failed. in create_shm_bridge(). errno: %s\033[0m\n", strerror(errno));
	}

	//drop_semaphore( bridge.sem );

	return bridge;
}
