#include<stdio.h>
struct info{
int std;
char name[20];
char id[14];
char phone[14];
double gpa;
};

int main(){
struct info a;
printf("Student ID: ");
scanf("%d", &a.std);
printf("Name : ");
scanf("%s", a.name);
printf("Resident ID: ");
scanf("%s", a.id);
printf("Phone: ");
scanf("%s", a.phone);
printf("GPA: ");
scanf("%lf",&a.gpa);
printf("===Masked Output===\n");
printf("Student ID: %d\n", a.std);
printf("Name: %s\n", a.name);
printf("Resident ID: ");
for(int i = 0; i < 14; i++){
 if(i <= 7) printf("%c",a.id[i]);
 else if(i > 7) printf("*");
 }
printf("\n");
printf("Phone: %s\n", a.phone);
printf("GPA: ***");
printf("\n");
}

