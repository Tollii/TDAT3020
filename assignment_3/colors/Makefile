CC=gcc
CFLAGS=-O3
DEPS=fargeskrift.h

.PHONY: all clean install

.SUFFIXES:


all: fargedemo fargetest fargewasd

%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) $< -o $@ 

fargedemo: fargedemo.o fargeskrift.o
	$(CC) -o fargedemo fargedemo.o fargeskrift.o

fargetest: fargetest.o fargeskrift.o
	$(CC) -o fargetest fargetest.o fargeskrift.o

fargewasd: fargetest.o fargeskrift.o
	$(CC) -o fargewasd fargetest.o fargeskrift.o


clean:
	rm -f *.o fargedemo fargetest

install: fargedemo fargetest
	cp fargedemo fargetest /usr/local/bin/

