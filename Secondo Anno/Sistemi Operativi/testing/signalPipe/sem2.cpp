#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

sem_t sem_s, sem_l;
int num_lettori = 0;
int value = 1;
int fermo = 0;

std::string messaggio = "";

void *scrittura_code(void *a)
{
    while(1){
        sem_wait(&sem_s);
        std::cout << "Inserisci messaggio: ";
        std::getline(std::cin, messaggio);
        std::cout << "Messaggio stampato" << std::endl;
        sem_getvalue(&sem_s, &value);
        std::cout << "Valore semaforo: " << value << std::endl;
        sem_post(&sem_s);

        sleep(1); // per dare tempo ai lettori di agire
    }
}

void *lettura_code(void * a)
{
    while(1){
        sem_wait(&sem_l);
        num_lettori++;
        if(num_lettori == 1){
            sem_wait(&sem_s);
        }
        std::cout << "Lettore: " << pthread_self() << std::endl;
        // legge il messaggio
        std::cout << "Messaggio: " << messaggio << std::endl;
        sem_post(&sem_l);

        sem_wait(&sem_l);
        num_lettori--;
        if(num_lettori == 0){
            sem_post(&sem_s);
        }
        sem_post(&sem_l);

        sleep(1); // per dare tempo allo scrittore di agire
    }
}

int main(int argc, char *argv[])
{
    sem_init(&sem_s, 0, 1);
    // inizialize sem_l
    sem_init(&sem_l, 0, 1);

    pthread_t tid[10];

    pthread_create(&tid[0], NULL, scrittura_code, NULL); // puntatore viene castato da int * a void * and start thread
    sleep(1);

    for (int i = 1; i < 10; i++)
    {
        pthread_create(&tid[i], NULL, lettura_code, NULL); // puntatore viene castato da int * a void * and start thread
    }

    for (int i = 0; i < 10; i++)
    {
        pthread_join(tid[i], NULL); // wait thread
    }

    std::cout << "lettura finita: " << std::endl; // print the result
}