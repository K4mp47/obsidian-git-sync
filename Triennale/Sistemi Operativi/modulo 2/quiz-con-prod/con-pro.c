#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t mutex_mother_father; // male, mamma sto male

#define MAX 10

int buffer[MAX];

void *produttore(void *arg) {
  int i = 0;
  for (i = 0; i < MAX; i++) {
    sem_wait(&mutex_mother_father);
    printf("Hello, World!\n");
    sem_post(&mutex_mother_father);
    sleep(1);
  }
  return NULL;
}

void *consumatore(void *arg) {
  int i = 0;
  sem_wait(&mutex_mother_father);
  for (i = 0; i < MAX; i++) {
    printf("Hello, World!!!!!!!\n");
    sleep(1);
  }
  sem_post(&mutex_mother_father);
  return NULL;
}

int main() {
  // start a thread
  pthread_t thread[2];
  // che due coglioni gelati mi viene da piangere
  sem_init(&mutex_mother_father, 0, 1);
  pthread_create(&thread[0], NULL, produttore, NULL);
  pthread_create(&thread[1], NULL, consumatore, NULL);
  // wait for the thread to finish
  pthread_join(thread[0], NULL);
  pthread_join(thread[1], NULL);
  return 0;
}
// per favore non piangere, non ci rimanere male :)
