DIR=$(shell pwd)

CC=gcc
CFLAGS=
COMMON_OBJS= common
OBJS=basicConcept myipc mygame
EXE=TestProgram

all: main.o

main.o: $(COMMON_OBJS) $(OBJS)
	$(CC) $(COMMON_OBJS) $(OBJS) $(CFLAGS) -o $(EXE) main.c

common:
	$(CC) -c -o $@ $(CFLAGS) common.c

basicConcept:$(COMMON_OBJS)
	$(CC) -c -o $@ $(CFLAGS) $(COMMON_OBJS) basicConcept.c

myipc:
	$(CC) -c -o $@ $(CFLAGS) myipc.c

mygame:
	$(CC) -c -o $@ $(CFLAGS) mygame.c

clean:
	rm -rf *.o $(OBJS) $(COMMON_OBJS) $(EXE)
