CC = gcc
CFLAGS = -Wall -g


all: digitcompress

compress.a: compress.o compress.h
	ar rcs compress.a compress.o

compress.o: compress.c compress.h
	$(CC) $(CFLAGS) -c compress.c

encodemain.o: encodemain.c compress.h
	$(CC) $(CFLAGS) -c encodemain.c -o encodemain.o

digitcompress: encodemain.o compress.a
	$(CC) $(CFLAGS) -o digitcompress encodemain.o ./compress.a

clean:
	rm -f *.o *.a digitcompress
