#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void *thread_code(void *a)
{
    std::cout << "Thread ID: " << pthread_self() << "\n Del processo: " << getpid() << std::endl;
    // power of two to number in a variable
    int num = *((int *)a); // number equal to what a is pointing, after int casting
    int result = num * num;
    // save it in a
    *((int *)a) = result; // save the result in the variable a is pointing to
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{

    int num[2];
    num[0] = atoi(argv[1]);
    num[1] = atoi(argv[2]);

    pthread_t tid[2];

    for (int i = 0; i < 2; i++)
    {
        pthread_create(&tid[i], NULL, thread_code, (void *)&num[i]); // puntatore viene castato da int * a void * and start thread
        sleep(1);
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_join(tid[i], NULL); // wait thread
    }

    std::cout << "Result: " << num[0] + num[1] << std::endl; // print the result
}