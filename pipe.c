#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(){
    int fd[2];
    if(pipe(fd) < 0){
        perror("pipe error");
        return -1;
    }

    pid_t pid = fork();
    if(pid < 0){
        perror("fork error");
        return -1;
    }
    if(pid == 0){
        //child  close write 
        close(fd[1]);
        char buf[1024] = {0};
        read(fd[0], buf, sizeof(buf) -1);
        printf("buf = %s\n",buf);
        close(fd[0]);
    }
    else{
        //father close read 
        sleep(2);
        close(fd[0]);
        char msg[] = "xixixhahahzhoudaxinbalalala";
        write(fd[1], msg, strlen(msg));
        close(fd[1]);
    }
}
