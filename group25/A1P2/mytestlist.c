/* NAME: Xudong Li
   NSID:xul395
   Student Number:11206927
*/

/* NAME:Tong Wang   
   NSID: tow087 
   Student Number: 11201222
   CMPT 332 Term 1 2019
   
   group: 25
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[])
{	
	int i;
	int *first;
	int *last;
	int *current;
	int *temp;
	int *tempfirst;
	int *templast;
	int lsize;
	int templsize;
	
	/*array of int items for adding to the list*/
	int testArray[200];
	
	
	/* create lists randomly */
	LIST* newList1;
	LIST* newList2; 
	LIST* newList3;
	LIST* newList4;
	LIST* newList5;
	LIST* newList6;
	LIST* newList7;
	LIST* newList8;
	LIST* newList9;

	printf("\ntest ListCreate here\n");
	newList1 = ListCreate();
	newList2 = ListCreate();
	newList3 = ListCreate();
	newList4 = ListCreate();
	


	/*test whether all lists are created successfully*/
	if(!(newList1 -> used)){
		printf("Error in Test: List1 is not created\n");
		return 0;
	}
	if(!(newList2 -> used)){
		printf("Error in Test: List2 is not created\n");
		return 0;
	}
	if(!(newList3 -> used)){
		printf("Error in Test: List3 is not created\n");
		return 0;
	}
	if(!(newList4 -> used)){
		printf("Error in Test: List4 is not created\n");
		return 0;
	}

	printf("Test for ListCreate did not report any errors \n");
	
	printf("test ListAdd: keep adding item after the end; In this case, current->next == NULL\n");
	printf("extra credit: memory reallocation should report below when adding items\n");
	/*test ListAdd: keep adding item after the end*/
	for(i=0;i<10;i++){
		testArray[i] = i;
		ListAdd(newList1,&testArray[i]);
	}
	
	printf("test ListAdd: test size and items in the list after adding items\n");
	/*test ListCount&ListAdd*/
	if(ListCount(newList1)!=10){
		printf("Error in Test ListCount&ListAdd: list size should be 0\n");
		return 0;
	}
	
	/*test ListFirst&ListAdd*/
	first = (int*)ListFirst(newList1);
	if(*first != 0){
		printf("Error in Test ListFirst&ListAdd: First item should be zero\n");
		return 0;
	}
	
	/*test last item of ListAdd*/
	last = (int*)(newList1->last->data);
	if(*last != 9){
		printf("Error in Test ListAdd: last item should be 9\n");
		return 0;
	}
	
	/*test ListNext&ListAdd*/
	for(i=1;i<10;i++){
		current = (int*)ListNext(newList1);
		if(*current != i){
			printf("Error in Test ListNext&ListAdd: current item should be %d, but not %d\n",i,*current);
			return 0;
		}
	}
	printf("test ListAdd: test Successfully, no errors reported\n");
	
	printf("try to use ListNext to go beyond the end of list\n");
	/*test ListNext: go beyond the end*/
	current = (int*)ListNext(newList1);
	if(current != NULL){
		printf("Error in Test ListNext: beyond the end; NULL should return\n");
		return 0;
	}
	printf("test ListNext successfully\n");
	
	/*test ListAdd: add item after current item (add item between 
	current and current->next & current->next != NULL)*/
	printf("test ListAdd: add item between current and current->next & current->next != NULL)\n");
	testArray[10] = 10;
	ListFirst(newList1);
	i = ListAdd(newList1,&testArray[10]);
	if(i!=0){
		printf("Error in Test ListAdd: 0 should return\n");
		return 0;
	}
	current = (int *)ListCurr(newList1);
	if(*current!=10){
		printf("Error in Test ListAdd&ListCurr: 10 should still be first item\n");
		return 0;
	}

	
	current = (int*)ListFirst(newList1);
	if(*current!=0){
		printf("Error in Test ListAdd&ListFirst: 0 should still be first item\n");
		return 0;
	}
	/*go from first item to the item after new added item, then go previosly*/
	current = (int*)ListNext(newList1);
	if(*current!=10){
		printf("Error in Test ListAdd&ListNext: 10 should still be next item\n");
		return 0;
	}
	
	current = (int*)ListNext(newList1);
	if(*current!=1){
		printf("Error in Test ListAdd&ListNext: 1 should still be next item after adding 10\n");
		return 0;
	}
	
	current = (int*)ListPrev(newList1);
	if(*current!=10){
		printf("Error in Test ListAdd&ListPrev: 10 should be prev item\n");
		return 0;
	}
	current = (int*)ListPrev(newList1);
	if(*current!=0){
		printf("Error in Test ListAdd&ListPrev: 0 should be prev item\n");
		return 0;
	}
	if(ListCount(newList1)!=11){
		printf("Error in Test ListCount&ListCount: list size should be 11\n");
		return 0;
	}
	printf("test ListAdd: test successfully\n");
	
	printf("test ListInsert: insert when current is the first Item\n");
	/*test ListInsert: insert when current is the first Item*/
	ListFirst(newList1);
	testArray[11] = 11;
	i = ListInsert(newList1,&testArray[11]);
	if(i!=0){
		printf("Error in Test ListInsert: 0 should return\n");
		return 0;
	}
	current = (int *)ListCurr(newList1);
	if(*current != 11){
		printf("Error in Test ListInsert&ListCurr: 11 should be current item\n");
		return 0;	
	}
	current = (int*)(newList1->first->data);
	if(*current != 11){
		printf("Error in Test ListInsert: 11 should be first item\n");
		return 0;	
	}
	current = (int*)(newList1->first->next->data);
	if(*current != 0){
		printf("Error in Test ListInsert: 0 should be next item of 11\n");
		return 0;	
	}
	if(ListCount(newList1)!=12){
		printf("Error in Test ListCount&ListCount: list size should be 12\n");
		return 0;
	}
	
	printf("test ListInsert successfully\n");
	
	printf("test ListInsert: insert when current is the last Item (current->prev != NULL)\n");
	/*test ListInsert: insert when current is the last Item*/
	current = (int*)ListLast(newList1);
	if(*current != 9){
		printf("Error in Test ListLast: 9 should be current item\n");
		return 0;	
	}
	testArray[12] = 12;
	i = ListInsert(newList1,&testArray[12]);
	if(i!=0){
		printf("Error in Test ListInsert from last item: 0 should return\n");
		return 0;
	}	
	current = (int *)ListCurr(newList1);
	if(*current != 12){
		printf("Error in Test ListInsert&ListCurr: 12 should be current item\n");
		return 0;	
	}
	
	/*go next & go previous*/
	current = (int*)(newList1->last->prev->data);
	if(*current != 12){
		printf("Error in Test ListInsert: 12 should be item before the last\n");
		return 0;	
	}	
	current = (int*)(newList1->last->prev->prev->data);
	if(*current != 8){
		printf("Error in Test ListInsert: 8 should be item before the last\n");
		return 0;	
	}
	current = (int*)(newList1->last->prev->prev->next->data);
	if(*current != 12){
		printf("Error in Test ListInsert: 12 should be item after 8\n");
		return 0;	
	}
	current = (int*)(newList1->last->prev->prev->next->next->data);
	if(*current != 9){
		printf("Error in Test ListInsert: 9 should be item after 12\n");
		return 0;	
	}
	
	if(ListCount(newList1)!=13){
		printf("Error in Test ListCount&ListCount: list size should be 13\n");
		return 0;
	}	
	printf("test ListInsert successfully\n");
	
	printf("test ListAppend\n");
	/*test ListAppend*/	
	testArray[13] = 13;
	i = ListAppend(newList1,&testArray[13]);
	if(i!=0){
		printf("Error in Test ListAppend from last item: 0 should return\n");
		return 0;
	}
	printf("test ListAppend: test whether current,size,last,prev..are all corrent\n");
	current = (int *)ListCurr(newList1);
	if(*current != 13){
		printf("Error in Test ListAppend&ListCurr: 13 should be current item\n");
		return 0;	
	}
	current = (int *)(newList1->last->data);
	if(*current != 13){
		printf("Error in Test ListAppend: 13 should be last item\n");
		return 0;	
	}
	current = (int *)(newList1->last->prev->data);
	if(*current != 9){
		printf("Error in Test ListAppend: 9 should be item before the last\n");
		return 0;	
	}		
	current = (int *)(newList1->last->prev->next->data);
	if(*current != 13){
		printf("Error in Test ListAppend: 13 should be item after 12\n");
		return 0;	
	}
	if(ListCount(newList1)!=14){
		printf("Error in Test ListCount&ListCount: list size should be 14\n");
		return 0;
	}
	printf("test successfully\n");		
	
	printf("test ListPrepend\n");	
	/*test ListPrepend*/
	testArray[14] = 14;
	i = ListPrepend(newList1,&testArray[14]);
	if(i!=0){
		printf("Error in Test ListPrepend from last item: 0 should return\n");
		return 0;
	}	
	printf("test ListPrepend: test whether current,size,first,next..are all corrent\n");
	current = (int *)ListCurr(newList1);
	if(*current != 14){
		printf("Error in Test ListPrepend&ListCurr: 14 should be current item\n");
		return 0;	
	}
	current = (int *)(newList1->first->data);
	if(*current != 14){
		printf("Error in Test ListPrepend: 13 should be firsr item\n");
		return 0;	
	}
	current = (int *)(newList1->first->next->data);
	if(*current != 11){
		printf("Error in Test ListPrepend: 11 should be item after the first\n");
		return 0;	
	}		
	current = (int *)(newList1->first->next->prev->data);
	if(*current != 14){
		printf("Error in Test ListPrepend: 14 should be item before 11\n");
		return 0;	
	}
	if(ListCount(newList1)!=15){
		printf("Error in Test ListPrepend&ListCount: list size should be 15\n");
		return 0;
	}
	
	printf("test ListPrepend successfully\n");
	
	printf("test ListConcat\n");
	printf("test ListConcat when list1&list2 are non-empty lists\n");
	/*test ListConcat*/	
	testArray[15] = 15;
	i = ListPrepend(newList2,&testArray[15]);
	if(i!=0){
		printf("Error in Test ListPrepend from last item: 0 should return\n");
		return 0;
	}
	current = (int *)ListCurr(newList1);
	ListConcat(newList1,newList2);
	temp = (int *)ListCurr(newList1);
	if(*current != *temp){
		printf("Error in Test ListConcat: current item should be same as previous list1\n");
		return 0;	
	}
	current = (int *)(newList1->last->data);
	if(*current != 15){
		printf("Error in Test ListConcat: 15 should be last item now\n");
		return 0;	
	}
	current = (int *)(newList1->last->prev->data);
	if(*current != 13){
		printf("Error in Test ListConcat: 13 should be item before 15\n");
		return 0;	
	}
	current = (int *)(newList1->last->prev->next->data);
	if(*current != 15){
		printf("Error in Test ListConcat: 15 should be item after 13\n");
		return 0;	
	}		
	if(ListCount(newList1) != 16){
		printf("Error in Test ListConcat: size of list1 should be 16\n");
		return 0;	
	}
	if(newList2->used){
		printf("Error in Test ListConcat: newList2 should not exist\n");
		return 0;	
	}
	newList5 = ListCreate();
	if(newList5!=newList2){
		printf("Error in Test ListConcat: memory for newList2 should be used by newList5\n");
		return 0;	
	}
	newList6 = ListCreate();
	if((newList4+1)!=newList6){
		printf("Error in Test ListConcat: original space for next list created should after newList4\n");
		return 0;	
	}
	
	printf("test ListConcat: ListConcat(newList1,newList6) when newList6 is empty\n");
	/*test special case: newList6 is empty*/
	ListConcat(newList1,newList6);
	if(newList6->used){
		printf("Error in Test ListConcat: newList6 should not exist\n");
		return 0;	
	}
	first = (int *)ListFirst(newList1);
	last = (int *)ListLast(newList1);
	lsize = ListCount(newList1);
	current = (int *)ListCurr(newList1);
	
	printf("test ListConcat: ListConcat(newList4,newList1) when newList4 is empty\n");
	ListConcat(newList4,newList1);
	if(newList1->used){
		printf("Error in Test ListConcat: newList6 should not exist\n");
		return 0;	
	}
	temp = (int *)ListCurr(newList4);
	templsize = ListCount(newList4);
	if(*current != *temp){
		printf("Error in Test ListConcat: current item of newList4 should be same as previous list1\n");
		return 0;	
	}
	tempfirst = (int *)ListFirst(newList4);
	if(*first != *tempfirst){
		printf("Error in Test ListConcat: first item of newList4 should be same as previous list1\n");
		return 0;	
	}
	templast = (int *)ListLast(newList4);
	if(*last != *templast){
		printf("Error in Test ListConcat: last item of newList4 should be same as previous list1\n");
		return 0;	
	}
	if(lsize != templsize){
		printf("Error in Test ListConcat: size of newList4 should be same as previous list1\n");
		return 0;	
	}
	
	printf("test ListConcat successfully\n");
	
	printf("test reallocate list pool: realloc message should reported below\n");
	newList7 = ListCreate();
	newList8 = ListCreate();
	newList9 = ListCreate();
	
	if(!(newList7 -> used)){
		printf("Error in Test: List7 is not created\n");
		return 0;
	}
	if(!(newList8 -> used)){
		printf("Error in Test: List8 is not created\n");
		return 0;
	}
	if(!(newList9 -> used)){
		printf("Error in Test: List9 is not created\n");
		return 0;
	}

	printf("test reallocate node pool of ListInsert: realloc message should reported below\n");
	for(i=16;i<25;i++){
		testArray[i] = i;
		ListInsert(newList7,&testArray[i]);
	}
	
	printf("test reallocate node pool of ListAppend: realloc message should reported below\n");
	for(i=25;i<65;i++){
		testArray[i] = i;
		ListAppend(newList7,&testArray[i]);
	}
	printf("test reallocate node pool of ListPrepend: realloc message should reported below\n");
	for(i=65;i<150;i++){
		testArray[i] = i;
		ListPrepend(newList7,&testArray[i]);
	}
	
	printf("\nTest Errors of routines below: Error message should be printed out\n\n");		
	
	/* given NULL pointer of list to show Errors. Except ListCreate ,*/
	/* all should report error*/
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
 	ListConcat(NULL,NULL);
 	ListFree(NULL, NULL);
	ListTrim(NULL);
	ListSearch(NULL, NULL, NULL);
	
	printf("\nEnd Test\n");	
	
	return 0;
}
