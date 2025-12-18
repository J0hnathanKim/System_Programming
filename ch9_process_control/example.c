#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int number;
    printf("Input the number of child processes: ");
    scanf("%d", &number);

    if (number <= 0) {
        printf("Wrong input. Input a number greater than 0\n");
        exit(0);
    }

    int *pid = (int *)malloc(sizeof(int) * number);
    if (pid == NULL) {
        perror("malloc");
        exit(1);
    }

    for (int i = 0; i < number; i++) {
        pid[i] = fork();

        if (pid[i] < 0) {
            perror("fork");
            exit(1);
        }

        if (pid[i] == 0) {
            
            printf("I am %dth child. PID = %d, Parent PID = %d\n",
                   i + 1, getpid(), getppid());
            exit(0);   
        }
        
    }

    
    while (wait(NULL) > 0);

    printf("[Parent %d] All children have terminated\n", getpid());

    
    printf("Childs Pid : ");
    for (int i = 0; i < number; i++) {
        printf("%d ", pid[i]);
    }
    printf("\n");

    free(pid);
    return 0;
}
