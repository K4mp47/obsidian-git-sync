/*
 * Campagnolo Alberto
 * Il codice implementa un array di semafori, uno per tipo di carattere.
 * Quando si prova ad entrare si controlla il carattere e ci si mette in coda
 * alla coda corrispondente.
 *
 * Il codice implementa anche un semaforo che controlla il numero di caratteri
 * in coda, così che quando sono usciti tutti e 10 le palline si passi a far 
 * entrare le palline nel semaforo successivo.
 *
 * */

#include <semaphore.h>

sem_t sem[4];
sem_t sem2; // semaforo per zona critica
int ind = 0; // indice per controllare il numero di palline uscite, 10.
int round_rob = 0; // indice per il cambio di semafori
char check[4] = {'O','-','+','1'}; // caratteri da controllare

void inizializza_sem(){ // default inizialization
  sem_init(&sem[0], 0, 10);
  sem_init(&sem[1], 0, 0);
  sem_init(&sem[2], 0, 0);
  sem_init(&sem[3], 0, 0);
  sem_init(&sem2, 0, 1);
}

void distruggi_sem(){ // distruggo i semafori
  sem_destroy(&sem[1]);
  sem_destroy(&sem[2]);
  sem_destroy(&sem[3]);
  sem_destroy(&sem[0]);
  sem_destroy(&sem2);
}

void entra_imbuto(char cb){
  for(int i=0; i<4;i++){
    if(cb == check[i]){
      sem_wait(&sem[i]); // semaforo per il carattere corrispondente
    }
  }
}

void esci_imbuto(){
  sem_wait(&sem2); // zona critica
  ind++;
  if(ind == 10){
    ind = 0;
    round_rob++; // variabile per il cambio di semaforo in ingresso
    if(round_rob == 4){
      round_rob = 0;
    }
    for(int i=0; i < 10; i++){
      sem_post(&sem[round_rob]); // apertura del semaforo per la prossima entrata
    }
  }
  sem_post(&sem2); // rilascio zona critica
}


