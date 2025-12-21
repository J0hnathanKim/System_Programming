#include <stdio.h>
#define MAXLINE 1024

int main(void)
{
    FILE *fp;
    int line = 0;
    char buffer[MAXLINE];


    fp = fopen("books.txt", "r+");
    if (fp == NULL) {
        perror("books.txt");  
        return 1;
    }


    fprintf(fp, "The Little Prince by Antoine de Saint-Exupury (1943)\n");
    fprintf(fp, "To Kill a Mockingbird by Harper Lee (1960)\n");
    fprintf(fp, "Pride and Prejudice by Jane Austen (1813)\n");
    fprintf(fp, "1984 by George Orwell (1949)\n");


    rewind(fp); 

    printf("=== Book List ===\n");
    while (fgets(buffer, MAXLINE, fp) != NULL) {
        line++;
        printf("Book %d = %s", line, buffer);
    }

    fclose(fp);
    return 0;
}
