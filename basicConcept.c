#include "basicConcept.h"

void macroConcept(void){
	printf("#define SQUARE(x) (x*x)\n");
	printf("#define SQUARE2(x) ((x)*(x))\n");
	printf("Q1:SQUARE(3+4)=%d\n",SQUARE(3+4));
	printf("Q2:SQUARE2(3+4)=%d\n",SQUARE2(3+4));
}

void variableSizeConcept(void){
	char charArray[10]="string";
	int intArray[10]={1,2,3,4,5,6,7,8,9,10};
	int Array[5][10];
	char *charPtr=NULL;
	int *intPtr=NULL;
	
	printf("Basic variable size:\n");
	printf("\t[Character]sizeof(char)= %d bytes.\n", (int)sizeof(char));
	printf("\t"ANSI_COLOR_RED"[Integer]"ANSI_COLOR_RESET"sizeof(short)= %d bytes.\n", (int)sizeof(short));
	printf("\t"ANSI_COLOR_RED"[Integer]"ANSI_COLOR_RESET"sizeof(int)= %d bytes.\n", (int)sizeof(int));
	printf("\t"ANSI_COLOR_RED"[Integer]"ANSI_COLOR_RESET"sizeof(long)= %d bytes.\n", (int)sizeof(long));
	printf("\t"ANSI_COLOR_RED"[Integer]"ANSI_COLOR_RESET"sizeof(unsigned int)= %d bytes.\n", (int)sizeof(unsigned int));
	printf("\t[Float]sizeof(float)= %d bytes.\n", (int)sizeof(float));
	printf("\t[Float]sizeof(double)= %d bytes.\n", (int)sizeof(double));

	printf("\n\nBasic array size:\n");
	printf("char charArray[10]=\"string\";\n");
	printf("int intArray[10]={1,2,3,4,5,6,7,8,9,10};\n");
	printf("int Array[5][10];\n");
	printf("\tsizeof("ANSI_COLOR_RED"charArray"ANSI_COLOR_RESET")= %d bytes.\n", (int)sizeof(charArray));
	printf("\tsizeof("ANSI_COLOR_RED"charArray[0]"ANSI_COLOR_RESET")= %d bytes.\n", (int)sizeof(charArray[0]));
	printf("\tstrlen("ANSI_COLOR_RED"charArray"ANSI_COLOR_RESET")= %d.\n", strlen(charArray));
	printf("\tsizeof(intArray)= %d bytes.\n", (int)sizeof(intArray));
	printf("\tsizeof(intArray[0])= %d bytes.\n", (int)sizeof(intArray[0]));
	printf("\tsizeof(Array)= %d bytes.\n", sizeof(Array));
        printf("\tsizeof(Array[3])= %d bytes.\n", sizeof(Array[3]));
        printf("\tsizeof(Array[3][5])= %d bytes.\n", sizeof(Array[3][5]));

	printf("\n\nBasic pointer size:\n");
	printf("char *charPtr=charArray;\n");
	printf("int *intPtr=intArray;\n");
	printf("\tsizeof("ANSI_COLOR_RED"*charPtr"ANSI_COLOR_RESET")= %d bytes.\n", (int)sizeof(*charPtr));
	printf("\tsizeof("ANSI_COLOR_RED"charPtr"ANSI_COLOR_RESET")= %d bytes.\n", (int)sizeof(charPtr));
	printf("\tsizeof(*intPtr)= %d bytes.\n", (int)sizeof(*intPtr));
	printf("\tsizeof(intPtr)= %d bytes.\n", (int)sizeof(intPtr));
}

void invertString(void){
	char string[20];
	//fgetc(stdin);	//ingore the first stdin
	printf("Enter String(Max 20 char):");
	gets(string);	//waiting user type string

	int length = strlen(string);

	int i=0;
	//char* tmp = new char[length];
	char* tmp = (char*) malloc(length);
	for(i=0; i<=length; i++)
	  tmp[i]=string[length-1-i];

	for(i=0; i<length; i++)
	  string[i]=tmp[i];

	printf("Reverse String is %s\n",string);    
	//delete tmp;
	free(tmp);
}

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

	printf("F(%d)=%d\n", x, fibonacci(x));
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
	printf("ptr1=0x%p;\nptr2=0x%p;\n", ptr1,ptr2);
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
void sListUsage(void){
	system("clear");
	printf("################ link list method ###################\n");
	printf(" 0:Exit the program.\n");
	printf(" 1:add a new entry to link list\n");
	printf(" 2:delet entry by name.(not implement)\n");
	printf(" 3:dump list info.\n");
	printf(" 4:reverse the link list.\n");
	printf(" 5:purch link list.\n");
	printf("###############################################\n");
}

void linklist(void){
	mySlist* head=NULL;
	int running=TRUE;
	char name[20]={0};
	int id=0;
	
	do{
		sListUsage();
		printf("Enter your interesting case:");
		scanf("%d", &id);
		switch(id){
		case 0:
			purchList(&head);
			running = FALSE;
			break;
		case 1:
			// add a new entry to last one
			memset(name, 0, sizeof(name));
			printf("Enter new entry name:");
			scanf("%s", name);
			addList(&head, name, NULL);
			break;
		case 2:
			memset(name, 0, sizeof(name));
			printf("Enter delete entry name:");
			scanf("%s", name);
			delByName(&head, name);
			break;
		case 3:
			dumplist(head);
			fgetc(stdin);	//clear stdin
			PAUSE
			break;
		case 4:
			/* invert single linked list */
			reverseList(&head);
			break;
		case 5:
			purchList(&head);
			break;
		default:
			printf(ANSI_COLOR_RED"Wrong case.\n"ANSI_COLOR_RESET);
			break;
		}
	}while(running);

	fgetc(stdin);	//clear stdin
	return;
}
#endif


