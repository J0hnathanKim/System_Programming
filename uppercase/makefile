main: main.o to_uppercase.o
	gcc -g -o main main.o to_uppercase.o

main.o: main.c to_uppercase.h
	gcc -g -c main.c

to_uppercase.o: to_uppercase.c
	gcc -g -c to_uppercase.c
