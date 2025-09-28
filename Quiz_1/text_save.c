#include <stdio.h>

int main() {
    FILE *fp;
    char c;

    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        perror("File open error");
        return 1;
    }

    printf("input text (Ctrl+D to finish):\n");
    while ((c = getchar()) != EOF) {
        fputc(c, fp);
    }

    fclose(fp);
    printf("Saved to example.txt\n");
    return 0;
}
