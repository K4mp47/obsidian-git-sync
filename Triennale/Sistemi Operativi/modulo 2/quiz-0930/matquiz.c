/*
 * Corso di Sistemi Operativi
 * Prima verifica: pipe
 *
 * Author: Riccardo Focardi
 *
 * Compilare con: gcc matquiz.c -o matquiz
 *
 * Per essere sicuri che le pipe siano create e aperte testare la soluzione con:
 * (sleep 1; ./soluzione) & ./matquiz -i /tmp/pipeIn -o /tmp/pipeOut
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <limits.h>

#define MAX  10000  // numero loop
#define SEED 144
#define MAXNUM 50   // valore massimo utilizzato
#define MAXBUF 1024 // buffer di lettura/scrittura

// Domanda
char *domanda = "Il tuo compito e' sommare (x+y) tra loro i seguenti numeri: x=%d,y=%d\n";

char *pipein=NULL,*pipeout=NULL; // pipe names
int fd0=0, fd1=1;   // stdin e stdout by default

int op(int x, int y) {
    return x+y;
}

void die() {
    close(fd0);
    close(fd1);
    unlink(pipein);
    unlink(pipeout);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int verbose=0;      // verbosity
    int i,j;            // indici
    int count=0;        // contatore
    int fd;             // fd temporaneo
    int c;              // char di parse linea comando
    int x,z,y;          // challenges
    char buffer[MAXBUF];// buffer di lettura/scrittura
    int res;            // response
    unsigned int flag=0;

    // se interrotto esce gracefully, cancellando le pipe
    signal(SIGINT,die);

    while ((c = getopt (argc, argv, "vhi:o:")) != -1) {
        switch (c)
          {
          case 'i':
          case 'o':
            if (c=='i')
                pipein=optarg;
            else
                pipeout=optarg;
            unlink(optarg);
            printf("[*] Creazione pipe '%c' %s\n",c,optarg);
            if(mkfifo(optarg,0600)<0) {
                perror("[ERRORE] creazione pipe");
                die();
            }
            printf("[*] Apertura pipe  '%c' %s\n",c,optarg);
            if ((fd = open(optarg,O_RDWR)) < 0) {
                perror("[ERRORE] apertura pipe");
                die();
            }
            if (c=='i')
                fd0=fd;
            else
                fd1=fd;
            break;
          case 'v':
            verbose=1;
            break;
          default:
            fprintf (stderr, "Utilizzo: %s [options]\n",argv[0]);
            fprintf (stderr, "options:\n");
            fprintf (stderr, "   -i pipeName: nome pipe input\n");
            fprintf (stderr, "   -o pipeName: nome pipe output\n");
            fprintf (stderr, "   -v:          modalita' verbosa\n");
            fprintf (stderr, "   -h:          questa schermata\n");
            die();
          }
    }

    srandom(SEED+1);    // inizializza la randomness (> 0)

    // loop principale
    for (i=0;i<MAX;i++){
        y = (int) (random()%(MAXNUM-1) + 1);
        z = (int) (random()%(MAXNUM-1) + 1);
        x = y*z;

        if(verbose) {
            printf("[VERBOSO] x=%d, y=%d\n",x,y);
        }

        if (snprintf(buffer,MAXBUF,domanda,x,y)>=MAXBUF) {
            printf("Buffer di scrittura insufficiente!\n");
            die();
        }

        write(fd1,buffer,strlen(buffer));

        if(verbose) {
            if (fd1 == 1) printf("\n");
            printf("[VERBOSO] ho inviato '%s'\n",buffer);
        }

        j=0;
        while(j < MAXBUF-1 && read(fd0,&buffer[j],1) && buffer[j]!='\n') {
            if (buffer[j]<'0' || buffer[j]>'9') {
                printf("Ho letto un carattere che non corrisponde a una cifra decimale '%c'\n!",buffer[j]);
                die();
            }
            j++;
            flag=(flag+(int)buffer[j]+(int)buffer[j-1])%16777216;
        }
        if (j==MAXBUF-1) {
            printf("Buffer di lettura insufficiente! Hai messo il '\\n'??\n");
            die();
        } else if (buffer[j]!='\n') {
            printf("Pipe di lettura chiusa!\n");
            die();
        } else if (j==0) {
            printf("Input vuoto (solo newline!)\n");
            die();
        }

        buffer[j]='\0'; // termina la stringa
        res = atoi(buffer);

        if(verbose) {
            if (fd1 == 1) printf("\n");
            printf("[VERBOSO] ho letto '%s' = %d\n",buffer,res);
        }

        if (res != op(x,y)) {
            printf("[ERRORE] Risultato errato: %d invece che %d!\n",res,op(x,y));
            die();
        }
    }

    printf("[*] Congratulazioni! Hai superato il matquiz! flag=%06x\n",flag);
    close(fd0);
    close(fd1);
    unlink(pipein);
    unlink(pipeout);
    exit(EXIT_SUCCESS);
}
