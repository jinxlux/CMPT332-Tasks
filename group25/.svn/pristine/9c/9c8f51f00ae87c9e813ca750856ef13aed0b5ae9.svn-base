
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
#include <Monitor.h>
#include "PhilosopherMonitor.h"

/* INITIALIZATION CODE */

#define numConds  5
#define think 0
#define eat 1
#define hungry 2

int state[5];

/* MONITOR PROCEDURES */

void Initialize(void)
{
      MonInit(numConds);
}

void pickUp(long i){
    MonEnter();
    state[i-1] = hungry;
    test(i);
    if(state[i-1] != eat){
        MonWait(i-1);
    }
    MonLeave();
}

void putDown(long i){
    MonEnter();
    state[i-1] = think;
    printf("Pholosopher %ld finished eating\n", i);
    test((i-1)%5);
    test((i+1)%5);
    MonLeave();
}

void test(long i){
    int left;
    int right;
    if(i == 0){
        i = 5;
    }
    left = (i-1)%5;
    right = (i+1)%5;
    if(left == 0){
        left = 5;
    }
    if(right == 0){
        right = 5;
    }
    if(state[left-1] != eat && state[right-1] != eat && state[i-1] == hungry){
        state[i-1] = eat;
        MonSignal(i-1);
    }
}


  
  




