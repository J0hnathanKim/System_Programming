#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

/* 시간 출력 함수 */
void print_time(time_t t)
{
    struct tm *tm = localtime(&t);
    char buf[64];

    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm);
    printf("%s\n", buf);
}

/* 파일 타입을 문자열로 변환 */
const char *get_file_type(mode_t mode)
{
    if (S_ISREG(mode))  return "일반 파일";
    if (S_ISDIR(mode))  return "디렉터리";
    if (S_ISCHR(mode))  return "문자 장치 파일";
    if (S_ISBLK(mode))  return "블록 장치 파일";
    if (S_ISFIFO(mode)) return "FIFO(파이프) 파일";
    if (S_ISLNK(mode))  return "심볼릭 링크";
    if (S_ISSOCK(mode)) return "소켓";
    return "알 수 없음";
}

/* 접근 권한을 rwxrwxr-x 형태로 출력 */
void print_perm(mode_t mode)
{
    char p[10];

    p[0] = (mode & S_IRUSR) ? 'r' : '-';
    p[1] = (mode & S_IWUSR) ? 'w' : '-';
    p[2] = (mode & S_IXUSR) ? 'x' : '-';

    p[3] = (mode & S_IRGRP) ? 'r' : '-';
    p[4] = (mode & S_IWGRP) ? 'w' : '-';
    p[5] = (mode & S_IXGRP) ? 'x' : '-';

    p[6] = (mode & S_IROTH) ? 'r' : '-';
    p[7] = (mode & S_IWOTH) ? 'w' : '-';
    p[8] = (mode & S_IXOTH) ? 'x' : '-';
    p[9] = '\0';

    printf("%s", p);
}

int main(int argc, char *argv[])
{
    struct stat st;

    if (argc != 2) {
        printf("사용법 : %s filename\n", argv[0]);
        exit(0);
    }

    if (stat(argv[1], &st) == -1) {
        perror("stat");
        exit(0);
    }

    printf("파일 이름 : %s\n", argv[1]);
    printf("파일 타입 : %s\n", get_file_type(st.st_mode));

    printf("접근 권한 : ");
    print_perm(st.st_mode);
    printf("\n");

    printf("링크 수 : %ld\n", (long)st.st_nlink);
    printf("UID : %d\n",  st.st_uid);
    printf("GID : %d\n",  st.st_gid);
    printf("파일 크기 : %ld bytes\n", (long)st.st_size);

    printf("최종 접근 시간(atime): ");
    print_time(st.st_atime);

    printf("최종 수정 시간(mtime): ");
    print_time(st.st_mtime);

    printf("상태 변경 시간(ctime): ");
    print_time(st.st_ctime);

    return 0;
}
