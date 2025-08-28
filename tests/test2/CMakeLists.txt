cmake_minimum_required ( VERSION 3.31.7 )

project( test2
	LANGUAGES C )

add_executable( ${PROJECT_NAME} main.c ../../src/sem_api.c )
