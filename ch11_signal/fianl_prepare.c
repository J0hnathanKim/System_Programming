#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

static pid_t child_pid = -1;

void alarm_handler(int sig)
{
    (void)sig;
    if (child_pid > 0) {
        kill(child_pid, SIGTERM);   // 자식 종료 요청
    }
}

int main(void)
{
    child_pid = fork();
    if (child_pid < 0) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {
        // Child: 1초마다 카운터 출력
        int i = 1;
        while (1) {
            printf("[Child] Counter: %d\n", i++);
            fflush(stdout);
            sleep(1);
        }
    } else {
        // Parent
        printf("[Parent] Child starts for 7 seconds\n");
        fflush(stdout);

        signal(SIGALRM, alarm_handler); // (권장: sigaction)
        alarm(7);                       // 7초 뒤 부모에게 SIGALRM

        // SIGALRM 오기 전까지 대기
        pause();

        // 자식 종료 기다리고 출력 후 부모도 종료
        waitpid(child_pid, NULL, 0);
        printf("[Parent] Child terminated\n");
        exit(0);
    }
}
