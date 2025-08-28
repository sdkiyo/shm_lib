#pragma once
#ifndef _SHM_API_INCLUDES_H_
#define _SHM_API_INCLUDES_H_


#define _GNU_SOURCE
// base lib
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <semaphore.h>
#include <fcntl.h>

// date types
#include <string.h>
#include <unistd.h>
#include <stdint.h>

// платформозависимые решения
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>

// header files in project
#include "shm_defines.h"

#endif
