#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
  int fd[2];

  pipe(fd);
  write(fd[1], "Yo mama is so fat", 17+1);
  close(fd[1]);

  char message[20];

  memset(message, 0, 20);
  read(fd[0], message, 20);

  printf("Message: %s\n", message);
  return 0;
}
