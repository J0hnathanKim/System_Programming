#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int c;

    
    if (argc < 2) {
        printf("Usage: %s file1.txt [file2.txt ...]\n", argv[0]);
        return 1;
    }

    
    for (int i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");  
        if (fp == NULL) {
            fprintf(stderr, "Can't open %s \n", argv[i]);
            continue;  
        }

        printf("\n%d. Filename: %s\n", i, argv[i]);
        printf("=================================\n");

        
        while ((c = fgetc(fp)) != EOF)
            putchar(c);

        fclose(fp);  
        printf("\n");
    }

    return 0;
}

