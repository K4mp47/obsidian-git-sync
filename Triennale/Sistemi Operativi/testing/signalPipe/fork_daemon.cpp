#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
    int pid, status;
    pid = fork();
    if(pid == 0){
        pid_t pid2, status2;
        std::cout << "Child process" << std::endl;
        pid2 = fork();
        if(pid2 == 0){
            int *tmp = 0;
            int a;
            std::cout << "Child process 2" << std::endl;
            sleep(5);
            a = *tmp;
        }
        pid2 = wait(&status2);
        if(WIFSIGNALED(pid2)){
            std::cout << "Child process 2 exited with signal " << WTERMSIG(status2) << std::endl;
        }
        sleep(5);
        exit(42);
    } else {
        pid = wait(&status);
        if(WIFEXITED(status))
            std::cout << "Child process exited with status " << WEXITSTATUS(status) << std::endl;
        std::cout << "Parent process" << std::endl;
    }
}