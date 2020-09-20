list_movers.c                                                                                       0000640 �    ��0007640 00000007164 13541013111 013432  0                                                                                                    ustar   tow087                          student                                                                                                                                                                                                                /* NAME: Xudong Li
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
                                                                                                                                                                                                                                                                                                                                                                                                            list_removers.c                                                                                     0000640 �    ��0007640 00000003317 13541013111 013755  0                                                                                                    ustar   tow087                          student                                                                                                                                                                                                                /* NAME: Xudong Li
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
                                                                                                                                                                                                                                                                                                                 mytestlist.c                                                                                        0000640 �    ��0007640 00000003543 13541013111 013302  0                                                                                                    ustar   tow087                          student                                                                                                                                                                                                                /* NAME: Xudong Li
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
                                                                                                                                                             partA1.c                                                                                            0000640 �    ��0007640 00000011014 13541013111 012201  0                                                                                                    ustar   tow087                          student                                                                                                                                                                                                                /* NAME:Tong Wang   
   NSID: tow087 
   Student Number: 11201222
   CMPT 332 Term 1 2019
*/

/* NAME: Xudong Li
   NSID:xul395
   Student Number:11206927
*/

/* widows.h is for */
#include "Square.h"
#include <windows.h>
#include <stdio.h>
#include <ctype.h>

/* define a struct to store infromation for thread*/
struct thread_info {
    DWORD thread_id;/* thread id */
    int thread_count; /* which thread, 1 ,2 ,3.... */
    int size_Number; /* sizeNumber that square() use */
    void *thread; /* point to arch specific thread info */
};
    /* three input arguments */
int threadNumber;
int sizeNumber;
int deadLine;

struct thread_info **thread_Information;

/* We have to print two kinds of information: 1.Time elapsed 2.square size. */

/* inside the thread function to print those information with threadID */
/* count the number square runtime */
int *countSquare;
/* global variable keepRunning and set it TRUE at begining */
int keepRunning = 1;

/* we should check the input arguments are integer or not */
/* implement a function checkNumber */
int checkNumber(char number[])
{
   int i;
   for (i = 0; number[i] != 0; i++)
   {
	   if ((!isdigit(number[i])) || number[i] < 0){
		   return 0;
	   }		   
   }
   return 1;
}

/* get id function to get current id */
int GetID(){
    int i;
    /* use thread id to find the correct children thread's count  */
    for(i = 0; i < threadNumber; i++ ){
        if(thread_Information[i] -> thread_id == GetCurrentThreadId()){
            return i;
        }
    }
    return 0;
}

/* next we need to build the windows thread function */
DWORD WINAPI ThreadFunction(void * threadInfo){
    /* Define SYSTEMTIME for begin time and end time. */
    /*check keepRunning and run square function */
    struct thread_info * thread_Info;
    SYSTEMTIME beginTime;
    SYSTEMTIME endTime;
    double timeElapsed;
    int i, N, threadID, threadCount;
    thread_Info = (struct thread_info *)threadInfo;
    N = thread_Info -> size_Number;
    threadID = thread_Info -> thread_id;
    threadCount = thread_Info -> thread_count;
    /*before start get the begin time */
    GetSystemTime(&beginTime);
    for(i = 1; i <= N; i++){
        if(!keepRunning){
           break; 
        }
        Square(i);        
    }
    /*finished get the end time */
    GetSystemTime(&endTime);
    timeElapsed = (endTime.wMinute - beginTime.wMinute) * 60 + (endTime.wSecond - beginTime.wSecond) + (endTime.wMilliseconds - beginTime.wMilliseconds) * 0.001;
    printf("We have %d threads to run\nNumber %d thread's id is %d and the count of Square() is %d \nThe elasped time of this thread is %f seconds\n", threadNumber, threadCount, threadID, countSquare[GetID()], timeElapsed);
    return 0;
}
/*the main function to run the code */
int main (int argc, char *argv[]){
    /* some variable for main function */

    int i;
    /* check the input validate or not */
    /* first check how many arguments */
    /* then check the arguments are integer or not */
    if(argc !=4){
        printf("Usage: partA1 threads deadline size\n");
        return -1;
    }
    if(checkNumber(argv[1]) && checkNumber(argv[2]) &&checkNumber(argv[3])){

        /*define a thread and thread_info */
        HANDLE *thread;
	    threadNumber = atoi(argv[1]);
	    sizeNumber = atoi(argv[3]);
	    deadLine = atoi(argv[2]);
        

        

        /*allocate memeory */
        /*square running times array */
        countSquare = (int*)malloc(sizeof(int) * threadNumber);
        thread = malloc(sizeof(HANDLE));
        thread_Information = (struct thread_info**)malloc(sizeof(struct thread_info*) * threadNumber);
        if(!thread) perror("malloc");
        /*create the children thread */
        for(i = 0; i < threadNumber; i++){
            if(!(thread_Information[i] = (struct thread_info *)malloc(sizeof(struct thread_info)))){
                perror("malloc");
            }
            /* thread count is i */
            thread_Information[i] -> thread_count = i;
            /* set thread id 0 */
            thread_Information[i] -> thread_id = 0;
            /*store size number */
            thread_Information[i] -> size_Number = i;
            /*call CreateThread function */
            CreateThread(NULL, 0, ThreadFunction, thread_Information[i],0, &(thread_Information[i] -> thread_id));
            
        }
        /*After that we should sleep the parent */
        Sleep(deadLine * 1000);
        /*set keepRunning 0 */
        keepRunning = 0;
    }
    else{
        printf("Please enter validate input. The input arguments must be integer ");
    }
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    square.c                                                                                            0000640 �    ��0007640 00000001040 13541013111 012347  0                                                                                                    ustar   tow087                          student                                                                                                                                                                                                                /* NAME:Tong Wang   
   NSID: tow087 
   Student Number: 11201222
   CMPT 332 Term 1 2019
*/

/* NAME: Xudong Li
   NSID:xul395
   Student Number:11206927
*/


/* This phase only for windows code PartA1,*/

#include "Square.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>



extern int* countSquare;

int Square(int N){
	int threadID = GetID();
	countSquare[threadID]++;
    if(N < 0){
        return -1;
    }
    else if( N == 0 ){
        return 0;
    }
    else{
        return Square(N-1) + 2 * N - 1;
    }
        
    
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                