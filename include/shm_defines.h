#pragma once
#ifndef _SHM_API_DEFINES_H_
#define _SHM_API_DEFINES_H_


#define SHM_INFO_BASE_SIZE sizeof(off_t)
#define SHM_INFO_SUFFIX ".info"


#define RED "\033[31m"
#define RESET_COLOR "\033[0m"


#define print_error(msg){\
	fprintf(stderr, RED"error in %s(), line %d, "msg", errno: %s"RESET_COLOR"\n", __func__, __LINE__, strerror(errno));\
}


#endif
