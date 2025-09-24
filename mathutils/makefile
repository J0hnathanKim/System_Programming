CC = gcc
CFLAGS = -g
OBJ = main.o mathutils.o
TARGET = calcprog

# Final excutable program
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# build main.o
main.o: main.c mathutils.h
	$(CC) $(CFLAGS) -c main.c

# build mathutils.o 
mathutils.o: mathutils.c mathutils.h
	$(CC) $(CFLAGS) -c mathutils.c

# cleaner
clean:
	rm -f $(TARGET) *.o
