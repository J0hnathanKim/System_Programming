#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    int grade;
    char name[20];
    double gpa;
};

int main()
{
   FILE *fp;
   int capacity = 10;
   int count = 0;
   struct student* std = (struct student*)malloc(sizeof(struct student) * capacity);
   fp = fopen("students.txt", "r");
   while(1){
   struct student tmp;
   int n = fscanf(fp,"%d %d %s %lf",&tmp.id, &tmp.grade, tmp.name, &tmp.gpa);
   if(n < 4) break;
   std[count] = tmp;
   count += 1;
   if(count > 10){
   capacity += 10;
   struct student* new_arr = (struct student*)realloc(std, sizeof(struct student) * capacity);
   std = new_arr;
   }
   
   }
   printf("-------------Student Information----------------------\n");
   for(int i = 0; i < count; i++){
   printf("ID: %d    GRADE: %d       NAME: %s     GPA: %.2lf\n", std[i].id, std[i].grade, std[i].name, std[i].gpa);
   }
   free(std);
   return 0;
}
