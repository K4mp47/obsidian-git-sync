#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(){
  char * pipein = "/tmp/pipeIn";
  char * pipeout = "/tmp/pipeOut";

  // leggi dalla pipeIN un carattere alla volta usando pipeIn
  int fd = open(pipeout, O_RDONLY);
  int fd1 = open(pipein, O_WRONLY);
  char c;
  int index;
  int check = 0;
  while(1){
    read(fd, &c, 1);
    if(check == 0){
      index = 'A' - c;
      check = 1;
    }
    if(c + index == '#'){
      check = 0;
    }
    //printf("%c\n", c);
    c = c + index;
    write(fd1, &c, 1);
  }
  close(fd);
 
  return 0;
}
