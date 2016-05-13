#include "common.h"
#include "myipc.h"
#include "mygame.h"
#include <termios.h>
void help(myCase *Cases)
{
     myCase *x=Cases;
     for(; x->id >= 0; x++){
         printf("  %d : %s\n",x->id, x->help);
     }

     return;
}

/************************************************************************************/
// test function define in here

void functionStart(void){
     printf("***********function start*****************\n");
}

void functionStop(void){
     printf("***********function stop*****************\n");
}

void invertString(void){
     char string[20];
     printf("Invert String Case, Enter String(Max 20 char):");
     scanf("%s",string);     // warning: unsafe (see fgets instead) 

     int length = strlen(string);

     int i=0;
     //char* tmp = new char[length];
     char* tmp = (char*) malloc(length);
     for(i=0; i<=length; i++)
          tmp[i]=string[length-1-i];

     for(i=0; i<length; i++)
          string[i]=tmp[i];

     printf("Invert String = %s\n",string);    
     //delete tmp;
     free(tmp);
}

void variableSize(void){
    char *ptr;
    printf("char: %d bytes.\n", sizeof(char));
    printf("int: %d bytes.\n", sizeof(int));
    printf("long: %d bytes.\n", sizeof(long));
    printf("float: %d bytes.\n", sizeof(float));
    printf("double: %d bytes.\n", sizeof(double));
    printf("unsigned int: %d bytes.\n", sizeof(unsigned int));
    printf("char pointer size(char *ptr): %d bytes.\n", sizeof(*ptr));
    printf("pointer size(ptr): %d bytes.\n", sizeof(ptr));
}

#if 1
void invertList(mySlist** list){
	mySlist *cur=NULL;
	mySlist *pre=NULL;

	printf("invert list start\n");
	cur = (*list);
	while(cur != NULL){
		cur = cur->next;
		(*list)->next = pre;
		pre=(*list);
		if(cur != NULL)
			(*list)=cur;
	}
	printf("invert finish.\n");
}

void invertSinglelist(void){
	mySlist* head=NULL;
	unsigned int number=0;
	char name[20]={0};
	int x=0;
	printf("Initial single linked list, Enter list number(must large than 0):");
	scanf("%d", &number);
	for(x=0; x<number; x++){
		memset(name, 0, sizeof(name));
		printf("Enter %dth's name:", x+1);
		scanf("%s", name);
		addList(&head, name, NULL);
	}

	dumplist(head);

	/* invert single linked list */
	invertList(&head);	
	dumplist(head);

	purchList(&head);
	dumplist(head);
	return;
}
#endif

#if 1
void bubbleSort(void){
	char input[]={20, 1, 58, 44,100, 2, 15, 20, 100, 512};
	int i,j,tmp;

        printf("before: {");
        for(i=0; i<sizeof(input); i++)
                printf(" %d,", input[i]);

        printf("}\n");


	for(i=0; i<sizeof(input); i++){
		for(j=0; j<(sizeof(input)-1-i); j++){
			if(input[j] > input[j+1]){
				/* exchange the number */
				tmp=input[j];
				input[j]=input[j+1];
				input[j+1]=tmp;
			}
		}
	}

	printf("after: {");
	for(i=0; i<sizeof(input); i++)
		printf(" %d,", input[i]);

	printf("}\n");

	return;
}
#endif

#if 1
void dec2bin(int c)
{
   int i = 0;
   for(i = 31; i >= 0; i--){
     if((c & (1 << i)) != 0){
       printf("1");
     }else{
       printf("0");
     } 
   }
   printf("\n");
}

void oper(void)
{
	unsigned int x=0,y=0;
	printf("Enter a unsigned inteter(x):");
	scanf("%d,", &x);
	dec2bin(x);
	printf("Enter a unsigned inteter(y):");
	scanf("%d,", &y);
	dec2bin(y);

	printf("x&y=%d\n",x&y);
	printf("x|y=%d\n",x|y);
	printf("x^y=%d\n",x^y);
	printf("x&&y=%d\n",x&&y);
	printf("x||y=%d\n",x||y);        
	printf("x<<y=%d\n",x<<y);
	printf("x>>y=%d\n",x>>y);
	printf("y<<x=%d\n",y<<x);
	printf("y>>x=%d\n",y>>x);
}
#endif

#if 1
unsigned int fibonacci(unsigned int x){

	if(x==0)
		return 0;
	else if(x==1)
		return 1;
	else
		return fibonacci(x-2) + fibonacci(x-1);

}
void fibSeries(void){
	printf("Enter the Nth of Fibonacci Series:");
	unsigned int x=0;
	scanf("%d", &x);

	printf("F%d=%d\n", x, fibonacci(x));
}
#endif

#if 1
void arrayAndPointer(void){

	int i[6]={10,20,30,40,50,60};
	int *ptr= (i+2);
	
	printf("Example:\n");
	printf("int i[6]={10,20,30,40,50,60};\n");
	printf("int *ptr=(i+2)\n\n");

	printf("Question:\n");
	printf("ptr[0]=%d\n", ptr[0]);
	printf("*(ptr+1)=%d\n", *(ptr+1));
	printf("*(i+1)=%d\n", *(i+1));
	printf("ptr[-1]=%d\n", ptr[-1]);
	
	printf("\nLevel 2 Question:\n");
	int *ptr1=(int *) 0x444444;
	char *ptr2=(char *) 0x111111;
	printf("int *ptr1=(int *) 0x444444;\n");
	printf("char *ptr2=(char *) 0x111111\n");
	ptr1 += 0x5;
	ptr2 += 0x5;
	printf("ptr1+=0x5;\nptr2+=0x5;\n");
	printf("ptr1=0x%x;\nptr2=0x%x;\n", ptr1,ptr2);
	return;
} 
#endif

#if 1
#define MAX 4
int setBitmap(int* bitmap,unsigned int offset){
	int index=0;
	
	if(NULL == bitmap || offset >= (sizeof(int)*MAX*8)){
		printf("Error: bitmap is NULL or offset is over bitmap size\n\n\n");
		return FALSE;
	}

	for(index=0; index<MAX;index++){
		if(offset < ((index+1)*sizeof(int)*8)){
			bitmap[index] |= (1 << offset);
			break;
		}
	}

	return TRUE;
}
void bitmapPractice(void){
	int bitmap[MAX]={0};
	int offset=0;
	int index=0;
	
	printf("Original Bitmap:\n");
	for(index=0; index < MAX; index++){
		printf("bitmap[%d]=", index);
		dec2bin(bitmap[index]);
	}

	printf("Enter the offset:");
	scanf("%d", &offset);

        if(setBitmap(bitmap, offset)){
		printf("After setBitmap:\n");
        	for(index=0; index < MAX; index++){
        	        printf("bitmap[%d]=", index);
        	        dec2bin(bitmap[index]);
        	}
	}
}
#endif

#if 1
myCase ipcCases[]={
  {0, "Finish Test program.", NULL},
  {1, "AF_UNIX Socket Server", socket_server},	/* UNIX Socket */
  {2, "AF_UNIX Socket Client", socket_client},	/* UNIX Socket */
  {3, "share memory Server.", shareMem_Server},	/* share Memory Server, create SHM */
  {4, "share memory Client.", shareMem_Client},	/* share Memory Client, associate SHM */
  {-1, "the last item for IPC_practice function.", NULL},
};

void ipc_practice(void){
	myCase *x=NULL;
	int example=0;
	int found=FALSE;
	pthread_t thread;
	while(1){
		found = FALSE;
		help(ipcCases);
		printf("Enter IPC test case:");
		scanf("%d", &example);

		if(example == 0){
			printf("finish IPC practice loop......\n");
			goto stop;
		}

		for(x=ipcCases; x->id >= 0; x++){
			if(x->id == example && x->function != NULL){
				functionStart();
				x->function();
				functionStop();
				found=TRUE;
				break;
			}
		}

		if(!found)
			printf("INPUT ERROR: please follow the hint\n");
	}

stop:	
        return;
}
#endif
/***********************************************************************************/
myCase testCases[] = {
  {0, "Finish Test program.", NULL},
  {1, "Reverse String Case.", invertString},
  {2, "Size of variables.", variableSize},
  {3, "Invert Single linked list.", invertSinglelist},
  {4, "Sort a list of number.", bubbleSort},
  {5, "Operater sample.", oper},
  {6, "Fibonacci series.", fibSeries},
  {7, "array vs pointer operator.", arrayAndPointer},
  {8, "bitmap and offset pratice.", bitmapPractice},
  {9, "IPC practice.", ipc_practice},
  {10, "Tower of Hanoi Game.", Hanoi},
  {-1, "the last item for test code.", NULL},
};

int main(int argc, char** argv)
{
    int example=-1;
    char* input[20];    
    myCase *x=NULL;

    while(1){
        help(testCases);
	printf("Enter Main test case:");
        scanf("%d", &example);
        
	if(example == 0){
		printf("finish program......\n");
		goto stop;
	}
        for(x=testCases; x->id >= 0; x++){
         if(x->id == example && x->function != NULL){
           functionStart();
           x->function();
           functionStop();
           break;
         }
        } 
    }  

stop:
    return 1;
}
