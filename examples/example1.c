#include <shm_api.h>

int main() {
	ShmChannelData shmChannelData;
	shmChannelData.semaphore = create_msg_semaphore();

	drop_semaphore( shmChannelData.semaphore );
	sem_wait( shmChannelData.semaphore );

	open_msg_shm( &shmChannelData.shm );

	write_shm( shmChannelData.shm, "hello world!" );
	print_shm( shmChannelData.shm );

	close( shmChannelData.shm );
	delete_msg_shm();

	return 0;
}
