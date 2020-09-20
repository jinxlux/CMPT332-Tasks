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

PID ServerPid = PNUL;
int serverNum = 0;
LIST** listPSpace = NULL;
LIST* enterWaitingList = NULL;
int lock = 1;

PID MonServer(){
	int* msg;
	PID* pid;
	int* length;
	for(;;){
		msg = (int*) Receive(pid,length);
		
	}

}

void MonInit(int numOfCv){
	int i;
	serverNum = numOfCv;
	if(serverNum==0){
		printf("Error: no conditional variables allowed");
		exit(0);
	}
	if(listPSpace == NULL){
		listPSpace = (LIST **)calloc(numOfCv,sizeof(LIST*));
	}
	for(i=0;i<numOfCv;i++){
		listSpace[i] = ListCreate();
	}
	enterWaitingList = ListCreate();
    while(ServerPid == PNUL){
        ServerPid = Create((void(*)()) MonServer, 16000, NULL, NULL, NORM, USR);
    }
}

/*first executable routine for monitor procedure */
void MonEnter(){
    if(ServerPid == PNUL || serverNum==0 || listPSpace == NULL || enterWaitingList == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
    printf("go to procedure MonEnter()\n");
}

/*last executable routine for monitor procedure to leave*/
void MonLeave(){
    if(ServerPid == PNUL || serverNum==0 || listPSpace == NULL || enterWaitingList == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
    printf("go to procedure MonLeave()\n");
}

/*let enter processes wait in some condition variables*/
void MonWait(int cv){
    if(ServerPid == PNUL || serverNum==0 || listPSpace == NULL || enterWaitingList == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
	printf("go to procedure MonWait()\n");
}

/*reactive the process top of the queue*/
void MonSignal(int cv){
    if(ServerPid == PNUL || serverNum==0 || listPSpace == NULL || enterWaitingList == NULL){
        printf("Error: MonInit missing\n");
        exit(0);
    }
    printf("go to procedure MonSignal()\n");
}
