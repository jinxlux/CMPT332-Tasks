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


#include "list.h"
#include <rtthreads.h>
#include <RttCommon.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <net/if.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <string.h>

/*Header file was not asked for, so defining function prototypes here*/
RTTTHREAD keyboardThread();

RTTTHREAD printToScreen();

RTTTHREAD receiveNetworkMsg();

RTTTHREAD sendOverNetwork();

LIST* sendBuffer = NULL; /*Send list to store sending messages*/
LIST* showBuffer = NULL; /*Show list to store printing messages*/
RttSem *sendSem;    /*Send sem*/
RttSem *showSem;    /*Show sem*/
int thisMachinePortNumber;		/*The host's port as an int*/
char toMachineName[3000];	/*The host's name*/
int  toMachinePortNumber;		/*This machine's port as an int*/
char ipToSendTo[3000];	/*Host's ip as a string*/
char toPort[3000];		/*This machine's port as a string*/
char thisPort[3000];		/*Host's port as a string*/

/*
 * Waits for input from keyboard
 * Once receives inputs, adds the message to a sender qeueue, notifys server thread
*/
RTTTHREAD keyboardThread(){
    char *input;
    for(;;){
        input = (char*)malloc(1024);
        while(read(0,input,1024) == -1);
        /*change the input to no blocking*/
        fcntl(0, F_SETFL, O_NONBLOCK);
        /*Use RttP RttV and semphoare to control the modification for the showbuff and sendBuff*/
        RttP(*sendSem);
        ListPrepend(sendBuffer,input);
        RttV(*sendSem);
        RttP(*showSem);
        ListPrepend(showBuffer,input);
        RttV(*showSem);
        RttSleep(2);
    }
}
/*
 * print information to screen when get the signal
 * 
*/
RTTTHREAD printToScreen(){
    char *temp;
    for(;;){
        RttP(*showSem);
        while(ListCount(showBuffer)!=0){
            temp = (char *)ListTrim(showBuffer);
            printf("%s",temp);
        }
        RttV(*showSem);
        RttSleep(2);
    }
}


/*
 * Waits for message(s) from machines over the network
 * 
*/
RTTTHREAD receiveNetworkMsg(){
    int sockfd;
    socklen_t addrlen;
    struct addrinfo hints, *serverinfo, *p;
    struct sockaddr_storage theiraddr;	
    int rv;
    char temp[1000];
    char receivemessages[1000];
    int right = 1;

    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;		/*use AF_INET to force IPv4*/
    hints.ai_socktype = SOCK_DGRAM;	/*setting socket type to UDP*/
    hints.ai_flags = AI_PASSIVE;
    for(;;){
        if ((rv = getaddrinfo(toMachineName, toPort, &hints, &serverinfo)) != 0) {
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
            exit(1);
            }
        /*check show list if there are messages send it to the right person*/
        RttP(*showSem);
        for(p = serverinfo; p != NULL; p = p->ai_next) {
	        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {/* the socket for receive */
	            perror("receiveNetworkMsg: socket");
	            continue;
	        }
	        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &right, sizeof(int)) == -1 && errno == EINTR) {	/*set socket to be reusable*/
	            perror("setsockopt");
	            exit(1);
            }
	        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {		/*Bind the socket that was created*/
	            close(sockfd);
	            perror("receiveNetworkMsg: bind");
	            continue;
	        }
            break;
        }
        addrlen = sizeof theiraddr;
        fcntl(sockfd, F_SETFL, O_NONBLOCK);     /*setting socket to be non-blocking*/
        if ((recvfrom(sockfd, temp, strlen(temp), 0, (struct sockaddr *)&theiraddr, &addrlen)) == -1) {
            perror("recvfromNetwork: receivefrom");
	        exit(1);
        }
        fcntl(sockfd, F_SETFL, ~O_NONBLOCK);    /*setting socket to be blocking*/
        strcpy(receivemessages,temp);
        ListPrepend(showBuffer,(void*)receivemessages);
        RttV(*showSem);
        RttSleep(2);
        freeaddrinfo(serverinfo); /* all done with this structure */
        close(sockfd);
    }
   /* printf("receiveNetworkMsg function need to be \n"); */
    
}

/*
 * Sends message(s) to machines over the network
 * 
*/
RTTTHREAD sendOverNetwork(){
    int sockfd;
    struct addrinfo hints, *serverinfo, *p;
    int rv;
    char *temp;
    char sendmessages[1000];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;		/*use AF_INET to force IPv4*/
    hints.ai_socktype = SOCK_DGRAM;	/*setting socket type to UDP*/
    for(;;){
        if ((rv = getaddrinfo(toMachineName, toPort, &hints, &serverinfo)) != 0) {
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
            exit(1);
            }
        /*check sending list if there are messages send it to the right person*/
        RttP(*sendSem);
        while(ListCount(sendBuffer)!=0){
            temp = (char *)ListTrim(sendBuffer);/*Get the item in the queue to send*/
            strcpy(sendmessages, (char*) temp); /*Copy the send message to send*/
            /* loop through all the results and make a socket */
            for(p = serverinfo; p != NULL; p = p->ai_next) {
	            if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) { 	/*Creating socket*/
	                perror("sendOverNetwork: socket");
	                continue;
	            }
                

	        break;/* if we get here, we must have connected successfully */
            }
            fcntl(sockfd, F_SETFL, O_NONBLOCK);     /*setting socket to be non-blocking*/
            if ((sendto(sockfd, sendmessages, strlen(sendmessages), 0, p->ai_addr, p->ai_addrlen)) == -1) {
                perror("sendOverNetwork: sendto");
	            exit(1);
            }
            fcntl(sockfd, F_SETFL, ~O_NONBLOCK);    /*setting socket to be blocking*/
        }
        RttV(*sendSem);
        RttSleep(2);
        freeaddrinfo(serverinfo); /* all done with this structure */
        close(sockfd);
    }
    
}

int mainp(int argc, char **argv){
    int i;
    int j;
    struct hostent *hostEnt;
    struct in_addr **addr_list;
    char ip[1000];	
    char int_ip[1000];
    uint32_t ipAddress;
    RttThreadId *rtID;
    RttThreadId *rtID2;
    RttThreadId *rtID3;
    RttThreadId *rtID4;
    RttSchAttr sch;
    /*printf("mainp function need to be \n");*/
    sendBuffer = ListCreate();
    showBuffer = ListCreate();
    rtID = (RttThreadId *)malloc(sizeof(RttThreadId));
    rtID2 = (RttThreadId *)malloc(sizeof(RttThreadId));
    rtID3 = (RttThreadId *)malloc(sizeof(RttThreadId));
    rtID4 = (RttThreadId *)malloc(sizeof(RttThreadId));
    sendSem = (RttSem *)malloc(sizeof(RttSem));
    showSem = (RttSem *)malloc(sizeof(RttSem));
    RttAllocSem(sendSem, 1, RTTFCFS);
    RttAllocSem(showSem, 1, RTTFCFS);
    sch.startingtime = RTTZEROTIME;
    sch.priority = RTTHIGH;
    sch.deadline = RTTNODEADLINE;


    /*Checking if amount of arguments are met*/
    if(argc != 4){
    printf("usage: yourPort hostMachine hostPort\nEX: 30001 tux1 40000\n");
    }
    /*Checking if arguments are valid*/
    if(argv[1] == NULL || argv[2] == NULL || argv[3] == NULL){
    printf("Argument(s) is/are null\n");
    return -1;
    }
    thisMachinePortNumber = atoi(argv[1]); 	/*Port on sender's machine*/
    i=0;
    while(argv[2][i] != '\0'){
        toMachineName[i] = argv[2][i];
        i++;
    }
    toMachinePortNumber =  atoi(argv[3]);	/*Host machine's port*/  
  
    /*Checking port range 30001 to 40000, as specified in the assignment*/
    if((toMachinePortNumber < 30001) || (toMachinePortNumber > 40000)){
        printf("tomachine port number wrong");
        return -1;
      
    }
  
    /*Checking this machine's port range*/
    else if ((thisMachinePortNumber < 30001) || (thisMachinePortNumber > 40000)){
        printf("currentmachine port number wrong");
        return -1;
    }
  
    /*Checking if host exists*/
    if((hostEnt = gethostbyname(toMachineName)) == NULL){
        printf("Could not find host name: %s\n", toMachineName);
        return -1;
    }
    else{
        hostEnt = gethostbyname(toMachineName);
        addr_list = (struct in_addr **) hostEnt->h_addr_list;
        for(i = 0; addr_list[i] != NULL; i++){
            strcpy(ip , inet_ntoa(*addr_list[i])); 	/*Getting host IP and putting into char array*/
        }
    }    
    /*printf("\nFound host: %s \nHost's IPv4: %s\n\n", toMachineName, ip);*/ 
    return 0;

      
    /*Converting the string IP to an int to be used for RttNetInit(), specified in the RT document*/
    i = 0;
    j = 0;
    strcpy(ipToSendTo,ip);
    strcpy(thisPort, argv[1]);
    strcpy(toPort, argv[3]);
    while (ip[i] != '\0'){
        if(ip[i] == '.'){
        i++;
        }
        int_ip[j]=ip[i];
        i++;
        j++;
    }
    ipAddress = atoi(int_ip);	/*Converting string to integer*/
  
  
    /*Check if port is available, already checked above if hostname exists, and if port was within range*/
    if(RttNetInit(ipAddress, thisMachinePortNumber) < 0){
        printf("Port unavailabe\n");
        return -1;
    }

    RttCreate(rtID2, (void(*)()) keyboardThread, 16000, "keyboardThread", NULL, sch, RTTUSR);
    RttCreate(rtID, (void(*)()) sendOverNetwork, 16000, "sendOverNetwork", NULL, sch, RTTUSR);
    RttCreate(rtID3, (void(*)()) receiveNetworkMsg, 16000, "receiveNetworkMsg", NULL, sch, RTTUSR);
    RttCreate(rtID4, (void(*)()) printToScreen, 16000, "printToScreen", NULL, sch, RTTUSR);

    return 0;
}