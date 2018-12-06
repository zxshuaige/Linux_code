#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  int value = 100;
  pid_t pid = vfork();
  if(pid == 0)
  {
    printf("child, pid = %d, ppid = %d, value = %d\n",getpid(), getppid(), value);
    value = 2020;
    sleep(1);
    printf("child, pid = %d, ppid = %d, value = %d\n",getpid(), getppid(), value);
    exit(0);
  }
  printf("child, pid = %d, ppid = %d, value = %d\n",getpid(), getppid(), value);
  sleep(2);
  printf("child, pid = %d, ppid = %d, value = %d\n",getpid(), getppid(), value);
  return 0;
}
