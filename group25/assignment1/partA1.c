/* NAME:Tong Wang   
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
}