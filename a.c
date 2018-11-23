#include<stdio.h>
#include<unistd.h>

int main(){
  char buf[1024] = {0};
  int i = 0;
  for(i = 0; i < 100; ++i){
    usleep(100*1000);
    buf[i] = 'l';
    if(i < 20){
      printf("\033[45m\r");
      printf("\033[35m%s\r", buf);
      printf("\033[30m%d%%\r",i+1);
    }
    else if(i < 60){
      printf("\033[44m\r");
      printf("\033[34m%s\r", buf);
      printf("\033[30m%d%%\r",i+1);
    }
    else{
      printf("\033[41m\r");
      printf("\033[31m%s\r", buf);
      printf("\033[30m%d%%\r",i+1);
    } 
    fflush(stdout);
  }
  printf("\n");

  printf("\033[0m");
  return 0;
}
