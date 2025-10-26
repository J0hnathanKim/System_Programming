#include <stdio.h>
#include <string.h>
#define MAXLINE 80

/* 텍스트 파일 내용을 표준출력에 프린트 */
int main(int argc, char *argv[])
{
    FILE *fp;
    int c;
    int line = 0;
    char buffer[MAXLINE];

    if (argc < 2) {
        fp = stdin;  // 인자가 없으면 표준입력 사용
    }
    else if (!strcmp(argv[1], "-n")) {  // "-n" 옵션일 경우
        if (argc < 3) {
            fprintf(stderr, "Usage: %s -n <filename>\n", argv[0]);
            return 1;
        }

        fp = fopen(argv[2], "r");  // 파일 열기
        if (fp == NULL) {
            perror(argv[2]);
            return 1;
        }
        while (fgets(buffer, MAXLINE, fp) != NULL) {  // 한 줄 읽기
              line++;
              printf("%d %s", line, buffer);    // 줄번호와 함께 프린트
        }
        fclose(fp);
        return 0;
    }
    else {
        fp = fopen(argv[1], "r"); // 일반 파일 읽기
        if (fp == NULL) {
            perror(argv[1]);
            return 1;
        }
    }

    // 기본 모드: 번호 없이 파일 내용 출력
    while ((c = getc(fp)) != EOF) {
        putc(c, stdout);
    }

    fclose(fp);
    return 0;
}
