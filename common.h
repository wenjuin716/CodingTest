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

struct singleLinkedList {
        char name[20];
        struct singleLinkedList *next;
};
typedef struct singleLinkedList mySlist;
