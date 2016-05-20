#include "basicConcept.h"
#include "myipc.h"
#include "mygame.h"

/***********************************************************************************/
// cases definition 
myCase basicCases[] = {
  {0, "Exit basicCases program.", NULL},
  {1, "variable size concept.", variableSizeConcept},
  {2, "Reverse String Case.", invertString},
  {3, "Invert Single linked list.", linklist},
  {4, "Sort a list of number.", bubbleSort},
  {5, "Operater sample.", oper},
  {6, "Fibonacci series.", fibSeries},
  {7, "array vs pointer operator.", arrayAndPointer},
  {8, "bitmap and offset pratice.", bitmapPractice},
  {9, "MACRO Concept.", macroConcept},
  {10, "Variable calculation Concept.", varCalConcept},  
  {-1, "the last item for test code.", NULL},
};

myCase ipcCases[]={
  {0, "Exit ipcCases program.", NULL},
  {1, "AF_UNIX Socket Server", socket_server},	/* UNIX Socket */
  {2, "AF_UNIX Socket Client", socket_client},	/* UNIX Socket */
  {3, "share memory Server.", shareMem_Server},	/* share Memory Server, create SHM */
  {4, "share memory Client.", shareMem_Client},	/* share Memory Client, associate SHM */
  {-1, "the last item for IPC_practice function.", NULL},
};

myCase gameCases[]={
  {0, "Exit gameCases program.", NULL},
  {1, "Tower of Hanoi Game.", Hanoi},
  {-1, "the last item for IPC_practice function.", NULL},
};

myGroup myGroups[] = {
  {1,	"basic", 	"basic programming concept.", basicCases},
  {2,	"IPC", 		"inter-process communication practice.", ipcCases},
  {3,	"Game",		"little Game practice.", gameCases},
  {0,	"", 		"", NULL},	//last
};

int main(int argc, char** argv)
{
	int id=-1;
	int ret=-1;
	int keepRunning=TRUE;
	myCase *cur_cases=NULL;
	while(keepRunning){
		//dump group info
		dumpGroup(myGroups);
		printf("Select Group(0=>Exit):");
		scanf("%d", &id);
		if(0 == id){
			keepRunning=FALSE;
			continue;
		}else if(NULL==(cur_cases=getCases(myGroups,id))){
			printf("Error Group id, please try again.\n");
			PAUSE
			continue;
		}

		do{
			//dump cases info
			myCasehelp(cur_cases);
			printf("Select Case:");
			scanf("%d", &id);
			if(0 == id){
				break;
			}else if(FALSE==callFunction(cur_cases, id)){
				printf("Error Case id.\n");
				PAUSE
				continue;
			}
		}while(1);
	}

stop:
    return 1;
}
