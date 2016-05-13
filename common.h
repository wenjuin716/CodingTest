#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

/************************************************************************************/
//myCase common function
typedef struct myCase {
      int id;
      char help[50];
      void (*function)();
} myCase;

void myCasehelp(myCase *Cases);
int callFunction(myCase *Cases,int id);

/************************************************************************************/
//myGroup common function
typedef struct myGroup {
	int id;
        char name[20];
	char descript[128];
        myCase* cases;
} myGroup;

void dumpGroup(myGroup *group);
myCase* getCases(myGroup *group,int id);

/************************************************************************************/
//mySlist common function
typedef struct singleLinkedList {
        char name[20];
	char descript[128];
        struct singleLinkedList *next;
} mySlist;

void addList(mySlist** list, char *name, char *descript);
void dumplist(mySlist *list);
void purchList(mySlist** list);


/************************************************************************************/
//other help common function
void functionStart(void);
void functionStop(void);
