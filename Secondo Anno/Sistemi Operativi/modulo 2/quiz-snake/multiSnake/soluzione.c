// variabili globali e semafori qui
#include <semaphore.h>

sem_t pieno[5],vuoto[5];
char buffer[5];
// invocato all'inizio dal thread principale prima di creare gli snake
void init_sem() {
  int i;
  for (i=0;i<5;i++)
    sem_init(&vuoto[i], 0, 1);

  for (i=0;i<5;i++)
    sem_init(&pieno[i], 0, 0);
}

// invocato dal thread prima della terminazione del programma
void destroy_sem() {
  for(int i=0; i < 5; i++){
    sem_destroy(&pieno[i]);
    sem_destroy(&vuoto[i]);
  }
}

// invia un carattere al thread id
void invia_char(int id, char c) {
  buffer[id] = c;
  sem_post(&pieno[id]);
}

// il thread id legge un carattere (bloccante se il carattere non è stato inviato)
char leggi_char(int id) {
  sem_wait(&pieno[id]);
  return buffer[id];
}

// attende che il thread id abbia letto
void attendi_lettura(int id) {
  sem_wait(&vuoto[id]);
}

// il thread id segnala che la lettura è avvenuta
void fatta_lettura(int id) {
  sem_post(&vuoto[id]);
}
