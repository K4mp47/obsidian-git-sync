//
// Created by andreixmanu on 11/03/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int size = 10;
    int array[size];
    srand(time(NULL));

    // populate array with random valyes
    for(int i = 0; i < size; i++)
        array[i] = rand() % 100;

    // open the pipe
    int fd = open("my_pipe", O_WRONLY);
    if(fd == -1) perror("Error opening fifo\n");

    // pass the array size to the other process
    write(fd, &size, sizeof(int));

    // pass every array value to the pipe
    for(int i = 0; i < size; i++)
        write(fd, &array[i], sizeof(int));

    return EXIT_SUCCESS;
}