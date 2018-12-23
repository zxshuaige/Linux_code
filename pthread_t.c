#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

void *pthread1(void* arg){
    printf("this is pthread1\n");
    sleep(1);
    int *p = (int*)malloc(4);
    *p = 1;
    return (void*)p;
}

void *pthread2(void* arg){
    printf("this is pthread2\n");
    sleep(1);
    int *p = (int*)malloc(4);
    *p = 22;
    pthread_exit((void*)p);
}


void *pthread3(void* arg){
    while(1){
        printf("this is pthread3\n");
        sleep(1);
    }
    return NULL;
}
int main()
{
    pthread_t tid;
    void *value;

    if(0 != pthread_create(&tid, NULL, pthread1, NULL)){
        perror("pthread_create error");
    }
    if(0 != pthread_join(tid, &value)){
        perror("pthread_join error");
    }
    printf("pthread1: tid is %x, return is %d\n", (int)tid, *(int*)value);
    free(value);

    if(0 != pthread_create(&tid, NULL, pthread2, NULL)){
        perror("pthread_create error");
    }
    if(0 != pthread_join(tid, &value)){
        perror("pthread_join error");
    }
    printf("pthread2: tid is %x, return is %d\n", (int)tid, *(int*)value);
    free(value);
    
    if(0 != pthread_create(&tid, NULL, pthread3, NULL))
        perror("pthread_create error");
    sleep(5);
    if(0 != pthread_cancel(tid))
        perror("pthread_cancel error");
    if(0 != pthread_join(tid, &value))
        perror("pthread_join error");
    if(value == PTHREAD_CANCELED){
        printf("pthread3: tid is %x, return is PTHREAD_CANCELED \n", (int)tid);
    }
    else
        printf("pthread3: tid is %x, return is NULL \n", (int)tid);
    return 0;
}









