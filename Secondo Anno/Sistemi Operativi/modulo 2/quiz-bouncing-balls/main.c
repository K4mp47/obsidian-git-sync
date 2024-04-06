#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

#define N_BALLS 20
#define X 20
#define Y 80
#define TICK 100000
#define DELAY TICK/N_BALLS * 2
#define BALL 'o'
#define BOUNCE '*'
#define CLEAR 40

// clears the terminal in a trivial way
char clear[CLEAR];

// Count ticks to test speed
int ticks=0;
int ball_tick[N_BALLS];

// This is the board
char board[X][Y];

// struct used to launch threads
struct info_r {
    int id;
    int x;
    int y;
    int dx;
    int dy;
} info_r;


/******* PARTE DA CONSEGNARE ********/

// dichiarazione dei semafori qui
sem_t mutex;
sem_t tick_sem;

void inizializza() {
    sem_init(&mutex, 0, 1); // Initialize mutex semaphore to 0
    sem_init(&tick_sem, 0, 0); // Initialize tick semaphore to 0
}

void inizia_mossa(int x, int y) {
    sem_wait(&tick_sem); // Wait for the tick to start the move
}

void fine_mossa(int x, int y) {
    sem_post(&mutex); // Signal the end of the move
}

void attendi_tick(int id) {
    sem_wait(&mutex); // Wait for the mutex to be released
}

void esegui_tick() {
    sem_post(&tick_sem); // Signal that a tick has occurred
}

void chiudi() {
    sem_destroy(&mutex); // Destroy mutex semaphore
    sem_destroy(&tick_sem); // Destroy tick semaphore
}
/******** FINE PARTE DA CONSEGNARE ********/

void die(char * s, int i) {
    printf("--> %s, thread numero %i\n",s,i);
    exit(1);
}


void print_board() {
    int x,y;
    printf("%s\n",clear);

    // esegue test di velocia' per vedere se ci sono palline troppo veloci o lente
    for (x=0;x<N_BALLS;x++) {
        if (ball_tick[x] > ticks)
            printf("Pallina %i troppo veloce! ball_tick=%i ticks=%i\n",x,ball_tick[x],ticks);
        if (ball_tick[x] < ticks)
            printf("Pallina %i troppo lenta! ball_tick=%i ticks=%i\n",x,ball_tick[x],ticks);
    }
    
    // stampa tutta la board
    for (x=0;x<X;x++) {
        for (y=0;y<Y;y++)
            printf("%c",board[x][y]);
        printf("\n");
    }
}

void *ball_code(void *i) {
    int mossa,nx,ny;
    struct info_r info = *(struct info_r *)i;
    int id = info.id;
    int x=info.x,y=info.y;
    int dx=info.dx,dy=info.dy;
    while (1) {
        // attende il tick
        attendi_tick(id);

        nx = x+dx;ny=y+dy;

        // si sincronizza
        inizia_mossa(nx,ny);

        /****************** esegue la mossa ********************/

        mossa = board[x+dx][y+dy];
        //printf("%c %i %i \n",mossa,x,y);
        if (mossa==' ') {
            board[x][y] = ' ';
            x = x+dx; y = y+dy;
            usleep(DELAY);
            if (board[x][y] != ' ') {
                printf("Balls overlap!\n");
                exit(1);
            }
            board[x][y] = BALL; // move!
            usleep(DELAY);
        } else {
            board[x][y] = BOUNCE;
            // wait next turn but changes directions
            if (mossa =='|')
                dy = -dy;
            else if (mossa =='-')
                dx = -dx;
            else {
                dx = -dx; dy=-dy;
            }
        }

        /*************** fine esecuzione mossa ***************/

        // per il test di velocita'
        ball_tick[id]++;

        fine_mossa(nx,ny);

    }
}

void *tick_code(void *i) {

    /**************** piccolo ritardo iniziale *************/
    usleep(TICK);
    
    while(1) {
        /***************** attende il prossimo tick ****************/
        usleep(TICK);

        /** stampa la board, le palline dovrebbero essersi mosse tutte! **/
        print_board();

        /**************** fa muovere le palline *******************/
        ticks++;
        esegui_tick();
    }
}


int posiziona(int x,int y,char c) {
    if (board[x][y] == ' ') {
        board[x][y] = c;
        return 1; // libera, prendi il posto
    } else
        return 0; // gia' occupata
}

int main() {
    pthread_t robots[N_BALLS];
    pthread_t you;
    int x,y,i,ret;
    struct info_r info[N_BALLS];
    struct info_r infop;

    srandom(time(NULL)); // initialize random seed

    for (x=0;x<CLEAR-1;x++)
        clear[x]='\n';
    clear[CLEAR-1]='\0';

    // reset board
    for (x=1;x<X-1;x++)
        for (y=1;y<Y-1;y++)
            board[x][y] = ' ';

    // mette gli angoli
    board[0][0]='+';
    board[X-1][0]='+';
    board[0][Y-1]='+';
    board[X-1][Y-1]='+';

    // mette i bordi
    for (y=1;y<Y-1;y++) {
        board[0][y]='-';
        board[X-1][y]='-';
    }
    for (x=1;x<X-1;x++) {
        board[x][0]='|';
        board[x][Y-1]='|';
    }

    // inizializza le strutture dati e i semafori
    inizializza();

    // crea i thread
    for (i=0;i<N_BALLS;i++) {
        info[i].id = i;
    // sceglie una nuova posizione libera
        do {
            info[i].x = random() % (X-2) + 1;
            info[i].y = random() % (Y-2) + 1;
            info[i].dx = random() % 3 - 1;
            do {
                info[i].dy = random() % 3 - 1;
            } while (info[i].dx == 0 && info[i].dy == 0);

        } while (!posiziona(info[i].x,info[i].y,BALL));

        if((ret=pthread_create(&robots[i],NULL,ball_code,(void *)&info[i])))
            die("errore create",ret);
    }

    printf("Create %i palline \n", N_BALLS);

    if ((ret=pthread_create(&you,NULL,tick_code,(void *)&infop)))
        die("errore create",ret);

    printf("Creato il timer \n");

    // attende la terminazione dei thread ... che non terminano mai!
    for (i=0;i<N_BALLS;i++)
        if((ret=pthread_join(robots[i], NULL)))
             die("errore join",ret);

    // distrugge i semafori
    chiudi();

}
