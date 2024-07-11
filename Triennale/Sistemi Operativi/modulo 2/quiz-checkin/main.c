#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <semaphore.h>
#include <stdint.h>
#include <stdbool.h>
 
#define N 100  // Numero di viaggiatori
#define CIN 10  // Numero postazioni di check-int
 
/*********** variabili per il testing ************/
    int check_postazione[CIN];
    sem_t check_mutuo;
/*************************************************/
 
void * viaggiatore(void * i);
 
void die(char * s, int i) {
    printf("--> %s numero %i\n",s,i);
    exit(1);
    }
 
 
/*********** parte da consegnare ****************/
 
// dichiarazione di variabili globali
 
// funzioni del main
sem_t check[CIN], mutex;

int postazioni[CIN] = {0,0,0,0,0,0,0,0,0,0};

void inizializza() { 
  sem_init(&mutex, 0, 1);
  for(int i = 0; i < CIN; i++) {
    sem_init(&check[i], 0, 1);
  }
}
  
void chiudi() {
  for(int i = 0; i < CIN; i++) {
    sem_destroy(&check[i]);
  }
}
 
// funzioni del viaggiatore
int attendi_postazione() {
  // accedi ad un determinato semaforo solo se il valore in postazione è true
  sem_wait(&mutex);
  int i;
  for(i = 0; i < CIN; i++) {
    if(postazioni[i] == 0) {
      sem_wait(&check[i]);
      postazioni[i] = 1;
      sem_post(&mutex);
      break;
    }
  }
  return i;
}
 
void libera_postazione(int j) {
  postazioni[j] = 0;
  sem_post(&check[j]);
}
/*********fine parte da consegnare **************/
 
 
void * viaggiatore(void * i) {
    int j;
    intptr_t id = (intptr_t)i;
 
    printf("[Viaggiatore %d] Entro in aeroporto\n", (int) id);
 
    j = attendi_postazione();
     
    /************** testing ***************/
        sem_wait(&check_mutuo);
        if (check_postazione[j]==1) {
            die("postazione gia' occupata",j);
        }
        check_postazione[j]=1;
        sem_post(&check_mutuo);
    /**************************************/
     
    printf("[Viaggiatore %d] Sto usando lo sportello %d \n", (int) id, j);
     
    /*************** testing **************/
        sleep(1);
        check_postazione[j]=-1;
    /**************************************/
 
    libera_postazione(j);
         
     
    printf("[Viaggiatore %d] Vado al gate! \n", (int) id);
                     
}
 
int main() {
    pthread_t th[N];
    int i;
 
    sem_init(&check_mutuo,0,1);
         
    for (i=0; i<CIN; i++)
        check_postazione[i] = 0;
         
    // inizializza le strutture dati e i semafori
    inizializza();
 
    // crea i thread viaggiatori    
    intptr_t a;
    int err;
 
    for (a=0;a<N;a++)
        if(err=pthread_create(&th[a],NULL,viaggiatore,(void *) a)) 
            die("errore create", err);
     
    printf("Creati %i viaggiatori \n", N);
 
    // attende la terminazione dei thread viaggiatori
    intptr_t b;
    int ret;
 
    for (b=0;b<N;b++)
        if(ret=pthread_join(th[b], NULL))
             die("errore join",ret);
    
    // distrugge i semafori 
    chiudi();
     
    /********************* testing *******************/
        for (i=0; i<CIN; i++) {
            if (check_postazione[i] == 0)
                die("postazione mai utilizzata",i);
        }
    /*************************************************/
}
