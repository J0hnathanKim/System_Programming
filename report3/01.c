#include <stdio.h>
#include <stdlib.h>

struct student {
    int   id;
    int   grade;        
    char  name[20];
    float gpa;          
};

int main(void)
{
    FILE *fp;
    struct student *arr = NULL;
    int capacity = 10;      
    int count = 0;          

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        perror("students.txt");
        exit(0);
    }

    arr = (struct student *)malloc(sizeof(struct student) * capacity);
    if (arr == NULL) {
        perror("malloc");
        fclose(fp);
        exit(0);
    }


    while (1) {
        struct student tmp;
        int n = fscanf(fp, "%d %d %19s %f",
                       &tmp.id, &tmp.grade, tmp.name, &tmp.gpa);
        if (n != 4)      
            break;

        
        if (count == capacity) {
            capacity += 10;
            struct student *new_arr =
                (struct student *)realloc(arr, sizeof(struct student) * capacity);
            if (new_arr == NULL) {
                perror("realloc");
                free(arr);
                fclose(fp);
                return 1;
            }
            arr = new_arr;
        }

        arr[count++] = tmp;
    }

    fclose(fp);

    printf("-----------Student Information-----------\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %4d, Grade: %d, Name: %-10s, GPA: %.2f\n",
               arr[i].id, arr[i].grade, arr[i].name, arr[i].gpa);
    }
    printf("Total %d students.\n", count);

    free(arr);
    return 0;
}
