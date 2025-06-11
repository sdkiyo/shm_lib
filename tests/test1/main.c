#include "../../include/shm_api.h"

int main() {
	fprintf(stderr, "\033[2mShmChannelData initialization.\033[0m\n");
	ShmChannelData test1;

	fprintf(stderr, "\033[2mopening shm.\033[0m\n");
	open_msg_shm( &test1.shm );

	fprintf(stderr, "\033[2mwriting data to shm.\033[0m\n");
	write_shm( test1.shm, "hello world!" );

	fprintf(stderr, "\033[2mprint data in shm.\033[0m\n");
	print_shm( test1.shm );

	fprintf(stderr, "\033[2mclosing shm.\033[0m\n");
	close( test1.shm );

	fprintf(stderr, "\033[2mdelete shm.\033[0m\n");
	delete_msg_shm();
	return 0;
}
