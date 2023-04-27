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
    
    //打开共享内存
    shmid = shmget(key, BUFSZ, IPC_CREAT|0666);

    //映射
    shmadd = (char*)shmat(shmid, NULL, 0);

    //读共享内存区数据
    printf("data = [%s]\n", shmadd);
    
    //分离共享内存和当前进程
    ret = shmdt(shmadd);

    //删除共享内存
  //  shmctl(shmid, IPC_RMID, NULL);
        
    return 0;
}