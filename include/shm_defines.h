#pragma once
#ifndef _SHM_API_DEFINES_H_
#define _SHM_API_DEFINES_H_


#ifndef _NOT_SHM_LIB_
//#define SHM_CHANNEL_SUFFIX ".ch"
//#define SHM_CHANNEL_BASE_SIZE 128
#define SHM_INFO_BASE_SIZE sizeof(off_t)
#define SHM_INFO_SUFFIX ".info"
#endif

#define SHM_NAME_LEN 9
#define INFO_SUFFIX_LEN 6

#define _shm_this_DEBUG


//--------------------------------------don't ask.-------------------------------------┐
#ifdef _shm_this_DEBUG
#define check_return_value(return_value, msg){\
	if (return_value == -1)\
	{\
		fprintf(stderr, "\033[31m"msg". errno: %s\033[0m\n", strerror(errno));\
		return -1;\
	}\
}
#else
#define check_return_value(return_value, msg){}
#endif
//--------------------------------------don't ask.-------------------------------------|
#ifdef _shm_this_DEBUG
#define check_mmap_return_value(return_value, msg){\
	if (return_value == MAP_FAILED)\
	{\
		fprintf(stderr, "\033[31m"msg". errno: %s\033[0m\n", strerror(errno));\
		return -1;\
	}\
}
#else
#define check_mmap_return_value(return_value, msg){}
#endif
//--------------------------------------don't ask.-------------------------------------|
#ifdef _shm_this_DEBUG
#define check_sem_return_value(return_value, msg){\
	if (return_value == SEM_FAILED)\
	{\
		fprintf(stderr, "\033[31m"msg". errno: %s\033[0m\n", strerror(errno));\
		return -1;\
	}\
}
#else
#define check_sem_return_value(return_value, msg){}
#endif
//--------------------------------------don't ask.-------------------------------------|
#ifdef _shm_this_DEBUG
#define print_debug(str, data){\
	fprintf(stderr, str, data);}
#else
#define print_debug(str, data){}
#endif
//--------------------------------------don't ask.-------------------------------------┘




#endif
