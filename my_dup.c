#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    int writefd = open("./dup.txt", O_WRONLY);
    if(writefd < 0){
        perror("write open error");
        return -1;
    }
    int readfd = open("./dup2.txt", O_RDONLY);
    if(readfd < 0){
        perror("read open error");
        return -1;
    } 
    dup2(writefd, 1);
    dup2(readfd, 0);

    char buf[1024] = {0};
    int ret = read(0, buf, sizeof(buf) - 1);                                                                      
    if(ret < 0){ 
		perror("read error");                                                                                     
        return -1;                                                                                                
    }
    printf("buf = %s\n", buf);
    return 0;
}
