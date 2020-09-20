/* NAME:Tong Wang   
   NSID: tow087 
   Student Number: 11201222
   CMPT 332 Term 1 2019
   
*/

#include<stdio.h>
#include<stdlib.h>
#include<os.h>
#include"monitor.h"
#include<unistd.h>
#include<sys/time.h>
#include<standards.h>
#include"list.h"

/* 
   Lists for each CV and enterQ, urgentQ
*/

LIST* enterQList; 
LIST* urgentQList; 
LIST* readList; 
LIST* writeList;

/* 
    semaphores for enterQ, urgentQ, and mutex.
    semaphores for each condition variable.
    global variable to indicate if monitor occupied.
*/
int muTex, enterQSem, urgentQSem, writeSem, readSem;
int monBusy = 0;

void MonEnter(){
    PID pid;
    printf("Monitor enter then acquire(mutex) and check monitor occupied or not\n");
    P(muTex);
    if(monBusy){
        pid = MyPid();
        ListPrepend(enterQList,&pid);
        printf("add to waiting queue and then release mustex\n");
        V(muTex);
        P(enterQSem);
    }
    else{
        monBusy = 1;
        V(muTex);
    }
}
void MonLeave(){
    PID *pid;
    printf("Monitor leave then acquire(mutex) and check urgentq, enterQ, and monBusy\n");
    P(muTex);
    if(ListCount(urgentQList) != 0){
        pid = ListTrim(urgentQList);
        printf("take item off urgentq, the item pid is %ld \n", *pid);
        V(urgentQSem);
        V(muTex);
    }
    else if(ListCount(enterQList) != 0){
        pid = ListTrim(enterQList);
        printf("take item off enterQ, the item pid is %ld \n", *pid);
        V(enterQSem);
        V(muTex);
    }
    else{
        monBusy = 0;
        V(muTex);
    }
}
void MonWait(int cv){
    PID pid;
    PID *temp;
    printf("Monitor wait then acquire(mutex) and check cv, urgentq, enterQ, and monBusy\n");
    P(muTex);
    pid = MyPid();
    if(cv == 1){
        ListPrepend(writeList,&pid);
        printf("add %ld to the writeQ.\n",pid);
    }else if(cv==0){
        ListPrepend(readList,&pid);
        printf("add %ld to the readQ.\n",pid);
    }
    if(ListCount(urgentQList) != 0){
        temp = ListTrim(urgentQList);
        printf("take item off urgentq, the item pid is %ld \n", *temp);
        V(urgentQSem);
        V(muTex);
    }
    else if(ListCount(enterQList) != 0){
        temp = ListTrim(enterQList);
        printf("take item off enterQ, the item pid is %ld \n", *temp);
        V(enterQSem);
        V(muTex);
    }
    else{
        monBusy = 0;
        V(muTex);
    }
    if(cv==1){
        P(writeSem);
    }else if(cv==0){
        P(readSem);
    }

}
void MonSignal(int cv){
    PID pid;
    PID *temp;
    printf("Monitor wait then acquire(mutex) and check cvlist \n");
    P(muTex);
    pid = MyPid();
    if(cv == 1){
        if(ListCount(writeList) != 0){
            temp = ListTrim(writeList);
            printf("Process with PID %ld is going to be relased from writelist.\n",*temp);
            ListPrepend(urgentQList,&pid);
            printf("add %ld to the urgentList.\n",pid);
            V(muTex);
            V(writeSem);
            P(urgentQSem);

        }
        else{
            V(muTex);
        }
    }
    else if (cv == 0){
        if(ListCount(readList) != 0){
            temp = ListTrim(readList);
            printf("Process with PID %ld is going to be relased from readList.\n",*temp);
            ListPrepend(urgentQList,&pid);
            printf("add %ld to the urgentList.\n",pid);
            V(muTex);
            V(readSem);
            P(urgentQSem);
        }
        else{
            V(muTex);
        }        
    }
}
void MonInit(){
    printf("MonInit\n");
    enterQList = ListCreate();
    urgentQList = ListCreate();
    writeList = ListCreate();
    readList = ListCreate();
    muTex = NewSem(1);
    enterQSem = NewSem(0);
    urgentQSem = NewSem(0);
    writeSem = NewSem(0);
    readSem = NewSem(0);
}