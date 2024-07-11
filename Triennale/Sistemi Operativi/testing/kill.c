#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
  pid_t pid1,pid2;

  pid1 = fork();
  if(pid1 < 0){
    perror("errore fork"); exit(EXIT_FAILURE);
  } else if(pid1 == 0){
    while(1) {
      printf("Sono figlio 1\n");
      sleep(1); 
    }
  }

  pid2 = fork();
  if(pid2 < 0){
    perror("errore fork"); exit(EXIT_FAILURE);
  } else if(pid2 == 0){
    while(1) {
      printf("Sono figlio 2\n");
      sleep(1); 
    }
  }

  sleep(2);
  kill(pid1, SIGSTOP); // stoppa
  sleep(2);
  kill(pid1, SIGCONT); // riparte
  sleep(2);
  kill(pid1, SIGINT); // interrompe
  kill(pid2, SIGINT); // interrompe
  return 0;
}
