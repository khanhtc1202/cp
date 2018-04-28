CC = gcc
CFLAGS = -g -std=c99
RM = rm -f

all: ex1

ex1: ex1.o libsort.o
	$(CC) ex1.o libsort.o -o ex1

ex1.o: main.c
	$(CC) $(CFLAGS) -c main.c -o ex1.o

libsort.o: libsort.c libsort.h
	$(CC) $(CFLAGS) -c libsort.c -o libsort.o

clean:
	$(RM) *.o ex1 result.txt
