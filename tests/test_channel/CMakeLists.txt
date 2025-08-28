cmake_minimum_required ( VERSION 3.31.7 )

project( test_channel
	LANGUAGES C )

add_executable( ${PROJECT_NAME} main.c ../../src/shm_channel.c ../../src/shm_api.c ../../src/sem_api.c )
