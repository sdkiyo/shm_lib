#include "../include/shm_api.h"


inline sem_t* create_task_semaphore() {
	errno = 0;
	sem_t *sem = sem_open(TASK_SEMAPHORE_NAME, O_CREAT, 0777, 0);
	if ( sem == SEM_FAILED ) {
		fprintf(stderr, "\033[31msem_open() failed. in create_task_semaphore(). errno: %s\033[0m\n", strerror(errno));
	}
	return sem;
}
inline sem_t* create_msg_semaphore() {
	errno = 0;
	sem_t *sem = sem_open(MSG_SEMAPHORE_NAME, O_CREAT, 0777, 0);
	if ( sem == SEM_FAILED ) {
		fprintf(stderr, "\033[31msem_open() failed. in create_msg_semaphore(). errno: %s\033[0m\n", strerror(errno));
	}
	return sem;
}
inline sem_t* create_err_semaphore() {
	errno = 0;
	sem_t *sem = sem_open(ERR_SEMAPHORE_NAME, O_CREAT, 0777, 0);
	if ( sem == SEM_FAILED ) {
		fprintf(stderr, "\033[31msem_open() failed. in create_err_semaphore(). errno: %s\033[0m\n", strerror(errno));
	}
	return sem;
}
inline sem_t* create_out_semaphore() {
	errno = 0;
	sem_t *sem = sem_open(OUT_SEMAPHORE_NAME, O_CREAT, 0777, 0);
	if ( sem == SEM_FAILED ) {
		fprintf(stderr, "\033[31msem_open() failed. in create_out_semaphore(). errno: %s\033[0m\n", strerror(errno));
	}
	return sem;
}

inline void open_task_semaphore( sem_t *sem ) {
	errno = 0;
	if ( (sem = sem_open(TASK_SEMAPHORE_NAME, 0)) == -1 ) {
		fprintf(stderr, "\033[31msem_open() failed. in open_task_semaphore(). errno: %s\033[0m\n", strerror(errno));
	}
}
inline void open_msg_semaphore( sem_t *sem ) {
	errno = 0;
	if ( (sem = sem_open(MSG_SEMAPHORE_NAME, 0)) == -1 ) {
		fprintf(stderr, "\033[31msem_open() failed. in open_msg_semaphore(). errno: %s\033[0m\n", strerror(errno));
	}
}
inline void open_err_semaphore( sem_t *sem ) {
	errno = 0;
	if ( (sem = sem_open(ERR_SEMAPHORE_NAME, 0)) == -1 ) {
		fprintf(stderr, "\033[31msem_open() failed. in open_err_semaphore(). errno: %s\033[0m\n", strerror(errno));
	}
}
inline void open_out_semaphore( sem_t *sem ) {
	errno = 0;
	if ( (sem = sem_open(OUT_SEMAPHORE_NAME, 0)) == -1 ) {
		fprintf(stderr, "\033[31msem_open() failed. in open_out_semaphore(). errno: %s\033[0m\n", strerror(errno));
	}
}

inline void drop_semaphore( sem_t *sem ) {
	errno = 0;
	if ( sem_post( sem ) == -1 ) {
		fprintf(stderr, "\033[31msem_post() failed. in drop_semaphore(). errno: %s\033[0m\n", strerror(errno));
	}
}


void open_task_shm( int *shm ) {
	errno = 0;

	if ( (*shm = shm_open(TASK_SHM_NAME, O_CREAT|O_RDWR, 0777)) == -1 ) {
		fprintf(stderr, "\033[31mshm_open() failed. in open_task_shm(). errno: %s\033[0m\n", strerror(errno));
	}
	if ( ftruncate( *shm, SHM_BASE_SIZE+1 ) == -1 ) {
		fprintf(stderr, "\033[31mftruncate() failed. in open_task_shm(). errno: %s\033[0m\n", strerror(errno));
	}
	//fprintf(stderr, "\033[2m\033[32mtask memory open, shm = %d\033[0m\n", shm);
}
void open_msg_shm( int *shm ) {
	errno = 0;

	if ( (*shm = shm_open(MSG_SHM_NAME, O_CREAT|O_RDWR, 0777)) == -1 ) {
		fprintf(stderr, "\033[31mshm_open() failed. in open_msg_shm(). errno: %s\033[0m\n", strerror(errno));
	}
	if ( ftruncate( *shm, SHM_BASE_SIZE+1 ) == -1 ) {
		fprintf(stderr, "\033[31mftruncate() failed. in open_msg_shm(). errno: %s\033[0m\n", strerror(errno));
	}
	//fprintf(stderr, "\033[2m\033[32mmsg memory open, shm = %d\033[0m\n", shm);
}
void open_err_shm( int *shm ) {
	errno = 0;

	if ( (*shm = shm_open(ERR_SHM_NAME, O_CREAT|O_RDWR, 0777)) == -1 ) {
		fprintf(stderr, "\033[31mshm_open() failed. in open_err_shm(). errno: %s\033[0m\n", strerror(errno));
	}
	if ( ftruncate( *shm, SHM_BASE_SIZE+1 ) == -1 ) {
		fprintf(stderr, "\033[31mftruncate() failed. in open_err_shm(). errno: %s\033[0m\n", strerror(errno));
	}
	//fprintf(stderr, "\033[2m\033[32merr memory open, shm = %d\033[0m\n", shm);
}
void open_out_shm( int *shm ) {
	errno = 0;

	if ( (*shm = shm_open(OUT_SHM_NAME, O_CREAT|O_RDWR, 0777)) == -1 ) {
		fprintf(stderr, "\033[31shm_open() failed. in open_out_shm(). errno: %s\033[0m\n", strerror(errno));
	}
	if ( ftruncate( *shm, SHM_BASE_SIZE+1 ) == -1 ) {
		fprintf(stderr, "\033[31mftruncate() failed. in open_out_shm(). errno: %s\033[0m\n", strerror(errno));
	}
	//fprintf(stderr, "\033[2m\033[32mout memory open, shm = %d\033[0m\n", shm);
}





void write_shm( const int shm, const char msg[] ) {
	errno = 0;
	int len = 0;

	len = strlen( msg );
	len = len<=SHM_BASE_SIZE ? len : SHM_BASE_SIZE;
	//fprintf(stderr, "len = %d\n", len);

	char *addr = mmap(0, SHM_BASE_SIZE+1, PROT_WRITE|PROT_READ, MAP_SHARED, shm, 0);
	if ( addr == MAP_FAILED ) {
		fprintf(stderr, "\033[31mmmap() failed. in write_shm(). errno: %s\033[0m\n", strerror(errno));
	}

	//printf("Get from old shared memory: %s\n", addr);
	memcpy(addr, msg, len);
	//printf("\033[2m\033[33mshm memory writed.\033[0m\n");
	//printf("Get from new shared memory: %s\n", addr);

	munmap(addr, SHM_BASE_SIZE);
}

void read_shm( const int shm, char *msg ) {
	errno = 0;
	char *addr = mmap(0, SHM_BASE_SIZE+1, PROT_READ, MAP_SHARED, shm, 0);
	if ( addr == MAP_FAILED ) {
		fprintf(stderr, "\033[31mmmap() failed. in read_shm(). errno: %s\033[0m\n", strerror(errno));
	}

	msg = malloc( sizeof(char) * strlen(addr) );
	for ( uint16_t i = 0; i < strlen(addr); i++ ) {
		msg[i] = addr[i];
	}
	//printf("Get from old shared memory: %s\n", addr);
	munmap(addr, SHM_BASE_SIZE);
}

inline void print_shm( const int shm ) {
	char *addr = mmap(0, SHM_BASE_SIZE+1, PROT_READ, MAP_SHARED, shm, 0);

	printf("Get from shared memory: %s\n", addr);
	munmap(addr, SHM_BASE_SIZE);
}


inline void delete_task_shm() {
	errno = 0;
	if ( shm_unlink(TASK_SHM_NAME) == -1 ) {
		fprintf(stderr, "\033[31mshm_unlink() failed. in delete_task_shm(). errno: %s\033[0m\n", strerror(errno));
	}
}
inline void delete_msg_shm() {
	errno = 0;
	if ( shm_unlink(MSG_SHM_NAME) == -1 ) {
		fprintf(stderr, "\033[31mshm_unlink() failed. in delete_msg_shm(). errno: %s\033[0m\n", strerror(errno));
	}
}
inline void delete_err_shm() {
	errno = 0;
	if ( shm_unlink(ERR_SHM_NAME) == -1 ) {
		fprintf(stderr, "\033[31mshm_unlink() failed. in delete_err_shm(). errno: %s\033[0m\n", strerror(errno));
	}
}
inline void delete_out_shm() {
	errno = 0;
	if ( shm_unlink(OUT_SHM_NAME) == -1 ) {
		fprintf(stderr, "\033[31mshm_unlink() failed. in delete_out_shm(). errno: %s\033[0m\n", strerror(errno));
	}
}
