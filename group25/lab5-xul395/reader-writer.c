/*# Dwight Makaroff   */
/*# student number    */
/*# nsid              */
/*# November 7, 2008  */

/* No part of this program may be used for any profit or example for any
   purpose other than for help in Lab5 for CMPT 332 at the University
   of Saskatchewan in the fall term of 2019-20 without the expressed
   written consent of the author.

   *********** reader-writer.c ***********
*/


#include <stdio.h>

#include <standards.h>
#include <os.h>

#include <monitor.h>
#include <reader-writer-monitor.h>

#define SLEEPMAX 20

PROCESS reader(void *arg)
{
  long myId;
  
  myId = (long) arg;
  
  for(;;)
    {
      printf("%ld start read\n", myId);
      StartRead();
      printf("%ld Reading\n", myId);
      Sleep((int) (rand() % SLEEPMAX));
      StopRead();
      printf("%ld stop read\n", myId);
      Sleep((int) (rand() % SLEEPMAX));
    }


}

PROCESS writer(void *arg)
{
  long myId;
  
  myId = (long) arg;
  
  for(;;)
    {
      printf("%ld start write\n", myId);
      StartWrite();
      printf("%ld writing\n", myId);
      Sleep((int) (rand() % SLEEPMAX*5));
      StopWrite();
      printf("%ld stop write\n", myId);
      Sleep((int) (rand() % SLEEPMAX*6));
    }
  
}

int mainp()
{
    int temp, temp2, temp3;


    setbuf(stdout, 0);
    MonInit();

    srand(71);
     
    temp = Create( (void(*)()) reader, 16000, "R1", (void *) 1000, NORM, USR );
    if (temp == PNUL) perror("Create");
    temp2 = Create( (void(*)()) writer, 16000, "W1", (void *) 100, NORM, USR );
    if (temp2 == PNUL) perror("Create");
    temp3 = Create( (void(*)()) reader, 16000, "R2", (void *) 1001, NORM, USR );
    if (temp3 == PNUL) perror("Create");
    temp3 = Create( (void(*)()) reader, 16000, "R3", (void *) 1002, NORM, USR );
    if (temp3 == PNUL) perror("Create");
    temp3 = Create( (void(*)()) writer, 16000, "W2", (void *) 101, NORM, USR );
    if (temp3 == PNUL) perror("Create");
    printf("processes created\n");
    
    return(0);
}
