cmake_minimum_required ( VERSION 3.31.7 )
include(base-kit.cmake)

message(DEBUG "${magenta}Starting compiling${blue} 'imagine a very cool project name'${yellow} library${rc}${gray}...${rc}")

project( shm_api
	VERSION ${ver}
	LANGUAGES C )

message(DEBUG "${blue}Project_Version: ${ver}${rc}")

add_library( _SharedMemoryLibrary SHARED src/shm_api.c )
