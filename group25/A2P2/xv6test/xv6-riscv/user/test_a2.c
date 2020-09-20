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
/* copy the code from assignment description */




#include "kernel/types.h"
#include "user/user.h"
#include "kernel/stat.h"

int bufferPosition;
int empty;
int full;
/* init function create mutx */
void init(){
    empty = mtxcreate(0);
    full = mtxcreate(1);
    bufferPosition = 0;
}
/* init procuder function */
void producer(void* arg){
    
    while(1){
        mtxlock(empty);
        bufferPosition++;
        printf("produce a data and put in position %d\n",bufferPosition);
        mtxunlock(full);
        sleep(10);
    }
}

void consumer(void* arg){
    
    while(1){
        mtxlock(full);
        printf("remove a data from position %d\n",bufferPosition);
        bufferPosition--;
        mtxunlock(empty);       
        sleep(10);
        
        
        
    }
}
/* this is a thread for testing threadcreate and threadjoin*/
void
createthread(void* a)
{

  printf("thread create test\n");
  printf("thread create OK\n");
  exit();
}
int
main(int argc, char *argv[])
{

  void* pstack;
  pstack = malloc(sizeof(uint64)*1000);
  void* cstack;
  cstack = malloc(sizeof(uint64)*1000);
  char* argument;
  void* tstack;
  tstack = malloc(sizeof(uint64));
  argument = malloc(sizeof(char) * 100);

  threadcreate((void(*)())createthread,tstack,argument);
  threadjoin((void**)tstack);
  printf("thread join test\n");
  printf("thread join OK\n");
  printf("Test all five system call by producer-consumer\n");
  sleep(20);
  threadcreate((void(*)())producer,pstack,argument);
  sleep(10);
  threadcreate((void(*)())consumer,cstack,argument);

  sleep(1000);
  threadjoin((void**)tstack);
  printf("success to terminate the thread, finish thread join/n");
  exit();
}