#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  pid_t pid;
  int count = 0;
  //printf("before: pid = %d\n", getpid());
  while(1){
    pid = fork();
    usleep(2000);
    if(pid < 0)
    {
      printf("this computer can fork %d times\n",count);
      return 1;
    }
    else if(pid == 0){
      printf("child have %d\n", count);
      exit(0);
    }
    count++;
  }
 // printf("father: pid = %d, return = %d\n", getpid(), pid);
  return 0;
}

