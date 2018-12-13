#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    umask(0);
    //create mkfifo 
    if(mkfifo("./Npipefifo", 0644) < 0){
        if(errno == EEXIST){
        }
        else{
            perror("mkfifo error");
            return -1;
        }
    }
    //open mkfifo 
    //must  write open and read open 
    int readfd = open("./Npipefifo", O_RDONLY);
    if(readfd < 0){
        perror("open error");
        return -1;
    }
    printf("open sucess!\n");
    while(1){
        usleep(50000);
        char buf[1024] = {0};
        int ret = read(readfd, buf, sizeof(buf) - 1);
        if(ret > 0){
            printf("client say: [%s] \n", buf);
        }
        else if(ret == 0){
            printf("all write close\n");
            sleep(1);
        }
    }
    return 0;
}
