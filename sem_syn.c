#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<string.h>
#include<errno.h>
#include<sys/sem.h>

#define IPC_KEY 0x12345678
union semun{
    int val;
};

static int com_P(int semid, int sem_num){
    struct sembuf buf;
    buf.sem_num = sem_num;
    buf.sem_op = -1;
    buf.sem_flg = 0;
    if(semop(semid, &buf, 1) < 0)
    {
        perror("semop");
        return -3;
    }
    return 0;
}

static int com_V(int semid, int sem_num){
    struct sembuf buf;
    buf.sem_num = sem_num;
    buf.sem_op = 1;
    buf.sem_flg = 0;
    if(semop(semid, &buf, 1) < 0)
    {
        perror("semop");
        return -4;
    }
    return 0;
}

int main()
{
    int pid = 0;
    int semid = semget(IPC_KEY, 1, IPC_CREAT|0664);
    if(semid < 0){
        perror("semget");
        return -1;
    }
    union semun _un;
    _un.val = 1;
    if(semctl(semid, 0, SETVAL, _un) < 0)
    {
        perror("semctl");
        return -2;
    }
    pid = fork();
    if(pid < 0){
        perror("fork");
        return -1;
    }
    else if(pid == 0){
        //child
        int i = 0;
        while(1){
            if(i++ > 30){
                break;
            }
            usleep(500000);
            com_P(semid, 0);
            printf("who eat a food\n");
        } 
        exit(1);
    }
    else{
        //father
        int i = 0;
        while(1){
            if(i++ > 30){
                break;
            }
            usleep(200000);
            printf("there creat a food\n");
            com_V(semid, 0);
        }
        wait(NULL);
    }
    //if(semctl(semid, 0, IPC_RMID) < 0){
    //    perror("semctl rm");
    //    return -5;
    //}
    return 0;
}
