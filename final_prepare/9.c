#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{  
   int number = 0;
   printf("Type the number : ");
   scanf("%d", &number);
   int* arr = (int *)malloc(sizeof(int) * number);
   for(int i = 0; i < number; i++){
   arr[i] = fork();
   if(arr[i] == 0) {
   printf("I'm %dth Child, Child id : %d, Parents id: %d\n", i+1, getpid(), getppid());
   exit(0);
   
   }
   
   }
   while(wait(NULL) > 0 );
   printf("Child IDs: ");
   for(int i = 0; i < number; i++){
   printf("%d ", arr[i]);
   }
   printf("\n");
   free(arr);
   return 0;
}
