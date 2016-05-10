#include "mygame.h"


#if 1
void grawTower(const char value, char level){

	char index;
	for(index=1;index <= ((level*2)-1); index++){
		if(index <= (level-value))
			printf(" ");
		else if(index <= (level-value)+(value*2)-1)
			printf("*");
		else
			printf(" ");
	}

	return;
}
void showAllTower(char* t1, char* t2, char* t3, unsigned int level){
	/*	if level=3,
	**	T1
	**	  * 	(1*2)-1 	
	**	 *** 	(2*2)-1
	**	*****	(3*2)-1
	**
	**	So that, (value*2)-1 is the number of '*'
	*/

	const int max=(level*2)-1;
	int index=0;
	for(index=0; index < level; index++){
		
		grawTower(t1[index], level);
		printf(" ");
		grawTower(t2[index], level);
		printf(" ");
		grawTower(t3[index], level);
		printf("\n");
		//printf("t1[%d]=%d, t2[%d]=%d, t3[%d]=%d\n", index, t1[index],index, t2[index],index, t3[index]);
	}
}
void game_init(char* t1, char* t2, char* t3, unsigned int level){
	int index=0;

	for(index=0; index < level; index++){
		/*	all items push to tower1
		**	and array should be the format,
		**	t1[0]=1,t1[1]=2,t1[2]=3,.....t1[level-1]=level
		*/
		t1[index]=index+1;
		t2[index]=0;
		t3[index]=0;
	}

	showAllTower(t1, t2, t3, level);
	return;
}

int isFinish(char* t3,unsigned int level){
	int ret=TRUE;
	int index=0;

	while(index<level){
		if(t3[index] != index+1){
			ret=FALSE;
			break;
		}

		index++;
	}
	
	return ret;
}

unsigned int findTopItem(char* tower, int* targetIndex, unsigned int level){
	unsigned int index=0;
	int found=FALSE;

	for(index=0; index<level; index++){
		if(tower[index] != 0){
			found=TRUE;
			break;
		}
	}

	if(found==TRUE){
		*targetIndex=index;
	}else{
		*targetIndex=level-1;	//empty tower
	}

	//printf("[DEBUG] the top item is at %dth's item, and value is %d in this tower.\n", *targetIndex, tower[*targetIndex]);
	return tower[*targetIndex];
}

int moveProcedure(char* t1, char* t2, unsigned int level){
	/* thie function is used to move the Honoi
	** and move rule as below:
	** [1]T1's top items -> T2's top empty items
	** [2]all items should follow this rule: upper item can not bigger than lower item
	 */

	int index1=0, index2=0;
	unsigned int value1=0, value2=0;

	//RULE 1: check tower1 move target
	if((value1=findTopItem(t1, &index1, level)) == 0){
		printf("Error: Tower1 is no suitable item to move.");
		return -1;
	}

	//RULE 2: check tower1 item is bigger than tower2
	if((value2=findTopItem(t2, &index2, level))!= 0 && value2 < value1){
		printf("Error: the lower item is bigger than upper item.\n");
		return -1;
	}

	//ALL RULE is pass, start move item

	if(index2 == (level-1) && t2[index2]==0){
		//tower2 is empty tower, push to last one
		t2[index2]=value1;	//push to tower2
		t1[index1]=0;	//remove tower1
	}else{
                t2[index2-1]=value1;  //push to tower2
                t1[index1]=0;       //remove tower1
	}

	return 1;
}

void dumpTowerValue(char* t1, char* t2, char* t3, unsigned int level){
        /*      if level=3,
        **      T1
        **        *     (1*2)-1
        **       ***    (2*2)-1
        **      *****   (3*2)-1
        **
        **      So that, (value*2)-1 is the number of '*'
        */

        int index=0;
        for(index=0; index < level; index++){
                printf("t1[%d]=%d, t2[%d]=%d, t3[%d]=%d\n", index, t1[index],index, t2[index],index, t3[index]);
        }
}

void Hanoi(void){
	unsigned int index=0;	//the tower current index
	unsigned int level=0;
	unsigned int step=0;
	char* tower[TOWER_NUMBER];

	//handle with user input
	char key[TOWER_NUMBER]={0};	//player input
	char* pch1=NULL;
	char* pch2=NULL;

	printf("input the Game Level:");
	scanf("%d", &level);

	printf("Game Start, level=%d\n", level);
	printf("Hint: you need move all Tower1's itmes to Tower3, and upper item should not bigger then lower item.\n");

	for(index=0; index < TOWER_NUMBER; index++)
		tower[index]=(char*)malloc(level);

	game_init(tower[0], tower[1], tower[2], level);
	while(!isFinish(tower[2], level)){
				
		printf("Enter Move action(Ex:1>2, it mean tower1 move to tower2):");
		gets(key);
		//printf("[DEBUG] key=%s\n", key);
		if(strlen(key) != 3)
			continue;

		pch1 = strtok (key,">");
		pch2 = strtok (NULL, ">");
		if(moveProcedure(tower[atoi(pch1)-1], tower[atoi(pch2)-1], level) == 1)
			step++;
		
		//show Hanoi 
		showAllTower(tower[0], tower[1], tower[2], level);
	}		

	printf("^.^ >.= =.=\n");
	printf("Congratulation, You have done it in %dth step\n", step);
EXIT:
        for(index=0; index < TOWER_NUMBER; index++)
                free(tower[index]);
	return;
}
#endif
