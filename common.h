#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef struct testCase {
      int id;
      char help[50];
      void (*function)();
} myCase;


typedef struct singleLinkedList {
        char name[20];
	char descript[128];
        struct singleLinkedList *next;
} mySlist;

void addList(mySlist** list, char *name, char *descript);
void dumplist(mySlist *list);
void purchList(mySlist** list);
