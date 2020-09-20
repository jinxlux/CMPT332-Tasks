
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

#include <os.h>
#include <standards.h>

#include <PhilosopherMonitor.h>

#define SLEEPMAX 50

PID philosopher(void *arg)
{
  long myId;
  
  myId = (long) arg;
  
  for(;;)
    {
      printf("Pholosopher %ld start think\n", myId);
      printf("Pholosopher %ld thinking\n", myId);
      Sleep((int) (rand() % SLEEPMAX));
      pickUp(myId);
      printf("Pholosopher %ld eating\n", myId);
      Sleep((int) (rand() % SLEEPMAX));
      putDown(myId);
    }
}


int mainp()
{
    PID tempPid;
    Initialize();
    setbuf(stdout, 0);

    srand(71);

    tempPid = Create((void(*)()) philosopher, 16000, "P1", (void *) 1, 
		      NORM, USR );
    if (tempPid == PNUL) perror("Create");
    tempPid = Create(  (void(*)()) philosopher, 16000, "P2", (void *) 2,
		       NORM, USR );
    if (tempPid == PNUL) perror("Create");
    tempPid = Create(  (void(*)()) philosopher, 16000, "P3", (void *) 3, 
		       NORM, USR );
    if (tempPid == PNUL) perror("Create");
    tempPid = Create(  (void(*)()) philosopher, 16000, "P4", (void *) 4, 
		       NORM, USR );
    if (tempPid == PNUL) perror("Create");
    tempPid = Create(  (void(*)()) philosopher, 16000, "P5", (void *) 5, 
		       NORM, USR );
    if (tempPid == PNUL) perror("Create");
    printf("philosopher processes created\n");
    
    return(0);
}