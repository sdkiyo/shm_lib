cmake_minimum_required ( VERSION 3.31.7 )

project( test3
	LANGUAGES C )

add_executable( ${PROJECT_NAME} main.c )
add_library( _SharedMemoryLibrary SHARED ../../src/shm_api.c )
