#pragma once
#ifndef _SHM_API_H_
#define _SHM_API_H_

#include "shm_includes.h"


typedef struct ShmChannelData {
	sem_t *semaphore;
	int shm;
} ShmChannelData;


sem_t* create_task_semaphore();
sem_t* create_msg_semaphore();
sem_t* create_err_semaphore();
sem_t* create_out_semaphore();

void open_task_semaphore( sem_t *sem );
void open_msg_semaphore( sem_t *sem );
void open_err_semaphore( sem_t *sem );
void open_out_semaphore( sem_t *sem );

void drop_semaphore( sem_t *sem );



void open_task_shm( int *shm );
void open_msg_shm( int *shm );
void open_err_shm( int *shm );
void open_out_shm( int *shm );

void write_shm( const int shm, const char msg[] );
void read_shm( const int shm, char *addr );
void print_shm( const int shm );

void delete_task_shm();
void delete_msg_shm();
void delete_err_shm();
void delete_out_shm();

#endif
