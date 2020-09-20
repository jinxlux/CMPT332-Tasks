/* NAME: Xudong Li
   NSID:xul395
   Student Number:11206927
*/


#include<stdio.h>
#include<stdlib.h>
#include<os.h>
#include"monitor.h"
#include<unistd.h>
#include<sys/time.h>
#include<standards.h>
#include"list.h"

LIST* enterWaitingList = NULL;
LIST* urgentList = NULL;
LIST* writeQ = NULL;
LIST* readQ = NULL;
int muTex, enterSem, urgentSem, writeSem, readSem;
int monBusy = 0;

void MonInit(){
    printf("go to MonInit\n");
    enterWaitingList = ListCreate();
    urgentList = ListCreate();
    writeQ = ListCreate();
    readQ = ListCreate();
    muTex = NewSem(1);
    enterSem = NewSem(0);
    urgentSem = NewSem(0);
    writeSem = NewSem(0);
    readSem = NewSem(0);
}

/*first executable routine for monitor procedure */
void MonEnter(){
    PID pid;
    if(enterWaitingList == NULL || urgentList == NULL || writeQ == NULL || readQ == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
    printf("go to procedure MonEnter()\n");
    printf("process with pid %ld is entering\n",MyPid());
    P(muTex);
    if(monBusy){
        pid = MyPid();
        ListPrepend(enterWaitingList,&pid);
        printf("add %ld to the enterWaitingList.\n",pid);
        V(muTex);
        P(enterSem);
    }else{
        monBusy = 1;
        V(muTex);
    }
}

/*last executable routine for monitor procedure to leave*/
void MonLeave(){
    PID* temp;
    if(enterWaitingList == NULL || urgentList == NULL || writeQ == NULL || readQ == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
    printf("go to procedure MonLeave()\n");
    printf("process with pid %ld is leaving\n",MyPid());
    P(muTex);
    if(ListCount(urgentList)!=0){
        temp = ListTrim(urgentList);
        printf("Process with PID %ld is going to be relased from urgent.\n",*temp);
        V(urgentSem);
        V(muTex);
    }
    else if(ListCount(enterWaitingList)!=0){
        temp = ListTrim(enterWaitingList);
        printf("Process with PID %ld is going to be relased from enterlist.\n",*temp);
        V(enterSem);
        V(muTex);
    }
    else{
        monBusy = 0;
        V(muTex);
    }
}

/*let enter processes wait in some condition variables*/
void MonWait(int cv){
    PID pid;
    PID *temp;
    if(enterWaitingList == NULL || urgentList == NULL || writeQ == NULL || readQ == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
	printf("go to procedure MonWait()\n");
    if(enterWaitingList == NULL || urgentList == NULL || writeQ == NULL || readQ == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
    printf("go to procedure MonEnter()\n");
    P(muTex);
    pid = MyPid();
    if(cv==1){
        ListPrepend(writeQ,&pid);
        printf("add %ld to the writeQ.\n",pid);
    }else if(cv==0){
        ListPrepend(readQ,&pid);
        printf("add %ld to the readQ.\n",pid);
    }
    if(ListCount(urgentList)!=0){
        temp = ListTrim(urgentList);
        printf("Process with PID %ld is going to be relased from urgentList.\n",*temp);
        V(urgentSem);
    }
    else if(ListCount(enterWaitingList)!=0){
        temp = ListTrim(enterWaitingList);
        printf("Process with PID %ld is going to be relased from enterWaitingList.\n",*temp);
        V(enterSem);
    }
    else{
        monBusy = 0;
    }
    V(muTex);
    if(cv==1){
        P(writeSem);
    }else if(cv==0){
        P(readSem);
    }
}

/*reactive the process top of the queue*/
void MonSignal(int cv){
    PID *temp;
    PID pid;
    if(enterWaitingList == NULL || urgentList == NULL || writeQ == NULL || readQ == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
    printf("go to procedure MonSignal()\n");
    P(muTex);
    pid = MyPid();
    if(cv==1){
        if(ListCount(writeQ)!=0){
            temp = ListTrim(writeQ);
            printf("Process with PID %ld is going to be relased from writeQ.\n",*temp);
            ListPrepend(urgentList,&pid);
            printf("add %ld to the urgentQ.\n",pid);
            V(muTex);
            V(writeSem);
            P(urgentSem);
        }else{
            V(muTex);
        }
    }else if(cv==0){
        if(ListCount(readQ)!=0){
            temp = ListTrim(readQ);
            printf("Process with PID %ld is going to be relased from readQ.\n",*temp);
            ListPrepend(urgentList,&pid);
            printf("add %ld to the urgentQ.\n",pid);
            V(muTex);
            V(readSem);
            P(urgentSem);
        }else{
            V(muTex);
        }
    }
}