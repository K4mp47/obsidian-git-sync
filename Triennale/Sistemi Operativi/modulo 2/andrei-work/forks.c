#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    pid_t pid = fork();

    if(pid == 0)
    { //processo figlio
        printf("[FIGLIO]\t%d\n", pid);
    } else if(pid < 0)
    { //errore della fork
        perror("Errore nella fork\n");
        exit(EXIT_FAILURE);
    } else
    { //genitore
       printf("[GENITORE]\t%d\n", pid);
    }
 printf("[1]\t%d\n", pid);

    //questo codice verrà eseguito da tutti i processi
    printf("[1]\t%d\n", pid);
    printf("[2]\t%d\n", pid);

    //prima tutto il codice viene eseguito dal padre, poi viene
    //eseguito dal figlio
    return 0;
}