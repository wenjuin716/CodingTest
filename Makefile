DIR=$(shell pwd)

CC=gcc
CFLAGS=
OBJS=
EXE=TestProgram

all: main.o

main.o:
	$(CC) main.c $(OBJS) $(CFLAGS) -o $(EXE)

clean:
	rm -rf *.o $(EXE)
