#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){
  int fd = open("myfifo", O_WRONLY);
  if(fd < 0){
    perror("open");
    return 1;
  }
  while(1){
    // read in stdin  write to pipe
    printf("> ");
    fflush(stdout);
    char buf[1024] = {0};
    ssize_t read_size = read(0, buf, sizeof(buf) - 1);
    if(read_size < 0){
      perror("read");
      return 1;
    }
    if(read_size == 0){
      printf("read done\n");
      return 0;
    }
    buf[read_size] = 0;
    write(fd, buf, strlen(buf));
  }
  close(fd);
  return 0;
}
