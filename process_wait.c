#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
  pid_t pid;

  pid = fork();
  if(pid < 0)
  {
    perror("fork!");
  }
  else if(pid == 0)
  {
    printf("child: pid = %d\n",getpid());
    sleep(5);
    exit(250);
  }
  else
  {
    int st;
    int ret = wait(&st);
    printf("father: pid = %d, ret = %d, st = %d\n", getpid(), ret, st);
  }
  return 0;
}
