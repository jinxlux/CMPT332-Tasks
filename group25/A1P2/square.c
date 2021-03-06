/* NAME:Tong Wang   
   NSID: tow087 
   Student Number: 11201222
   CMPT 332 Term 1 2019
*/

/* NAME: Xudong Li
   NSID:xul395
   Student Number:11206927
   group25
*/


/* This phase only for windows code PartA1,*/

#include "square.h"
#include <stdlib.h>
#include <stdio.h>




extern int* countSquare;

int Square(int N){
	int threadID = GetID();
	countSquare[threadID]++;
    if(N < 0){
        return -1;
    }
    else if( N == 0 ){
        return 0;
    }
    else{
        return Square(N-1) + 2 * N - 1;
    }
        
    
}