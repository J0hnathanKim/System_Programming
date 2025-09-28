#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

union Data {
	int i;
	float f;
	char str[20];
};


int main() {
	union Data d;
	d.i = 123;
	printf("[d.i = 123;]\n");
	printf("d.i = %d\n", d.i);
	printf("d.i = %lf\n", d.f);
	printf("d.i = %s\n", d.str);
	printf("\n");
	d.f = 3.14159;
	printf("[d.f = 3.14159;]\n");
	printf("d.i = %d\n", d.i);
	printf("d.i = %lf\n", d.f);
	printf("d.i = %s\n", d.str);
	printf("\n");
	strcpy(d.str, "hello");
	printf("strcpy(d.str,\"hello\");\n");
	printf("d.i = %d\n", d.i);
	printf("d.i = %lf\n", d.f);
	printf("d.i = %s\n", d.str);
	printf("\n");
	printf("union Data의 크기 = %d 바이트", sizeof(d));
}
