//
// Created by andreixmanu on 11/03/24.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define FIFO_NAME "myFifo"

int main(int argc, char* argv[])
{
    if (mkfifo(FIFO_NAME, 0777) == -1) // creates a pipe file in the filesystem
    {
        if (errno == EEXIST) printf("FIFO '%s' already exists.\n", FIFO_NAME);
        else
        {
            perror("Fifo creation error\n");
            return 1;
        }
    }
    else printf("FIFO '%s' created successfully.\n", FIFO_NAME);

    int fd = open(FIFO_NAME, O_RDONLY); //

    /* program waits here for a process that reads the pipe
    * use parameter "O_RDWR" to both read and write
    * use command "cat" on the created fifo to read the fifo, and unlock the execution
    * also use "O_RDONLY" to only read the pipe file
    */

    int x = 97;
    if(write(fd, &x, sizeof(x)) == -1) perror("Write error\n");
    close(fd);

    return 0;
}
