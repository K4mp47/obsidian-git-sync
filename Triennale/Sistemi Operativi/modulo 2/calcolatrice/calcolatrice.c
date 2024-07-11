#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
 
#define PIPE_IN "calcPipeIn"
#define PIPE_OUT "calcPipeOut"
#define MAXEXP 100
#define NT 6
#define DEBUG 1
 
die(char * s) {
    perror(s);
    exit(1);
}
 
// output abilitato se DEBUG == 1
void d_print(char *s, ...) {
    va_list ap;
 
    if (DEBUG) {  
        va_start(ap, s);
        vprintf(s,ap);
        va_end(ap); 
    }    
}
 
main() {
    int pin,pout,nums,n,i,j,k,r,fail=false,rread;
    char sn[MAXEXP],ris[MAXEXP];
 
    // apre le pipe
    if( ( pin=open(PIPE_IN,O_RDWR) ) < 0 ||  ( pout=open(PIPE_OUT,O_RDWR | O_NONBLOCK) ) < 0 )
        die("Errore apertura pipe");
 
    srand(time(NULL)); // inizializza il generatore random
 
    d_print("=== INIZIO TEST ===\n");
     
    // genera NT espressioni le invia e controlla il risultato ricevuto
    for(i=0;i<NT;i++) {
        r=0; // azzera la somma (per il test)
 
        nums = (int) ((float)rand() / RAND_MAX * 9) + 1; // lunghezza espressione
         
        d_print("Espressione %i composta da %i numeri: ",i,nums);
         
        // genera i nums numeri e li invia come stringhe separati da +
        // l'ultimo numero e' terminato con #
        for(j=0;j<nums;j++) {
            // sceglie un numero a caso
            n = (int) ((float)rand() / RAND_MAX * 100);
            d_print("%i ",n);
            r += n; // aggiorna la somma (per il test successivo)
            sprintf(sn,"%i",n); // crea la stringa
            write(pin,sn,strlen(sn)); // la invia sulla pipe
            if (j==nums-1) // e' l'ultimo numero?
                write(pin,"#",1); // termina l'espressione
            else
                write(pin,"+",1); // aggiunge il simbolo +
        }
        d_print("\n  somma: %i",r);
         
        // controlliamo il risultato dalla pipe
        d_print("\n  leggo dalla pipe ... :"); fflush(stdout);
        k=0;
        
        write(pout,"ciao",4);
        // leggo un risultato. La lettura e' non bloccante (vedi la open)
        while(k<MAXEXP-1 && (rread=read(pout,&ris[k],1))>0 && ris[k] != '#') k++;
         
        // se per caso non ha letto nulla ritenta dopo un secondo
        if (rread < 0 && errno ==EAGAIN) {
            sleep(1);
            while(k<MAXEXP-1 && (rread=read(pout,&ris[k],1))>0 && ris[k] != '#') k++;
        }          
            
         
        if (rread < 0 && errno ==EAGAIN) {
            // anche al secondo tentativo non ho letto nulla
            d_print("FAIL! timeout\n");
            fail = true;  
        } else if (atoi(ris) == r) 
            // ho letto la somma corretta
            d_print("OK\n");
        else {
            // ho letto un valore errato, stampo la stringa letta dalla pipe
            ris[k+1] ='\0';
            d_print("FAIL! Ho letto %s\n",ris);
            fail = true;               
        }
    }    
     
    if (fail) {
        d_print("=== TEST FALLITO ===\n");
        exit(1);
    }else{
        d_print("=== TEST SUPERATO ===\n");
        exit(0);
    }
}
