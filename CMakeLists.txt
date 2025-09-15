cmake_minimum_required (VERSION 3.31.7)
include(base-kit.cmake)

project( shmApi
	LANGUAGES C )

message(DEBUG "${blue}Project name: ${cyan}${PROJECT_NAME}${reset_color}")
message(DEBUG "${blue}Project version: ${cyan}${version}${reset_color}")
message(DEBUG "${blue}CMAKE_C_STANDARD: ${cyan}${CMAKE_C_STANDARD}${reset_color}")

add_library( ${PROJECT_NAME} SHARED
	src/shm_close.c		src/shm_destroy.c
	src/shm_getData.c	src/shm_rewrite.c
	src/shm_simple_open.c	src/shm_write.c
)

set(prefix "lib_")
set(suffix ".so")
set_target_properties( ${PROJECT_NAME} PROPERTIES
	PREFIX ${prefix}
	OUTPUT_NAME "${PROJECT_NAME}"
	SUFFIX ${suffix}
)

message(DEBUG "${blue}library name: ${cyan}${prefix}${PROJECT_NAME}${suffix}${reset_color}")
