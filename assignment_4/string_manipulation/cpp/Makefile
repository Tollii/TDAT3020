CC=g++
CFLAGS=-O3

.PHONY: all clean

all: string_manipulation

%.o: %.c
		$(CC) -c $(CFLAGS) $< -o $@

string_manipulation: string_manipulation.o
	$(CC) -o string_manipulation string_manipulation.o

clean:
	rm -f *.o string_manipulation

