#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
 
#define BUFSZ 1024*1024
 
int main(int argc, char *argv[])
{
    int shmid;
    int ret;
    key_t key;
    char *shmadd;
    
    //创建key值
    key = ftok(".", 2016);
    printf("%x",key);
    
    //创建共享内存
    shmid = shmget(key, BUFSZ, IPC_CREAT|0666);    
    
    //映射
    shmadd = (char*)shmat(shmid, NULL, 0);

    //拷贝数据至共享内存区
    printf("copy data to shared-memory\n");
    bzero(shmadd, BUFSZ); // 共享内存清空
    strcpy(shmadd, "how are you, lh");
    
    return 0;
}