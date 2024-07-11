#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>

#define DIMENSIONX 40
#define DIMENSIONY 20
#define LEAD "LEAD"
#define SNAKE_LENGTH 4
#define BUFDIM 400
#define SNAKE 'O'
#define SNAKEHEAD '@'
#define LEFT '<'
#define RIGHT '>'
#define MOVES 1000
#define N_SNAKES 5
#define DRAWTIME  50000
#define SNAKETIME 100000

extern void init_sem();
extern void destroy_sem();
extern void invia_char(int id, char c);
extern char leggi_char(int id);
extern void attendi_lettura(int id);
extern void fatta_lettura(int id);

char board[DIMENSIONX][DIMENSIONY];
int snake_x[N_SNAKES][SNAKE_LENGTH],snake_y[N_SNAKES][SNAKE_LENGTH];
char snake_str[N_SNAKES][SNAKE_LENGTH];
int directions_x[4] = {-1, 0, 1, 0};
int directions_y[4] = { 0,-1, 0, 1}; 
int ind_direction[N_SNAKES];
int n_round=MOVES;

void closeall() {
    exit(1);
}

// exits with error
void die(char * s, int e) {
    printf("%s [%i]\n",s,e);
    exit(1);
}

// clean the board
void cleanboard() {
    int i,j;
    for (i=0;i<DIMENSIONX;i++) 
        for (j=0;j<DIMENSIONY;j++){
            board[i][j] = ' ';
        }
}

void printboard() {
    int i,j;
    system("/usr/bin/clear");

    printf("+");
    for (j=0;j<DIMENSIONX;j++)
        printf("-");
    printf("+\n");
    for (i=0;i<DIMENSIONY;i++) {
    	printf("|");
        for (j=0;j<DIMENSIONX;j++){
        	printf("%c",board[j][i]);
        }
        printf("|\n");
    }
    printf("+");
    for (j=0;j<DIMENSIONX;j++)
        printf("-");
    printf("+\n");
    printf("Moves to go: %i\n",n_round);
}

long random_at_most(long max) {
  unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

  long x;
  // This is carefully written not to overflow
  while (num_rand - defect <= (unsigned long)(x = random()));

  // Truncated division is intentional
  return x/bin_size;
}

int drawonboard() {
    int i,j;
    for (j=0;j<N_SNAKES;j++) {
        for (i=0;i<SNAKE_LENGTH;i++) {
            if (board[snake_x[j][i]][snake_y[j][i]] != ' ')
                return 1;
            board[snake_x[j][i]][snake_y[j][i]] = snake_str[j][i];
        }
    }
    return 0;
}

int sumModuloNegative(int x, int y, int mod) {
    int result = (x+y) % mod;
    while (result < 0)
        result += mod;
    return result;
}

char movesnake(int s) {
    int i,tx,ty;
    n_round--;
    if (n_round==0) {
        for(i=0;i<N_SNAKES;i++) {
            invia_char(i,'#');
        }
        pthread_exit(NULL);
    }
    tx = sumModuloNegative(snake_x[s][0],directions_x[ind_direction[s]],DIMENSIONX);
    ty = sumModuloNegative(snake_y[s][0],directions_y[ind_direction[s]],DIMENSIONY);
    if (board[tx][ty] == ' ') {
        for (i=SNAKE_LENGTH-1;i>0;i--) {
            snake_x[s][i] = snake_x[s][i-1];
            snake_y[s][i] = snake_y[s][i-1];
        }
        snake_x[s][0] = tx;
        snake_y[s][0] = ty;
    }
    return board[tx][ty];
}

void display() {
    cleanboard();
    drawonboard();
    printboard();
}

void * snake(void *id) {
    int myid = *(int *)id;
    int i;
    char next;
    char tmp;

    while(1) {
        for (i=0; i < SNAKE_LENGTH; i++) {
            usleep(SNAKETIME*10);
            snake_str[myid][i] = leggi_char(myid);
            if (snake_str[myid][i] == '#')
                pthread_exit(NULL);
            fatta_lettura(myid);
            display();
        }

        while(1) {
            usleep(SNAKETIME);
            if (random_at_most(5) == 0) {
                if (random_at_most(1) == 0)
                    ind_direction[myid] = (ind_direction[myid]+1)%4;
                else
                    ind_direction[myid] = (ind_direction[myid]+3)%4;
            }
            next = movesnake(myid);
            display();
            if (next-48 >= 0 && next-48 < N_SNAKES)
                break;
        }
        next = next-48; // char to id

        for (i=0; i < SNAKE_LENGTH; i++) {
            tmp = snake_str[myid][i];
            snake_str[myid][i]=myid+48;
            invia_char(next,tmp);
            attendi_lettura(next);
        }
    }
    pthread_exit(NULL);
}

int main() {
	int i,j;
    int start;
    pthread_t tid[N_SNAKES];
    int snake_id[N_SNAKES];
    int err;

    if (strlen(LEAD) != SNAKE_LENGTH) {
        printf("LEAD length should match SNAKE_LENGTH\n");
        exit(1);
    }
    init_sem();

    signal(SIGINT,closeall);

    srandom(time(NULL));

    do {
        for (j=0;j<N_SNAKES;j++) {
            memset(snake_str[j],j+48,SNAKE_LENGTH);
            ind_direction[j] = random_at_most(3);
            if (ind_direction[j]>=4 || ind_direction[j]<0) {
                printf("valore di i errato: %i\n",ind_direction[j]);
                closeall();
            }

            snake_x[j][SNAKE_LENGTH-1] = random_at_most(DIMENSIONX-1);
            snake_y[j][SNAKE_LENGTH-1] = random_at_most(DIMENSIONY-1);

            for (i=SNAKE_LENGTH-2;i>=0;i--) {
                snake_x[j][i] = sumModuloNegative(snake_x[j][i+1],directions_x[ind_direction[j]],DIMENSIONX);
                snake_y[j][i] = sumModuloNegative(snake_y[j][i+1],directions_y[ind_direction[j]],DIMENSIONY);
            }
        }
        cleanboard();
    } while (drawonboard() == 1);


     for (i=0;i<N_SNAKES;i++) {
        snake_id[i] = i;
        if ((err=pthread_create(&tid[i],NULL,snake,(void *)&snake_id[i])))
            die("errore create",err);
    }
     
    start = random_at_most(N_SNAKES-1);
    // invia la stringa di partenza a un thread random
    for (i=0; i < SNAKE_LENGTH; i++) {
        display();
        invia_char(start,LEAD[i]);
        attendi_lettura(start);
    }

    for (i=0;i<N_SNAKES;i++){
        if ((err=pthread_join(tid[i],NULL)))
            die("errore join",err);
    }

    destroy_sem();

    return EXIT_SUCCESS;
}

