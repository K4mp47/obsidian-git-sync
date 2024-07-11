#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

// Campagnolo Alberto
// Soluzione macchinosa ma semplice
// passo i caratteri fino al caratter :, da qui faccio le prima tre read per togliere ' x='
// leggo il numero fino a che non trovo , e ripeto due letture per saltare 'y=', infine scrivo
// la somma in una stringa dopo averla trovata trasformando le stringhe in int con atoi
// flag=414f6c
 

int main(){
  char * pipein = "/tmp/pipeIn";
  char * pipeout = "/tmp/pipeOut";

  // leggi dalla pipeOut un carattere alla volta usando pipeIn
  int fd = open(pipeout, O_RDONLY);
  int fd1 = open(pipein, O_WRONLY);
  char c; // variabile per salvare il carattere
  int index; // index per le stringhe
  char num1[20]; // primo numero
  char num2[20]; // secondo numero
  char strsum[20]; // somma
  while(1){
    while(c != ':'){
      read(fd, &c, 1);
    }
    // passo ' x='
    read(fd, &c, 1);
    read(fd, &c, 1);
    read(fd, &c, 1);
    // setto a zero le stringhe
    memset(num1, 0, 20); 
    memset(num2, 0, 20);
    memset(strsum, 0, 20);
    index = 0;
    while(c != ','){
      read(fd, &c, 1);
      num1[index] = c;
      index++;
    }
    // passo 'y='
    read(fd, &c, 1);
    read(fd, &c, 1);
    index = 0; // riazzero per il secondo numero
    while(c != '\n'){
      read(fd, &c, 1);
      num2[index] = c;
      index++;
    }
    
    // sommo 
    int num1Int = atoi(num1);
    int num2Int = atoi(num2);
    int sum = num1Int + num2Int;
    // converto in string e invio il risultato
    sprintf(strsum, "%d\n", sum);
    //printf("%d", num1Int);
    //printf("%d", num2Int);
    //printf("%s\n", strsum);
    write(fd1, &strsum, strlen(strsum));
  }
  close(fd);
  close(fd1);
  return 0;
}
