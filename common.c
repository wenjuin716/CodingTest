#include "common.h"

/************************************************************************************/
//myCase common function
void myCasehelp(myCase *Cases)
{
	myCase *tmp=Cases;
	system("clear");	//clear cmd window
	printf("##################Case Help ###################\n");
	for(; tmp->id >= 0; tmp++){
		printf(ANSI_COLOR_BLUE"  %d : %s\n"ANSI_COLOR_RESET,tmp->id, tmp->help);
	}
	printf("###############################################\n");

	return;
}

int callFunction(myCase *Cases,int id){
	int ret=FALSE;
	myCase *tmp=NULL;
	for(tmp = Cases; tmp->id >= 0; tmp++){
		if(id == tmp->id){
			if(NULL != tmp->function){
				system("clear");	//clear cmd window
				printf("Excute case %d : %s\n",tmp->id, tmp->help);
				ret=TRUE;
				functionStart();
				tmp->function();
				functionStop();

				//it need PAUSE twice, because the exute time to fast. 
				PAUSE
				PAUSE
			}
			break;
		}
	}	

	return ret;
}

/************************************************************************************/
//myGroup common function
void dumpGroup(myGroup *group){
	myGroup *tmp = group;
	system("clear");	//clear cmd window
	printf("################ Group Info ###################\n");
	for(tmp = group; tmp->cases != NULL; tmp++){
		printf(ANSI_COLOR_BLUE"[%d]%s : %s\n"ANSI_COLOR_RESET, tmp->id, tmp->name, tmp->descript);
	}
	printf("###############################################\n");
}

myCase* getCases(myGroup *group,int id){
	myGroup *tmp=NULL;
	for(tmp = group; tmp->cases != NULL; tmp++){
		if(id == tmp->id){
			break;
		}
	}	

	return tmp->cases;
}

/************************************************************************************/
//mySlist common function
void addList(mySlist** list, char *name, char *descript){
	if(*list == NULL){
		/* the first entry of list */
		*list = (mySlist*) malloc(sizeof(mySlist));
		// init linked list
		if(name != NULL)
                	sprintf( (*list)->name, "%s", name);

		if(descript != NULL)
			sprintf( (*list)->descript, "%s", descript);
		(*list)->next = NULL;
	}else{
		//find the last entry
		mySlist *tmp=NULL;
		for(tmp = *list; tmp != NULL; tmp = tmp->next){
			if(tmp->next == NULL)
				break;
		}
		
		tmp->next = (mySlist*) malloc(sizeof(mySlist));
		if(name != NULL)
	                sprintf( (tmp->next)->name, "%s", name);

		if(descript != NULL)
                	sprintf( (tmp->next)->descript, "%s", descript);
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


/************************************************************************************/
//other help common function
void functionStart(void){
     printf("\n***********function start*****************\n");
}

void functionStop(void){
     printf("***********function stop*****************\n");
}

