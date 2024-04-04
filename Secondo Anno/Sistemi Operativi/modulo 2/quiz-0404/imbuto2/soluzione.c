/*
 * Corso di Sistemi Operativi 2020
 * Schema soluzione seconda verifica: semafori
 *
 * Author: Riccardo Focardi
 */
#include <semaphore.h>
//
// int sem_wait(sem_t *sem) esegue una P(sem);
// int sem_post(sem_t *sem) esegue una V(sem);
// int sem_getvalue(sem_t *sem, int *val) legge il valore del semaforo e lo copia in val;
// ATTENZIONE: in alcune implementazioni il semaforo rosso è 0, in altre è negativo (e indica il numero di processi in attesa);
// sem_destroy(sem_t *sem) elimina il semaforo. Da NON usare se ci sono processi in attesa sul semaforo (comportamento non specificato).
sem_t sinc, mutex;
int max;
int c = 0;
// dichiarazione semafori e variabili globali
// inizializza semafori e variabili
// ATTENZIONE dim è la dimensione del gruppo che deve entrare
// nell'imbuto.
void inizializza_sem(int dim) {
  sem_init(&sinc,0,dim);
  max = dim;
  sem_init(&mutex,0,1);
}
 
// distruggi i semafori
void distruggi_sem() {
  sem_destroy(&sinc);
  sem_destroy(&mutex);
}
 
// attende di entrare nell'imbuto
void entra_imbuto() {
  sem_wait(&sinc);
}
 
// esce dall'imbuto
// ATTENZIONE usare una variabile intera condivisa per sapere 
// quante palline sono uscite (da proteggere con una sezione critica)!
void esci_imbuto() {
  sem_wait(&mutex);
  c++;
  sem_post(&mutex);
  if(c == max) {
    for(int i = 0; i < max; i++) {
      sem_post(&sinc);
    }
    c = 0;
  }
}

