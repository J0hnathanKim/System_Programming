#include<stdio.h>
#include "fact.h"
int main(){
        int a = 5;
        int b = 6;
        printf("Factorial %d is %d\n",a, fact(a));
        printf("Factorial %d is %d\n", b, fact(b));
        return 0;
}
