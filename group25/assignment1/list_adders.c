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

/* add the Item after the current item of the list */
int ListAdd(LIST *list, Item item)
{	
	printf("Got to procedure ListAdd \n");
	
	/* list and current pointer cannot be NULL*/
	if(list == NULL){
		printf("Error in ListAdd : invalid parameter list = NULL \n");
		return -1;
	}
	else if(list -> current == NULL){
		printf("Error in procedure ListAdd: current item in list is Null \n");
		return -1;
	}
	return 0;
}

/*create a new list and return its pointer*/
LIST *ListCreate()
{
	printf("Got to procedure ListCreate \n");

	return NULL;
}

/* add the Item before the current item of the list*/
int ListInsert(LIST *list, Item item)
{	
	/* list and current pointer cannot be NULL*/

	printf("Got to procedure ListInsert \n");
	if(list == NULL){
		printf("Error in ListInsert : invalid parameter list = NULL \n");
		return -1;
	}
	else if(list -> current == NULL){
		printf("Error in procedure ListInsert: current item in list is Null \n");
		return -1;
	}
	

	return 0;
}

/*adds item to the end of list*/
int ListAppend(LIST *list, Item item)
{
	printf("Got to procedure ListAppend \n");
	
	/* list pointer can not be NULL*/
	if(list == NULL){
		printf("Error in ListAppend : invalid parameter list = NULL \n");
		return -1;
	}
	return 0;
}

/*adds item to the front of list*/
int ListPrepend(LIST *list, Item item)
{
	printf("Got to procedure ListPrepend \n");
	/* list pointer can not be NULL*/
	if(list == NULL){
		printf("Error in ListPrepend : invalid parameter list = NULL \n");
		return -1;
	}

	return 0;
}

/*adds list2 to the end of list1*/
void ListConcat(LIST *list1,LIST *list2)
{
	printf("Got to procedure ListConcat \n");
	
	/* both lists' pointer can not be NULL*/
	if(list1 == NULL || list2 == NULL){
		printf("Error in ListConcat : invalid parameter list = NULL \n");
	}
}
