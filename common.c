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

	if(count==0)
		printf("empty link list.\n");
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

void reverseList(mySlist** list){
	mySlist *cur=NULL;
	mySlist *pre=NULL;

	cur = (*list);
	while(cur != NULL){
		cur = cur->next;
		(*list)->next = pre;
		pre=(*list);
		if(cur != NULL)
			(*list)=cur;
	}
}

void delByName(mySlist** list, const char* name){
	mySlist *pre=NULL;
	mySlist *cur=(*list);

	int found=FALSE;
	while(cur != NULL){
		found=FALSE;	//init it
		if(0 == strncmp(cur->name, name, sizeof(cur->name))){
			found=TRUE;

			//found target entry, delete it
			if(pre == NULL){
				// target entry is first entry
				(*list) = (*list)->next;	//assign list head to second entry
				free(cur);
				cur=(*list);	//next entry is list(second entry)
			}else{
				pre->next=cur->next;
				free(cur);
				cur=pre->next;	//next entry is pre->next
			}

			/* it should have same name entry, 
			** so we don't break it, and keep search it
			*/
		}else{
			//not found
			pre=cur;
			cur=cur->next;
		}
	}
}

/************************************************************************************/
//other help common function
void functionStart(void){
	fgetc(stdin);	//ignore the first input
	printf("\n***********function start*****************\n");
}

void functionStop(void){
     printf("***********function stop*****************\n");
}

