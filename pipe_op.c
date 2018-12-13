#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
//come true  | 
int main(){
    int pipefd[2];

    if(pipe(pipefd) < 0){
        perror("pipe error");
        return -1;
    }
    int pid = fork();
    if(pid < 0){
        perror("fork error");
        return -1;
    }
    else if(pid == 0){
        //child
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        execlp("grep", "grep", "shh", NULL);
        close(pipefd[0]);
    }
    else{
        //father 
        close(pipefd[0]);
        dup2(pipefd[1], 1);
        execlp("ps", "ps", "-ef", NULL);
        close(pipefd[1]);
    }
    return 0;
}
