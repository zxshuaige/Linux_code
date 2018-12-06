#include<stdio.h>
#include<unistd.h>


int main()
{
  int value = 200;
  while(1){
    printf("xixixixi\n");
    sleep(2);
  }
  pid_t pid = fork();
  if(pid < 0){
    perror("fork");
  }
  else if(pid == 0){
    printf("child  pid = %d, ppid = %d, value = %d, &value = %p\n", getpid(), getppid(), value, &value);
    sleep(1);
    value = 300;
    printf("child  pid = %d, ppid = %d, value = %d, &value = %p\n", getpid(), getppid(), value, &value);
  }
  else{
    printf("father  pid = %d, ppid = %d, value = %d, &value = %p\n", getpid(), getppid(), value, &value);
    sleep(2);
    printf("father  pid = %d, ppid = %d, value = %d, &value = %p\n", getpid(), getppid(), value, &value);
  }
  return 0;
}
