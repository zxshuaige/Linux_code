#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  //execl("/usr/bin/ls", "ls", "-al", NULL);
  printf("-----------\n");
  //execlp("ls", "ls", "-al", NULL);
  char* env[] = {
    "AAAA=aaaa",
    NULL,     //must use NULL become last
  };
  //execle("./a.out", "./a.out", NULL, env);
  //printf("---------------\n");
  char* argv[] = {
    "ls",
    "-al",
    NULL 
  };
  char *argv1[] = {"./a.out", NULL};
  //execv("/usr/bin/ls", argv);
  //execvp("ls", argv);
  execve("./a.out", argv1, env);
}
