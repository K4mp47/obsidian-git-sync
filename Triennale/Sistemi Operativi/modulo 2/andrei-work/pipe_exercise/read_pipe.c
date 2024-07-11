//
// Created by andreixmanu on 11/03/24.
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    // open the pipe
    int fd = open("my_pipe", O_RDONLY);
    if(fd == -1) perror("Error opening fifo\n");

    // read the array size from the pipe
    int size;
    read(fd, &size, sizeof(int));

    // initialize array
    int array[size];

    // place the values in the array
    for(int i = 0; i < size; i++)
        read(fd, &array[i], sizeof(int));

    // print the array
    for(int i = 0; i < size; i++)
        printf("%d\n", array[i]);

    return EXIT_SUCCESS;
}