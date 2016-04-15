#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if 1	// add for Inter-Process Comminucation case
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/un.h>		// sockaddr_un for AF_UNIX
#include <unistd.h>		// for close()
#endif

typedef struct testCase {
      int id;
      char help[50];
      void (*function)();
} myCase;

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
struct singleLinkedList {
	char name[20];
	struct singleLinkedList *next;
};
typedef struct singleLinkedList mySlist;

void addList(mySlist** list){
	char prefix[10] = "name_";
	if(*list == NULL){
		/* the first entry of list */
		*list = (mySlist*) malloc(sizeof(mySlist));
		// init linked list
                sprintf( (*list)->name, "%s1", prefix);
		(*list)->next = NULL;
	}else{
		//find the last entry
		mySlist *tmp=NULL;
		int count=0;
		for(tmp = *list; tmp != NULL; tmp = tmp->next){
			++count;
			if(tmp->next == NULL)
				break;
		}
		
		tmp->next = (mySlist*) malloc(sizeof(mySlist));
                sprintf( (tmp->next)->name, "%s%d", prefix, count+1);
                (tmp->next)->next = NULL;
	}
}

void dumplist(mySlist *list){
	mySlist *tmp = list;
	int count=0;
	for(;tmp != NULL; tmp=tmp->next){
		printf("Entry[%d]:%s\n", ++count, tmp->name);
	}
}

void purchList(mySlist** list){
	mySlist *tmp=NULL;
	for(;(*list) != NULL;){
		tmp = (*list);
		(*list) = (*list)->next;
		printf("free %s.\n", tmp->name);
		free(tmp);
	}
}

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
	printf("Initial single linked list, Enter list number(must large than 0):");
	scanf("%d", &number);
	for(int x=0; x<number; x++)
		addList(&head);

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
bool setBitmap(int* bitmap,unsigned int offset){
	int index=0;
	
	if(NULL == bitmap || offset >= (sizeof(int)*MAX*8)){
		printf("Error: bitmap is NULL or offset is over bitmap size\n\n\n");
		return false;
	}

	for(index=0; index<MAX;index++){
		if(offset < ((index+1)*sizeof(int)*8)){
			bitmap[index] |= (1 << offset);
			break;
		}
	}

	return true;
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
//int socket(int domain, int type, int protocol);
#define SOCKET_NAME "tmp.socket"
#define BUFFER_SIZE 64

void socket_server(void){
	/*
	**	struct sockaddr_un {
	**	 sa_family_t sun_family;               // AF_UNIX
	**	 char        sun_path[108];            // pathname
	**	};
	*/
	struct sockaddr_un name;
	int serverfd=0, readfd=0;
	int ret=0;
	char buffer[BUFFER_SIZE]={0};

	/*
	 * In case the program exited inadvertently on the last run,
	 * remove the socket.
	 */
	unlink(SOCKET_NAME);


	/*
	**  AF_UNIX is used for local interprocess communication
	**	valid type in AF_UNIX socket as below:
	**	1) SOCK_STREAM for a stream-oriented socket;
	**	2) SOCK_DGRAM, for a datagram-oriented socket that preserves message boundaries
	**	3) SOCK_SEQPACKET, for a sequenced-packet socket that is connection-oriented, preserves message boundaries,
	**	   and delivers messages in the order that they were sent.
	*/
	serverfd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
	if(serverfd == -1){
		printf("Create server socket error.\n");
		goto stop;
	}else{
		printf("Create Server socket, fd=%d\n", serverfd);
	}

	memset(&name, 0, sizeof(struct sockaddr_un));
	/* Bind socket to socket name. */

	name.sun_family = AF_UNIX;
	strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path) - 1);

	ret = bind(serverfd, (const struct sockaddr *) &name,
		  sizeof(struct sockaddr_un));
	if (ret == -1) {
	   printf("server socket bind error\n");
	   goto stop;
	}

	/*
	* Prepare for accepting connections. The backlog size is set
	* to 20. So while one request is being processed other requests
	* can be waiting.
	*/

	ret = listen(serverfd, 20);
	if (ret == -1) {
	   printf("server socket listen error\n");
	   goto stop;
	}

	printf("####### server socket waiting client connect.....\n\n");

	/* Wait for incoming connection. */
	readfd=accept(serverfd, NULL, NULL);
	if(-1 == readfd){
		printf("accept error.\n");
		goto stop;
	}

	printf("####### server socket accept succcess and waiting receive data\n\n");
	ret = write(readfd, "Hi client, Notice: server will terminate when receive \"END\"", BUFFER_SIZE);

	if (ret == -1) {
		printf("write data error\n");
		goto stop;
	}

	/* TODO */
	/* we should implement receive client data loop here */
	for(;;){
		ret = read(readfd, buffer, BUFFER_SIZE);
		if(-1 == ret){
			printf("read data error.\n");
			goto stop;
		}

		printf("server receive: %s\n", buffer);

		if (!strncmp(buffer, "END", BUFFER_SIZE)) {
			printf("receive END, server terminate....\n");
			break;
		}
	}

stop:
	close(readfd);
        close(serverfd);

	/* Unlink the socket. */
	unlink(SOCKET_NAME);
	printf("####### finish server socket loop\n\n");
	return;
}

void socket_client(void){
	int clientfd=0;
	struct sockaddr_un addr;
	char buffer[BUFFER_SIZE]={0};
	int ret=0;

	/*
	**  AF_UNIX is used for local interprocess communication
	**	valid type in AF_UNIX socket as below:
	**	1) SOCK_STREAM for a stream-oriented socket;
	**	2) SOCK_DGRAM, for a datagram-oriented socket that preserves message boundaries
	**	3) SOCK_SEQPACKET, for a sequenced-packet socket that is connection-oriented, preserves message boundaries, 
	**	   and delivers messages in the order that they were sent.
	*/
	clientfd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
	if(clientfd == -1){
		printf("Create client socket error.\n");
		goto stop;
	}else{
		printf("Create client socket, fd=%d\n", clientfd);
	}

	memset(&addr, 0, sizeof(struct sockaddr_un));
	/* Bind socket to socket name. */

	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);

	ret = connect(clientfd, (const struct sockaddr *) &addr,
		  sizeof(struct sockaddr_un));
	if (ret == -1) {
	   printf("client socket bind error\n");
	   goto stop;
	}

	ret = read(clientfd, buffer, BUFFER_SIZE);
	if (ret == -1) {
		printf("read data error\n");
		goto stop;
	}

	printf("%s\n\n", buffer);

	for(;;){
		/* TODO */
		memset(buffer, 0, BUFFER_SIZE);
		printf("Enter the message:");
		//scanf("%s", buffer);
		gets(buffer);
		ret = write(clientfd, buffer, BUFFER_SIZE);
		if (ret == -1) {
			printf("write data error\n");
			goto stop;
		}
	}
stop:
	close(clientfd);
	return;
}

myCase ipcCases[]={
  {0, "Finish Test program.", NULL},
  {1, "AF_UNIX Socket Server", socket_server},
  {2, "AF_UNIX Socket Client", socket_client},
  {-1, "the last item for IPC_practice function.", NULL},
};

void ipc_practice(void){
	myCase *x=NULL;
	int example=0;
	bool found=false;
	pthread_t thread;
	while(1){
		found = false;
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
				found=true;
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

