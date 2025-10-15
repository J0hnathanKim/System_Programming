#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    long size;

    
    if (argc < 2) {
        printf("Usage: %s file1.txt\n", argv[0]);
        return 1;
    }

    
    for (int i = 1; i < argc; i++) {
        fp = fopen(argv[i], "rb");   
        if (fp == NULL) {
            fprintf(stderr, "Cannot open file: %s\n", argv[i]);
            continue;
        }

        
        fseek(fp, 0, SEEK_END);
        size = ftell(fp);

        
        printf("Size of file[%s] is %ldbytes.\n", argv[i], size);

        fclose(fp);
    }

    return 0;
}
