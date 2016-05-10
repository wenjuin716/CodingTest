DIR=$(shell pwd)

CC=gcc
CFLAGS=
OBJS=myipc.o mygame.o
EXE=TestProgram

all: main.o

main.o: $(OBJS)
	$(CC) main.c $(OBJS) $(CFLAGS) -o $(EXE)

clean:
	rm -rf *.o $(EXE)
