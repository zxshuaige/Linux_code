#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>

#define IPC_KEY 0x12345678

int main()
{
    //create
    int shmid = -1;
    shmid = shmget(IPC_KEY, 64, IPC_CREAT|0664);
    if(shmid < 0){
        perror("shmget error");
        return -1;
    }
    //yingshe to address space
    void *shm_start = shmat(shmid, NULL, 0);
    if(shm_start == (void*)-1){
        perror("shmat error");
        return -1;
    }
    //data copy
    while(1){
        printf("please input: ");
        fflush(stdout);
        memset(shm_start, 0x00, 64);
        scanf("%s", (char*)shm_start);
        sleep(1);
    }
    //jiechuyingshe
    if(shmdt(shm_start) < 0){
        perror("shmdt error");
        return -1;
    }
    //delete
    if(shmctl(shmid, IPC_RMID, NULL) < 0){
        perror("shmctl error");
        return -1;
    }
    return 0;
}
