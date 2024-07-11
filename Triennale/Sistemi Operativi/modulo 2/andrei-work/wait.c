//
// Created by andreixmanu on 08/03/24.
//
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    pid_t pid = fork();
    int n;

    if(pid == 0)
    { //child process
        n = 1;
    } else
    { //parent process
        n = 6;
    }

   if(pid != 0) wait(NULL);

    for (int i = n; i < n + 5; i++) {
        printf("%d ", i);
        fflush(stdout);
    }

    printf("\n");

}