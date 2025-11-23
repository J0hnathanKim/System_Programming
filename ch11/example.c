#include <stdio.h>      
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void userHandler(int sig){
    printf("SIGUSR1 received signal number: %d\n", sig);
}

int main(){
    pid_t pid;

    pid = fork();

    if(pid == 0){
        signal(SIGUSR1, userHandler);
        printf("Child PID %d - waiting for parent's signal...\n", getpid());
        while(1)
            pause();
    }
    else{
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
        sleep(2);
        printf("Parent: sending SIGUSR1 signal to child\n");
        kill(pid, SIGUSR1);
        sleep(1);
        printf("Parent: terminating child process (SIGTERM)\n");
        kill(pid, SIGTERM);
    }
    return 0;
}
