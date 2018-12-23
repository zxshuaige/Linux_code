#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

void *pthread1(void* arg){
    pthread_detach(pthread_self());
    printf("pthread1 say: %s\n", (char*)arg);
    sleep(1);
}

int main()
{
    pthread_t tid;
    void *value;

    if(0 != pthread_create(&tid, NULL, pthread1, "xxxhhh")){
        perror("pthread_create error");
    }
    sleep(5);
    if(0 != pthread_join(tid, &value)){
        perror("pthread_join error");
    }

    return 0;
}







