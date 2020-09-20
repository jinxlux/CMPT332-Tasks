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

#include<stdio.h>
#include<stdlib.h>
#include<os.h>
#include<Monitor.h>
#include<unistd.h>
#include<sys/time.h>
#include<standards.h>
#include"list.h"

/*struct for saving message of IPC */
typedef struct message
{
    int msgType;
    int cvType;
} MESSAGE;

/*PID for the server process*/
PID ServerPid = PNUL;
/*save the number of condition variables needed*/
int cvNum = 0;
/*list of lists for CVs*/
LIST** listPSpace = NULL;
/*list for buffering entering processes*/
LIST* enterWaitingList = NULL;
/*list for saving signaler processes*/
LIST* urgentList = NULL;
/*indicate whether the monitor is occupied by a process*/
int occupied = 0;
/*length of the MESSAGE*/
int* length;

/*serve all requests*/
PID MonServer(){
	MESSAGE* msg;
    PID* pid;
    PID* pidDinamic;
    int pidDinamicTemp;
    int* msgLength;
    PID* temp;
    msg = (MESSAGE *)malloc(sizeof(MESSAGE)*10);	
    pid = (PID *)malloc(sizeof(long)*10);	
    msgLength = (int *)malloc(sizeof(int)*10);
    printf("go to proc MonServer: wait for require\n");
	for(;;){
		msg = (MESSAGE*) Receive(pid,msgLength);
        printf("server receiv pid %ld\n",*pid);
        /*check msg to decide add or relaese: enter */
        if((msg->msgType)== 0){
            printf("receive msg from Enter\n");
            if(occupied){
                pidDinamic = (PID *)malloc(sizeof(long));
                *pidDinamic = pid[0];
                printf("add %ld to enter waiting list\n",*pidDinamic);
                ListPrepend(enterWaitingList,pidDinamic);
            }else{
                printf("first enter: not to add to enter list\n");
                Reply(*pid, msg, *msgLength);
                occupied = 1;
            }
        }
        /*check msg to decide add or relaese: leave */
        else if((msg->msgType)== 1){
            printf("receive msg from leave\n");
            Reply(*pid, msg, *msgLength);
            if(ListCount(urgentList)!=0){
                temp = (PID*)ListTrim(urgentList);
                printf("Process with PID %ld is going to be relased from urgent.\n",*temp);
                pidDinamicTemp = *temp;
                Reply(pidDinamicTemp, msg, *msgLength);
                free(temp);
            }else if(ListCount(enterWaitingList)!=0){
                temp = (PID*)ListTrim(enterWaitingList);
                printf("Process with PID %ld is going to be relased from enterL.\n",*temp);
                pidDinamicTemp = *temp;
                Reply(pidDinamicTemp, msg, *msgLength);
                free(temp);
            }else{
                occupied = 0;
            }
        }
        /*check msg to decide add or relaese: wait */
        else if ((msg->msgType)== 2){
            printf("receive msg from wait\n");
            pidDinamic = (PID *)malloc(sizeof(long));
            *pidDinamic = pid[0];
            ListPrepend(listPSpace[msg->cvType],pidDinamic);
            printf("add %ld to a wait Q with index %d.\n",*pidDinamic, msg->cvType);
            if(ListCount(urgentList)!=0){
                temp = (PID*)ListTrim(urgentList);
                printf("Process with PID %ld is going to be relased from urgent.\n",*temp);
                pidDinamicTemp = *temp;
                Reply(pidDinamicTemp, msg, *msgLength);
                free(temp);
            }else if(ListCount(enterWaitingList)!=0){
                temp = (PID*)ListTrim(enterWaitingList);
                pidDinamicTemp = *temp;
                printf("Process with PID %ld is going to be relased from enterL.\n",*temp);
                Reply(pidDinamicTemp, msg, *msgLength);
                free(temp);
            }else{
                occupied = 0;
            }
        }
        /*check msg to decide add or relaese: signal */
        else if ((msg->msgType)== 3){
            printf("receive msg from signal\n");
            if(ListCount(listPSpace[msg->cvType])!=0){
                pidDinamic = (PID *)malloc(sizeof(long));
                *pidDinamic = pid[0];
                ListPrepend(urgentList,pidDinamic);
                printf("add %ld to the urgentList.\n",*pidDinamic);
                temp = (PID*)ListTrim(listPSpace[msg->cvType]);
                printf("Process with PID %ld is going to be relased from wait q with index %d\n",*temp, msg->cvType);
                pidDinamicTemp = *temp;
                Reply(pidDinamicTemp,msg,*msgLength);
                free(temp);
            }else{
                Reply(*pid, msg, *msgLength);
            }
        }
	}

}

/*initialize all variables*/
void MonInit(int numOfCv){
	int i;
	cvNum = numOfCv;
    /* allocate memory for length of msg*/
    length = (int*) malloc(sizeof(int));
    *length = sizeof(MESSAGE);
    printf("go to proc MonInit\n");
	if(cvNum==0){
		printf("Error: no conditional variables allowed");
		exit(0);
	}
	if(listPSpace == NULL){
		listPSpace = (LIST **)calloc(numOfCv,sizeof(LIST*));
	}
	for(i=0;i<numOfCv;i++){
		listPSpace[i] = ListCreate();
	}
	enterWaitingList = ListCreate();
    urgentList = ListCreate();
    while(ServerPid == PNUL){
        ServerPid = Create((void(*)()) MonServer, 16000, NULL, NULL, NORM, USR);
    }
    printf("ServerPid: %ld\n",ServerPid);
}

/*first executable routine for monitor procedure */
void MonEnter(){
    MESSAGE* enterMsg = (MESSAGE*) malloc(sizeof(MESSAGE) * 10);   
    enterMsg -> msgType = 0;
    enterMsg -> cvType = 0;
    printf("go to procedure MonEnter()\n");
    if(ServerPid == PNUL || cvNum==0 || listPSpace == NULL || enterWaitingList == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
    printf("MonEnter: myPid:%ld\n",MyPid());
    Send(ServerPid,enterMsg,length);
    printf("successfully receive enterMsg reply\n");
    free(enterMsg);
}

/*last executable routine for monitor procedure to leave*/
void MonLeave(){

    MESSAGE* leaveMsg;
    leaveMsg = (MESSAGE*) malloc(sizeof(MESSAGE) * 10);
    leaveMsg -> msgType = 1;
    leaveMsg -> cvType = 0;

    if(ServerPid == PNUL || cvNum==0 || listPSpace == NULL || enterWaitingList == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
    printf("go to procedure MonLeave()\n");
    Send(ServerPid,leaveMsg,length);
    printf("successfully receive leaveMsg reply\n");
    free(leaveMsg);
}

/*let enter processes wait in some condition variables*/
void MonWait(int cv){
    MESSAGE* waitMsg;
    waitMsg = (MESSAGE*) malloc(sizeof(MESSAGE) * 10);
    waitMsg -> msgType = 2;
    waitMsg -> cvType = cv;
    if(ServerPid == PNUL || cvNum==0 || listPSpace == NULL || enterWaitingList == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
    printf("go to procedure MonSignal()\n");
    Send(ServerPid,waitMsg,length);
    printf("successfully receive waitMsg reply\n");
    free(waitMsg);

}

/*reactive the process top of the queue*/
void MonSignal(int cv){
    MESSAGE* signalMsg;
    signalMsg = (MESSAGE*) malloc(sizeof(MESSAGE) * 10);
    signalMsg -> msgType = 3;
    signalMsg -> cvType = cv;
    if(ServerPid == PNUL || cvNum==0 || listPSpace == NULL || enterWaitingList == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
    printf("go to procedure MonSignal()\n");
    Send(ServerPid,signalMsg,length);
    printf("successfully receive signalMsg reply\n");
    free(signalMsg);
}
