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

extern void santathread();
extern void elvesthread();
extern void reindeerthread();
extern void assignvalues();


/* in mainp function we should call those threads*/
int mainp(int argc, char *argv[]){
    int i;
    int elvesnum;
    int reindeernum;

    assignvalues();
    printf("enter how many elves want to have: \n");
    scanf("%d",&elvesnum);
    printf("enter how many reindeer want to have: \n");
    scanf("%d",&reindeernum);
    
    /* create santa keep checking */
    Create(santathread, 16000,"santathread", NULL, NORM, USR);

    /* create multiple elves and reindeers */
    for(i = 0; i < reindeernum; i++){
        Create(reindeerthread, 16000,"reindeerthread", NULL, NORM, USR);
    }

    for(i = 0; i < elvesnum; i++){
        Create(elvesthread, 16000,"elvesthread", NULL, NORM, USR);
    }

    return 0;
}

