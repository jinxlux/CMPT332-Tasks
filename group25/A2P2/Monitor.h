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
#ifndef _MONITOR_
#define _MONITOR_



/*
function prototypes
*/

void MonEnter();
void MonLeave();
void MonWait(int cv);
void MonSignal(int cv);
void MonInit(int numOfCv);




#endif