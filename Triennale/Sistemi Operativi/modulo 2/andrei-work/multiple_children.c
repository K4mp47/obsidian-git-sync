//
// Created by andreixmanu on 11/03/24.
//

#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main(int argc, char* argv[]){

    pid_t pid = fork();

    if(pid == -1) perror("Fork error\n");

    if(pid == 0)
    { // child process -> create another child
        int child1_pid = getpid();
        printf("[CHILD 1] My PID: %d, my ppid: %d\n", child1_pid, getppid());

        pid_t pid2 = fork();
        if(pid2 == -1) perror("Fork2 error\n");

        if(getpid() == child1_pid)
            printf("[CHILD 1 POST FORK] My PID: %d, my ppid: %d\n", child1_pid, getppid());

        if(pid2 == 0) {
            int child2_pid = getpid();
            printf("[CHILD 2] My PID: %d, my ppid: %d\n", child2_pid, getppid());
        }
    } else
    { // main process
        int parent_pid = getpid();
        printf("[PARENT] My pid: %d\n", parent_pid);
        wait(NULL); // makes so it does not terminate until children processes
    }
    return 0;
}