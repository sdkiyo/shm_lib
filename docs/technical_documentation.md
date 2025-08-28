# Technical Documentation [shm_interface](https://)
###### [сслыка на супер текст](#супер-текст)
##### [сслыка на супер текст](#супер-текст)
##### [сслыка на супер текст](#супер-текст)
##### [сслыка на супер текст](#супер-текст)
#### [сслыка на супер текст](#супер-текст)
#### [сслыка на супер текст](#супер-текст)

___
## SharedMemoryInfo
структура предназначенная для хранения данных о разделяемой памяти
~~~C
typedef struct SharedMemoryInfo {
    char shmName[SHM_NAME_LEN];
    char shmInfoName[SHM_NAME_LEN+INFO_SUFFIX_LEN];
    sem_t *pSemaphore;
    off_t shmByteSize;
    void *pMappedShmAddr;
    void *pMappedShmInfoAddr;
    int shmFileDescriptor;
    int shmInfoFileDescriptor;
} SharedMemoryInfo;
~~~
___
## shm_write()
записывает данные в разделяемую память, при успешном выполнении функция возвращает `0`, при ошибке `-1`.
~~~
int shm_write(struct SharedMemoryInfo *shmInfo, const void const *data, const size_t data_byte_size);
~~~
###### всё.

