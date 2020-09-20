/* NAME: Xudong Li
   NSID:xul395
   Student Number:11206927
*/

/* NAME:Tong Wang   
   NSID: tow087 
   Student Number: 11201222
   CMPT 332 Term 1 2019

   group25
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*remove the current node, and return the pointer of it*/
void *ListRemove(LIST *list)
{	
	/*for saving the current item*/
	void *removedCurrentItem;
	printf("Got to procedure ListRemove \n");
	if(list == NULL){
		printf("Error in ListRemove : invalid parameter list = NULL \n");
		return NULL;
	}
	else if(list->current == NULL){
		printf("Error in ListRemove : current item is NULL \n");
		return NULL;
	}
	else{
		removedCurrentItem = list->current->data;
	}
	/*TODO: delete the current item after*/
	return removedCurrentItem;
}

/*delete list, free all items in it*/
void ListFree(LIST *list, void (*itemFree)(Item))
{
	printf("Got to procedure ListFree \n");

	if(list == NULL){
		printf("Error in ListFree : invalid parameter list = NULL \n");
	}
	else if(itemFree == NULL){
		printf("Error in ListFree : invalid parameter itemFree = NULL \n");
	}
	else{
		/* free the list*/
	}	
}

/*Return last item and take it out of list, */
/*the current pointer shall be the new last item in the list.*/
void *ListTrim(LIST *list)
{
	/*for saving the current last item*/
	void *removedLstItem;
	
	printf("Got to procedure ListTrim \n");
	if(list == NULL){
		printf("Error in ListTrim : invalid parameter list = NULL \n");
		return NULL;
	}
	else if(list->last == NULL){
		printf("Error in ListTrim : last item is NULL \n");
		return NULL;
	}
	else{
		removedLstItem = list->last->data;
		/*move*/
		list->last = list->last->prev;
		list->current = list->last;
		/*TODO: delete the last item after*/
	}

	return removedLstItem;
}
