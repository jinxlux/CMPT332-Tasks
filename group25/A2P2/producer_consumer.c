
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


int bufferPosition;
int empty;
int full;

void init(){
    empty = mtx_create(0);
    full = mtx_create(1);
    bufferPosition = 0;
}

void producer(void* arg){
    printf("test argument in producer: %ld",(long)arg)
    while(1){
        mtx_lock(empty);
        printf("produce a data and put in position %d\n",bufferPosition);
        bufferPosition++;
        mtx_unlock(full);
    }
}

void consumer(void* arg){
    printf("test argument in consumer: %ld",(long)arg)
    while(1){
        mtx_lock(full);
        printf("remove a data from position %d\n",bufferPosition);
        bufferPosition--;
        mtx_unlock(empty);
    }
}

int mainp(){

    init();
    long* address;
    address = (long*) malloc(sizeof(long) * 1600);
    int thread_create(producer, address, (void *) 1);
    int thread_create(consumer, address, (void *) 2);
    printf("finish creating/n")
}