DIR=$(shell pwd)

CC=gcc
CFLAGS=
OBJS=test.o
EXE=TestProgram

all: test

test:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)

clean:
	rm -rf $(OBJS) $(EXE)
