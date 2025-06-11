cmake_minimum_required ( VERSION 3.31.7 )

project( test_bridge
	LANGUAGES C )

add_executable( ${PROJECT_NAME} main.c ../../src/shm_bridge.c )
