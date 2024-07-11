/*
 * Corso di Sistemi Operativi
 * Seconda verifica: semafori
 *
 * Author: Riccardo Focardi
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

extern void inizializza_sem();
extern void distruggi_sem();
extern void entra_imbuto(char cb);
extern void esci_imbuto();

#define X 40        // dimensione griglia X
#define Y (X-2)/2   // dimensione griglia Y
#define N 10    
#define SLEEP_REFRESH 100000    // temporizzazione refresh

#ifdef FAST       // velocita' maggiore
#define SLEEP_BALL 1000    // temporizzzione palline
#define TEST__N_BALLS 400    // totale thread pallina
#else
#define SLEEP_BALL 100000   // temporizzzione palline
#define TEST__N_BALLS 400   // totale thread pallina
#endif

char TEST__table[X][Y];   // griglia
sem_t TEST__mutex_table[X][Y],TEST__mymutex; // semafori ad uso interno
int TEST__n_balls=0;      // numero di palline nell'imbuto in un certo istante
int TEST__n_balls_id=0;      // id palline nell'imbuto in un certo istante
int TEST__n_balls_tot=0;  // numero di palline totali che sono entrate
int TEST__goingup=1;      // se il numero sale o scende
int TEST__turn=0;        // di quale pallina è il turno
int TEST__flag=0;
int TEST__turn_count=1;
char TEST__tipi[]={'O','-','+','1'}; 

// uscita in caso di errore
void die(char * s, int e) {
    printf("%s [%i]\n",s,e);
    exit(1);
}

// Stampa la griglia sullo schermo
void stampa_griglia() {
    int i,j;

    printf("\e[1;1H\e[2J"); // cancella
    for (i=0;i<Y;i++) {
        for (j=0;j<X;j++) {
            printf("%c",TEST__table[j][i]); // stampa l'elemento j,i
        }
        printf("\n");
    }
    // Dati sulle palline
    printf("\nPalline nell'imbuto: %d/%d (processate: %d/%d)\nTurno: %c\n",TEST__n_balls,N,TEST__n_balls_tot,TEST__N_BALLS,TEST__tipi[TEST__turn]);

}

// Inizializza la griglia con la forma di un imbuto
void init_imbuto() {
    int i,j;

    for (i=0;i<Y;i++) {
        for (j=0;j<X;j++) {
            // inizializza il mutex per lo spostamento sulla griglia
            sem_init(&TEST__mutex_table[j][i],0,1); 
            if (i<Y-1) {
                if (i==j) {
                    TEST__table[j][i]='\\';
                } else if (X-i-2==j) {
                    TEST__table[j][i]='/';
                } else {
                    TEST__table[j][i]=' ';
                }
            } else {
                if (j==X/2 || j==X/2-2)
                    TEST__table[j][i]='|';
                else
                    TEST__table[j][i]=' ';
            }
        }
    }
}

// Random da 0 a max
long random_at_most(long max) {
  unsigned long
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

  long x;
  while (num_rand - defect <= (unsigned long)(x = random()));
  return x/bin_size;
}

// Thread pallina
void * pallina(void * c_ball) {
    char cb = *(char *)c_ball; // carattere grafico
    int x,y=0,nx,ny,dx;
    int myid=0;

    x = random_at_most(X-4)+1;

    entra_imbuto(cb); // Attende di entrare nell'imbuto

    // Statistiche di debug
    sem_wait(&TEST__mymutex);
    if (TEST__tipi[TEST__turn]!=cb) {
        stampa_griglia();
        printf("[ERRORE] Le pallina dovrebbe essere %c e non %c\n",TEST__tipi[TEST__turn],cb);
        exit(1);
    }
    if (!TEST__goingup) {
        stampa_griglia();
        printf("[ERRORE] Le palline non dovrebbero entrare ma uscire\n");
        exit(1);
    }
    TEST__n_balls++;      // pallina entra
    myid = TEST__n_balls_id++;      // id pallina entra
    TEST__n_balls_tot++;  // pallina entra
    if (TEST__n_balls==N) {
        TEST__goingup = 0; // ora di scendere!
    }
    sem_post(&TEST__mymutex);

    // Entra nell'imbuto
    sem_wait(&TEST__mutex_table[x][y]);
    TEST__table[x][y] = cb; 

    // Finché non arriva in fondo:
    while(y<Y) {
        usleep(SLEEP_BALL+random_at_most(SLEEP_BALL/100));
        ny = y+1;
        nx = x;
        dx = x+(x<X/2-1 ? 1 : (x==X/2-1 ? 0 : -1)); // spostamento "naturale" verso il centro
        if (TEST__table[x][ny] == '\\' || TEST__table[x][ny] == '/' || TEST__table[x][ny] == '|') {nx = dx; // si sposta verso il centro 
            // se occupato resta alla stessa altezza
            if (TEST__table[dx][ny] != ' ') ny=y;
        }
        else if (TEST__table[x][ny] != ' ') { // se occupato da altra pallina
            if (TEST__table[dx][ny] == ' ') nx = dx; // si sposta verso il centro
            else if (TEST__table[dx][y] == ' ') {    // resta alla stessa altezza
                nx = dx; ny = y;
            }
        } 

        // condizioni che non devono mai avverarsi:
        if (nx<ny) {
            printf("out of bound! (non deve succedere) %d %d -> %d %d (%d %d)\n",x,y,nx,ny,X,Y);
            exit(1);
        }
        if (nx > X || ny > Y || nx < 0 || ny < 0) {
            printf("overflow (non deve succedere) %d %d\n",nx,ny);
            exit(1);
        }

        // Se ancora sulla griglia occupa la nuova posizione
        if(ny<Y) {
            sem_wait(&TEST__mutex_table[nx][ny]);
            TEST__table[nx][ny] = cb;
        }
        // Libera la vecchia posizione
        TEST__table[x][y] = ' ';
        sem_post(&TEST__mutex_table[x][y]);

        x=nx;y=ny;
    }

    // Statistiche di debug
    sem_wait(&TEST__mymutex);
#ifndef FASTER       // stresstest tante palline 0 sleep!
    if (TEST__goingup) {
        stampa_griglia();
        printf("[ERRORE] Le palline non dovrebbero uscire ma entrare\n");
        exit(1);
    }
#endif
    TEST__n_balls--; // pallina esce
    TEST__flag=(TEST__flag+((int)cb)*myid*TEST__turn_count)%16777216;
    if (TEST__n_balls==0) {
        TEST__goingup = 1; // e' ora di entrare!
        TEST__turn = (TEST__turn+1)%sizeof(TEST__tipi);
        TEST__n_balls_id=0;
        TEST__turn_count++;
    }
    sem_post(&TEST__mymutex);
    esci_imbuto();

    return NULL;
}

// Thread separato che fa il refresh della griglia e controlla che non 
// ci siano troppe palline nell'imbuto
void * refresh(void * id) {
    while(1) {
        sem_wait(&TEST__mymutex);
        stampa_griglia();
        if (TEST__n_balls > N) {
            printf("[ERRORE] Ci sono %d palline nell'imbuto. Dovrebbero essere al massimo %d\n",TEST__n_balls,N);
            exit(1);
        }
        sem_post(&TEST__mymutex);

        usleep(SLEEP_REFRESH);
    }
}

int main() {
    pthread_t tid[TEST__N_BALLS+1];
    int err,i;
    int n_palline=0;
    char cb[TEST__N_BALLS+1];

    inizializza_sem(); // inizializza i semafori

    sem_init(&TEST__mymutex,0,1); // mutex per debug

    srandom(time(NULL));

    init_imbuto(); // inizializza l'imbuto
    
    if (TEST__N_BALLS/sizeof(TEST__tipi)*sizeof(TEST__tipi) != TEST__N_BALLS) {
        die("TEST__N_BALLS non si divide per i TEST__tipi",1);
    }

    // Crea TEST__N_BALLS thread "pallina" dei vari TEST__tipi

    for (i=0;i<TEST__N_BALLS;i++) {
        cb[i] = TEST__tipi[i*sizeof(TEST__tipi)/TEST__N_BALLS];
        if((err=pthread_create(&tid[i],NULL,pallina,&cb[i]))) {
            die("errore create",err);
        }
    }
    // Crea il thread "refresh"
    if((err=pthread_create(&tid[i],NULL,refresh,NULL))) {
        die("errore create",err);
    }   

    // Attende i thread pallina
    for (i=0;i<TEST__N_BALLS;i++) {
        if((err=pthread_join(tid[i],NULL))) {
            die("errore join",err);
        }
    }

    // Esce
    stampa_griglia();
    distruggi_sem();
    printf("Tutte le palline sono transitate! flag=%06x\n",TEST__flag);
    exit(0);

}
