cmake_minimum_required ( VERSION 3.31.7 )

project( test3
	LANGUAGES C )

set (path ../../src)

add_executable( ${PROJECT_NAME} main.c )
add_library( _SharedMemoryLibrary SHARED
	${path}/shm_close.c
	${path}/shm_destroy.c
	${path}/shm_getData.c
	${path}/shm_rewrite.c
	${path}/shm_simple_open.c
	${path}/shm_write.c )
