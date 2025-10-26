//still fixing
#include <stdio.h>
#include <string.h>

/* 텍스트 파일 내용을 표준출력에 프린트 */
int main(int argc, char *argv[])
{
    FILE *fp;
    int c;
    int i = 1;

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

        printf("%d ", i);  // 첫 번째 줄 번호 출력
        while ((c = getc(fp)) != EOF) {
            putc(c, stdout);   // 문자 출력
            if (c == '\n') {   // 줄바꿈이면 다음 줄 번호 출력
                i++;
                printf("%d ", i);
            }
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
