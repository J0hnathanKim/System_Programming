#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>


#define PIPE_12 "pipe_12"
#define PIPE_21 "pipe_21"
#define MAXLINE 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [1|2]\n", argv[0]);
        exit(1);
    }

    int mode = atoi(argv[1]);
    char *read_pipe;
    char *write_pipe;
    char *name;

    mkfifo(PIPE_12, 0660);
    mkfifo(PIPE_21, 0660);

    if (mode == 1) {
        printf("[Mode 1] Started.\n");
        name = "DUPLEX-1";
        read_pipe = PIPE_21;   // 2 -> 1
        write_pipe = PIPE_12;  // 1 -> 2
    } else if (mode == 2){
        printf("[Mode 2] Started.\n");
        name = "DUPLEX-2";
        read_pipe = PIPE_12;
        write_pipe = PIPE_21;
    } else{
        printf("Mode must be 1 or 2\n");
        exit(1);
    }

    int fd_r = open(read_pipe, O_RDWR);
    int fd_w = open(write_pipe, O_RDWR);

    if(fd_r < 0 || fd_w < 0){
        perror("open");
        exit(1);
    }

    pid_t pid = fork();

    if(pid < 0){
        perror("fork");
        exit(1);
    }

    char buf[MAXLINE];

    if(pid == 0){
        while(1){
            if(!fgets(buf, MAXLINE, stdin))
                break;
            write(fd_w, buf, strlen(buf)+1);
        }
        exit(0);
    }

    while(1){
        int n = read(fd_r, buf, MAXLINE);
        if (n > 0){
            printf("[Received] %s", buf);
            fflush(stdout); //필수 X
        }
    }

    close(fd_r);
    close(fd_w);
    return 0;
}

