#include "../../include/shm_channel.h"

#define print_test(a){fprintf(stderr, "\033[2m[t] " a "\033[0m\n");}
#define print_err(a){fprintf(stderr, "\033[31m[tE] " a "\033[0m\n");}

int main()
{
	print_test("start.");
	shm_channel ch;

	print_test("channel creating");

	if (shm_channel_create(&ch, "test_channel", "/test_channel", 64, "hello world, #'# ## ####. 12345 asdkl;--.--.-. **** ff |||") == -1)
	{
		print_err("shm_channel_create failed.");
	}

	printf("\033[2m[t] \033[0m\033[34mshm_min_size = %d\033[0m\n", ch.shm_min_size);

	print_test("printing data from memory");

	if (shm_print(&ch.shm_fd, ch.shm_min_size) == -1)
	{
		print_err("shm_print failed.");
	}

	print_test("channel delete");

	shm_channel_destroy(&ch);

	print_test("end.");
	return 0;
}
