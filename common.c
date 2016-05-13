#include "common.h"

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
