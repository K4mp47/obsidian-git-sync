#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

sem_t sem;

void *thread_code(void *a)
{
    sem_wait(&sem);
    std::cout << "Thread ID: " << pthread_self() << "\n Del processo: " << getpid() << std::endl;
    // power of two to number in a variable
    for(int i=0; i < 10; i++)
      *((int *)a) = *((int *)a) + 1; // number equal to what a is pointing, after int casting
    sem_post(&sem);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    sem_init(&sem, 0, 1);
    int num = atoi(argv[1]);
    
    pthread_t tid[2];

    for (int i = 0; i < 2; i++)
    {
        pthread_create(&tid[i], NULL, thread_code, (void *)&num); // puntatore viene castato da int * a void * and start thread
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_join(tid[i], NULL); // wait thread
    }

    std::cout << "Result: " << num << std::endl; // print the result
}