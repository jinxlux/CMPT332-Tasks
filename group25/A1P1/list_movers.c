/* NAME: Xudong Li
   NSID:xul395
   Student Number:11206927
*/

/* NAME:Tong Wang   
   NSID: tow087 
   Student Number: 11201222
   CMPT 332 Term 1 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*count the number of items in a list*/
int ListCount(LIST *list)
{
	printf("Got to procedure ListCount \n");
	/* list can not be NULL*/
	if(list == NULL){
		printf("Error in ListCount : invalid parameter list = NULL \n");
		return -1;
	}
	return list->size;
}

/* let current item be first item, and return pointer of it*/
void *ListFirst(LIST *list)
{
	printf("Got to procedure ListFirst \n");
	/* list can not be NULL*/
	if(list == NULL){
		printf("Error in ListFirst : invalid parameter list = NULL \n");
		return NULL;
	}
	/*first node can not be NULL*/
	if((list->first) == NULL){
		printf("Error in procedure ListFirst: first item in list is Null \n");
		return NULL;
	}	
	return (list->first) -> data;
}

/* let current item be last item, and return pointer of it*/
void *ListLast(LIST *list)
{
	printf("Got to procedure ListLast \n");
	/* list can not be NULL*/
	if(list == NULL){
		printf("Error in ListLast : invalid parameter list = NULL \n");
		return NULL;
	}
	/*first node can not be NULL*/
	if(list->last == NULL){
		printf("Error in procedure ListLast: last item in list is Null \n");
		return NULL;
	}
	
	return (list->last) -> data;
}

/* advances the list's current node by one, and return pointer of it*/
void *ListNext(LIST *list)
{
	printf("Got to procedure ListNext \n");
	/* list can not be NULL*/
	if(list == NULL){
		printf("Error in ListNext : invalid parameter list = NULL \n");
		return NULL;
	}
	/*current node can not be NULL*/
	if(list->current == NULL){
		printf("Error in procedure ListNext: current item in list is Null \n");
		return NULL;
	}
	else{
		if((list -> current -> next)==NULL){
			printf("Error in procedure ListNext: next item in list is Null \n");
			return NULL;
		}
	}
	return list -> current -> data;
}

/* backs up  the list's current node by one, and return pointer of it*/
void *ListPrev(LIST *list)
{
	printf("Got to procedure ListPrev \n");
	/* list can not be NULL*/	
	if(list == NULL){
		printf("Error in ListPrev : invalid parameter list = NULL \n");
		return NULL;
	}
	/*current node can not be NULL*/
	if(list -> current == NULL){
		printf("Error in procedure ListPrev: current item in list is Null \n");
		return NULL;
	}
	else{
		if((list -> current -> prev)==NULL){
			printf("Error in procedure ListPrev: prev item in list is Null \n");
			return NULL;
		}
	}
	return list -> current -> data;
}

/* returns a pointer to the current item in list.*/
void *ListCurr(LIST *list)
{
	printf("Got to procedure ListCurr \n");
	/* list can not be NULL*/
	if(list == NULL){
		printf("Error in ListCurr : invalid parameter list = NULL \n");
		return NULL;
	}
	/*current node can not be NULL*/
	if(list -> current == NULL){
		printf("Error in ListCurr: current item in list is Null \n");
		return NULL;
	}
	return (list -> current) -> data;
}

/*searches list starting at the current item until the end is reached or a match is found*/
void *ListSearch(LIST *list, int (*comparator)(Item, Item), Item comparisonArg)
{
	printf("Got to procedure ListSearch \n");
	/* list can not be NULL*/	
	if(list == NULL){
		printf("Error in ListSearch : invalid parameter list = NULL \n");
		return NULL;
	}
	/*pointer to routines can not be NULL*/
	if(comparator == NULL){
		printf("Error in ListSearch : invalid parameter comparator\n");
		return NULL;
	}
	/*current node can not be NULL*/
	if(list -> current == NULL){
		printf("Error in ListCurr: current item in list is Null \n");
		return NULL;
	}	

	return (list -> current) -> data;
}
