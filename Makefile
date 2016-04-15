DIR=$(shell pwd)

CC=gcc
CFLAGS=
OBJS=ipc.o
EXE=TestProgram

all: main.o

main.o: $(OBJS)
	$(CC) main.c $(OBJS) $(CFLAGS) -o $(EXE)

ipc.o:
	$(CC) -c ipc.c

clean:
	rm -rf *.o $(EXE)
