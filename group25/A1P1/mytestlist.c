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

int main(int argc, char *argv[])
{	
	/* some lists for test */
	LIST list = {0,NULL,NULL,NULL,0};
	LIST list1 = {0,NULL,NULL,NULL,0};
	LIST list2 = {0,NULL,NULL,NULL,0};

	ListCreate();
	ListCount(&list);
	/*error should report here for ListFirst*/
	ListFirst(&list);
	/*error should report here for ListLast (last = NULL)*/
	ListLast(&list);
	/*error should report here  for ListNext (next = NULL)*/
	ListNext(&list);
	/*error should report here  for ListPrev (prev = NULL)*/
	ListPrev(&list);
	/*error should report here  for ListCurr (curr = NULL)*/
	ListCurr(&list);
	/*error should report here  for ListAdd (curr = NULL,can not add after current item)*/
	ListAdd(&list,NULL);
	/*error should report here  for ListInsert (curr = NULL,can not add before current item)*/
	ListInsert(&list,NULL);
	ListAppend(&list,NULL);
	ListPrepend(&list,NULL);
	/*error should report here  for ListRemove (curr = NULL,can not delete)*/
	ListRemove(&list);
 	ListConcat(&list1,&list2);
 	/*error should report here  for ListFree (itemFree = NULL, no routine to free Item)*/
 	ListFree(&list, NULL);
	ListTrim(&list);
 	/*error should report here  for ListSearch (comparator = NULL, no routine to free Item)*/
	ListSearch(&list, NULL, NULL);
	
	/* given NULL pointer of list to show Errors. Except ListCreate ,*/
	/* all should report error*/
	ListCreate();
	ListCount(NULL);
	ListFirst(NULL);
	ListLast(NULL);
	ListNext(NULL);
	ListPrev(NULL);
	ListCurr(NULL);
	ListAdd(NULL,NULL);
	ListInsert(NULL,NULL);
	ListAppend(NULL,NULL);
	ListPrepend(NULL,NULL);
	ListRemove(NULL);
 	ListConcat(NULL,&list2);
 	ListFree(NULL, NULL);
	ListTrim(NULL);
	ListSearch(NULL, NULL, NULL);
	
	return 0;
}
