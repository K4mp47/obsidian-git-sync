#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>

int i = 0;

void alarmHandler(int sig){
    if (i < 15)
    {
        std::cout << "Alarm triggered" << std::endl;
        alarm(3);
    }
    else
    {
        std::cout << "Alarm triggered, exiting" << std::endl;
    }
}

int main()
{
    sigset_t newHandler, oldHandler;
    
    sigemptyset(&newHandler);
    sigaddset(&newHandler, SIGINT);

    sigprocmask(SIG_BLOCK, &newHandler, &oldHandler);

    signal(SIGALRM, alarmHandler);
    alarm(3);
    while (1)
    {
        sleep(1);
        i++;
    }
}