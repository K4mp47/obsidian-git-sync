#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/*
void alarmHandler(int sig) {
  printf("Alarm!\n");
  alarm(3);
}

int main() {
  signal(SIGALRM, alarmHandler); 
  alarm(14);
  while (1){};
  return 0;
}

*/ 

int main() {
  void (*old)(int);

  old = signal(SIGINT, SIG_IGN);
  printf("Sono protetto!\n");

  sleep(3);

  signal(SIGINT, old);
  printf("Non sono protetto!\n"); 
  sleep(3);
  return 0;
}
