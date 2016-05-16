#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define PAUSE printf("Press Enter key to continue..."); fgetc(stdin);

#define DEBUG printf("[Common Debug]%s:%d\n",__FILE__, __LINE__);fgetc(stdin);

typedef struct singleLinkedList mySlist;
typedef struct myGroup myGroup;
typedef struct myCase myCase;

void myCasehelp(myCase *Cases);
int callFunction(myCase *Cases,int id);

void dumpGroup(myGroup *group);
myCase* getCases(myGroup *group,int id);

void addList(mySlist** list, char *name, char *descript);
void dumplist(mySlist *list);
void purchList(mySlist** list);
void reverseList(mySlist** list);
void delByName(mySlist** list, const char* name);

/************************************************************************************/
//other help common function
void functionStart(void);
void functionStop(void);
#ifndef COMMON_H	//those struct can't be included twice, So we should protect it by macro 
/************************************************************************************/
//myCase common function
struct myCase {
      int id;
      char help[50];
      void (*function)();
};

/************************************************************************************/
//myGroup common function
struct myGroup {
	int id;
        char name[20];
	char descript[128];
        myCase* cases;
};

/************************************************************************************/
//mySlist common function
struct singleLinkedList {
        char name[20];
	char descript[128];
        struct singleLinkedList *next;
};
#endif	//COMMON_H
