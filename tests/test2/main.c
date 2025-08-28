#include "../../include/sem_api.h"

#define print_test(a){fprintf(stderr, "\033[2m[t] " a "\033[0m\n");}
#define print_err(a){fprintf(stderr, "\033[31m[tE] " a "\033[0m\n");}

int main()
{
	print_test("start");

	print_test("create semaphore");

	sem_t *sem;

	print_test("creating semaphore");
	if (sem_simple_create(&sem, "test2") == -1)
	{
		print_err("failed.");
	}

	print_test("dropping semaphore");
	if (sem_post(sem) == -1)
	{
		print_err("failed.");
	}

	print_test("waiting semaphore");
	if (sem_wait(sem) == -1)
	{
		print_err("failed.");
	}

	print_test("close semaphore");
	if (sem_close(sem) == -1)
	{
		print_err("failed.");
	}

	print_test("open semaphore");
	if (sem_simple_open(&sem, "test2") == -1)
	{
		print_err("failed.");
	}

	print_test("destroy semaphore");
	if (sem_unlink("test2") == -1)
	{
		print_err("failed.");
	}

	print_test("end");
	return 0;
}
