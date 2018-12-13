#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sysexits.h>
int main(){
  int count = 0;
  while(1){
    usleep(40000);
    int fd[2] = {0};
    int ret = pipe(fd);
    if(ret < 0){ 
      printf("i can pipe %d times\n", count);
      perror("pipe!!");
      break;
    }
    else{
      printf("this is %d pipe\n",count);
    }
    count++;
  }
  //pid_t pid = 0;
  //pid = fork();
  //if(pid < 0){
  // 
  // perror("fork!");
  //}
  //else if(pid == 0){
  //  int fd[2];
  //  int ret = pipe(fd);
  //  if(ret < 0){
  //    printf("pipe can create %d num\n", count);
  //  }
  //  count++;
  //}
  //else{
    
  //}
  return 0;
}
