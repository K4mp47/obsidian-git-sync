//
// Created by andreixmanu on 09/03/24.
//

#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char* argv[])
{
    int array[] = { 1, 2, 3, 4, 5, 6};
    int start, end;
    int arraySize = sizeof(array) / sizeof(int);

    // create the pipe
    int fd[2];
    pipe(fd);

    // create the child process
    pid_t pid = fork();
    if(pid < 0) perror("Error creating child process\n");

    if(pid == 0)
    { // child process -> read first half array
        start = 0;
        end = arraySize/2;
    }
    else
    { // parent process -> read second half array
        start = arraySize/2;
        end = arraySize;
    }

    int sum = 0;
    for(int i = start; i < end; i++)
        sum += array[i];
    printf("Calculated partial sum: %d\n", sum);

    if(pid == 0)
    { // child process
        write(fd[1], &sum, sizeof(sum));
        close(fd[0]);
        close(fd[1]);
    } else
    { // parent process
        wait(NULL);
        int tmp;
        read(fd[0], &tmp, sizeof(int));
        int total_sum = tmp + sum;
        printf("Total sum: %d\n", total_sum);
        close(fd[0]);
        close(fd[1]);
    }

}