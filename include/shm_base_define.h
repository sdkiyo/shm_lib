#pragma once
#ifndef _SHM_API_BASE_DEFINE_H_
#define _SHM_API_BASE_DEFINE_H_


#define TASK_SEMAPHORE_NAME "/task_sem"
#define MSG_SEMAPHORE_NAME "/msg_sem"
#define ERR_SEMAPHORE_NAME "/err_sem"
#define OUT_SEMAPHORE_NAME "/out_sem"

#define TASK_SHM_NAME "task_mem"
#define MSG_SHM_NAME "msg_mem"
#define ERR_SHM_NAME "err_mem"
#define OUT_SHM_NAME "out_mem"
#define SHM_BASE_SIZE 64

#define SHM_CREATE 1
#define SHM_PRINT  3
#define SHM_CLOSE  4

#define this_DEBUG


#endif
