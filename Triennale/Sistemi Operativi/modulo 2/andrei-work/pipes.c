//
// Created by andreixmanu on 09/03/24.
//

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int fd[2]; // file descriptor
    // fd[0] -> read
    // fd[1] -> write
    if(pipe(fd) == -1) perror("Pipe error\n");

    pid_t pid = fork();
    if(pid == 0)
    {
        close(fd[0]);
        int x;
        printf("Write the number: ");
        scanf(" %d", &x);
        write(fd[1], &x, sizeof(int));
        close(fd[1]);
    } else
    {
        close(fd[1]);
        int y;
        read(fd[0], &y, sizeof(int));
        close(fd[0]);
        printf("Value read: %d", y);
    }
    return 0;
}