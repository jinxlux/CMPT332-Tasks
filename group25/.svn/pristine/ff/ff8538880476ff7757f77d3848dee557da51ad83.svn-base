/* NAME: Xudong Li
   NSID:xul395
   Student Number:11206927
*/

/* NAME:Tong Wang   
   NSID: tow087 
   Student Number: 11201222
   CMPT 332 Term 1 2019
*/

/* NAME: Enyu Ma
   NSID:enm614
   Student Number:11191666
*/

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <standards.h>
#include <os.h>


/* declear some semaphores, variables to make it global */
int elves, reindeer, santaSem, reindeerSem, elfTex, muTex;
/* Santa thread */
void santathread(){
    while(1){
        int i;
        
        P(santaSem);
        
        P(muTex);
        
        if(reindeer >= 9){
            printf("Prepare sleigh\n");
            for(i = 0; i < 9; i++){
                V(reindeerSem);                
            }
            reindeer = reindeer - 9;
            printf("-------------------- all 9 reindeers hitched\n");
        }
        else if( elves == 3){
            printf("Help elves\n");
        }
        V(muTex);    
    }

}
/* Elves thread*/
void elvesthread(){
/*  */
    P(elfTex);
    P(muTex);
    elves = elves + 1;
    printf("enter elves\n");
    
    if(elves == 3){
        V(santaSem);
    }
    else{
        V(elfTex);
    }
    V(muTex);
    
    Sleep(20);
    P(muTex);
    elves = elves - 1;
    printf("--------------------  helped elves\n");
    if(elves == 0){
        V(elfTex);
    }
    V(muTex);
}
/* Reindeer thread*/
void reindeerthread(){
/*  */

    P(muTex);
    reindeer = reindeer + 1;
    /* print reindeer number*/
    
    printf("reindeer number %d\n", reindeer);
    
    if(reindeer == 9){
        V(santaSem);
    }
    V(muTex);
    P(reindeerSem);

    printf("-------------------- get a reindeer hitched\n");
    
}

void assignvalues(){

    elves = 0;
    reindeer = 0;
    
    santaSem = NewSem(0);
    reindeerSem = NewSem(0);
    elfTex = NewSem(1);
    muTex = NewSem(1);
    
}

/* */
