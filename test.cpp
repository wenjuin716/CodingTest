#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<iostream>
//using namespace std;

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

/***********************************************************************************/

struct testCase {
      int id;
      char help[50]; 
      void (*function)();
};

struct testCase testCases[] = {
  {0, "Reverse String Case.", invertString},
  {1, "size of variables.", variableSize},
  {-1, "the last item for test code.", NULL},
};

void help(void)
{
     testCase *x=testCases;
     for(; x->id >= 0; x++){
         printf("  %d : %s\n",x->id, x->help);
     } 
     printf("Enter Test Case:");    
     return;
}

int main(int argc, char** argv)
{
    int example=-1;
    char* input[20];    
    testCase *x=testCases;    

    while(1){
        help();
        scanf("%d", &example);
        
        for(x=testCases; x->id >= 0; x++){
         if(x->id == example && x->function != NULL){
           functionStart();
           x->function();
           functionStop();
           break;
         }
        } 
    }  

    return 1;
}

