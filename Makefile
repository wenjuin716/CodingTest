DIR=$(shell pwd)

CC=gcc
CFLAGS=
OBJS=myipc.o
EXE=TestProgram

all: main.o

main.o: $(OBJS)
	$(CC) main.c $(OBJS) $(CFLAGS) -o $(EXE)

myipc.o:
	$(CC) -c myipc.c

clean:
	rm -rf *.o $(EXE)
