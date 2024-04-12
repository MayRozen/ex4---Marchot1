CC = gcc
CFLAGS = -wll -g


all: digitcompress

encodemain.o: encodemain.c compress.h
	$(CC) $(CFLAGS) -c encodemain.c


digitcompress: encodemain.o
	$(CC) $(CFLAGS) -o encodemain encodemain.o

clean:
	rm -f *.o *.c digitcompress