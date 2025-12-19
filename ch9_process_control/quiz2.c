#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void) {
    int n;

    printf("Input the number of child processes: ");
    if (scanf("%d", &n) != 1) {
        printf("Input error.\n");
        exit(1);
    }

    if (n <= 0) {
        printf("Wrong number. Input greater than 0.\n");
        exit(1);
    }

    // 조건 5: 동적할당으로 pid 배열 생성
    pid_t *pids = (pid_t *)malloc(sizeof(pid_t) * n);
    if (!pids) {
        perror("malloc");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid < 0) { // fork 실패
            perror("fork");
            // 이미 만든 자식들이 있을 수 있으니 정리
            for (int k = 0; k < i; k++) {
                // 필요시 kill 같은 정리 가능 (과제에선 보통 생략)
            }
            free(pids);
            exit(1);
        }

        if (pid == 0) { // child
            srand((unsigned int)getpid());
            int rand_sec = rand() % 5 + 1; // 1~5초

            printf("[Child %d] PID = %d, PPID = %d, random = %d -> sleep %d sec\n",
                   i + 1, (int)getpid(), (int)getppid(), rand_sec, rand_sec);

            sleep(rand_sec);
            _exit(0);
        }

        // parent: 자식 pid 저장 (조건 4,5의 핵심)
        pids[i] = pid;
    }

    printf("\nParent waiting for child processes...\n");

    // 조건 4: 자식이 전부 끝날 때까지 기다리면서, 종료되는 PID 출력
    int status;
    int finished = 0;
    while (finished < n) {
        pid_t terminated = wait(&status); // 종료된 자식 PID 리턴
        if (terminated > 0) {
            printf("Child process terminated: PID = %d\n", (int)terminated);
            finished++;
        } else {
            // wait()가 실패/더 이상 자식 없음
            break;
        }
    }

    printf("\nCreated Child PIDs: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", (int)pids[i]);
    }
    printf("\nParent [%d]: All child processes have finished.\n", (int)getpid());

    free(pids);
    return 0;
}
