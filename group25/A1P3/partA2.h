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
#include <unistd.h>
#include <standards.h>
#include <os.h>
/*
    define a struct of thread infomation to store count number of thread, the identifier of thrad,
    the size number need to tell square function, the start time and running flag(it's little different to A1
    because we don't have global varibale to check the thread is running or not)
*/

struct UBCpthread_threadInfo
{
    int threadCount;
    int threadID;
    int sizeNumber;
    long startTime;
    int running;
};