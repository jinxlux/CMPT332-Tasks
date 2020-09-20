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
#include <sys/time.h>
#include "square.h"
#include "partA2.h"

/* define variable thread, threadNumber, size, deadline, runnint to see if the thread is running and 
 an array index is the count of thread
*/
struct UBCpthread_threadInfo **UBCthread;
int threadNumber;
int size;
int deadLine;
int running;
int *countSquare;
/* 
 implement a getID function base on pthread function MyPid()
 use this function to get thread and use in square function
*/
int GetID(){
    int result;
    result = MyPid();
    return result;
}
/* 
 implement a UBCpthreadfuction(void* thread) input parameter is UBCpthread_threadInfo
 inside the thread we could calculate the time spent and print information
*/
void UBCpthreadFunction(void *threadInfo){
/* 
declare varibale timestamp, i for for loop using, ubcpthread struct, thread_id, thread_count
thead_id is the id of thread 
*/
    long beginTime, endTime, timeSpent;
    int i;
    struct UBCpthread_threadInfo *inputThreadinfo;
    int thread_id, thread_count;
    inputThreadinfo = (struct UBCpthread_threadInfo*)threadInfo;
    thread_id = inputThreadinfo -> threadID;
    thread_count = inputThreadinfo -> threadCount;
/* 
use Time() function to store the begin time in the global UBCthread array, index is thread_count
*/   
    UBCthread[thread_count] -> startTime = Time();
    
/* 
*/
/* 
set running =1
*/
    inputThreadinfo -> running = 1;
/* 
call square() function
*/    
    for(i = 1; i <= size; i++){
        Square(i);
    }
    /* 

    */
    /* 
    store end time and then calulate the time spent
    */
    endTime = Time();
    beginTime = UBCthread[thread_id] -> startTime;
    timeSpent = endTime - beginTime;
    printf("This is the number %d thread.The thread's id is %d and it spent time: %ld clock ticks:\nNumber of square() called is %d\n ",
           thread_count,thread_id, timeSpent, countSquare[thread_id]);
    inputThreadinfo -> running = 0;
    


}
/* 
this is the parent thread function, use running to check runnint status, use sleep() to sleep the function
similar to UBCpthreadFunction just need check 
*/
void UBCparent(){
    int i;
    int timeSpent;
    long beginTime, endTime;
    sleep(deadLine);
    for(i = 0; i < threadNumber; i++){
        if(UBCthread[i] -> running == 0){
            break;
        }
        if(Kill(UBCthread[i] -> threadID) == UBCthread[i] -> threadID){
            endTime = Time();
            beginTime = UBCthread[i] -> startTime;
            timeSpent = endTime - beginTime;
            printf("This is the number %d thread.The thread's id is %d and it spent time: %d clock ticks:\nNumber of square() called is %d\n ",
            i,UBCthread[i] -> threadID, timeSpent, countSquare[i]);
        }
        
    }
}
/*
mainp function,  
*/
 
int mainp(int argc, char *argv[]){
    int i;
    if(argc!=4){
        printf("Please enter like that partA2 threadCount deadLine size\n");
        return -1;
    }
    threadNumber = atoi(argv[1]);
    deadLine = atoi(argv[2]);
    size= atoi(argv[3]);
    UBCthread = (struct UBCpthread_threadInfo **)malloc(threadNumber * sizeof (struct UBCpthread_threadInfo *));
    if(threadNumber<1||deadLine<0||size<0){
        printf("Error in mainp(): invalid parameter %d\t%d\t%d\n", threadNumber,deadLine,size);
        return -1;
    }
    countSquare = (int *)malloc(sizeof(int)*threadNumber);
    for(i =0; i< threadNumber; i++)
        {
            countSquare[i] = 0;
        }
    for (i = 0; i < threadNumber; i++) {
        if(!(UBCthread[i]=(struct UBCpthread_threadInfo *)malloc(sizeof(struct UBCpthread_threadInfo)))){
            printf("malloc error\n");
            return 0;
        }
        UBCthread[i]->sizeNumber = size;
        UBCthread[i]->threadCount = i;
        if((UBCthread[i]->threadID = Create(UBCpthreadFunction, 1600000, NULL,(void *)UBCthread[i], NORM, USR))<0){
            printf("thread created error\n");
        }
    }
    Create(UBCparent, 16000000,"main", NULL, NORM, USR);
    return 0;
}
/* 
*/
/* 
*/
/* 
*/