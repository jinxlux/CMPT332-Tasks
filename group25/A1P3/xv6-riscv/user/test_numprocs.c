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

void
createfork(void)
{
  int n, pid;

  printf("fork test\n");

  for(n=0; n<20; n++){
    pid = fork();
    if(pid < 0)
      break;
    if(pid == 0)
      while(1);
  }
  printf("fork create OK\n");
}
int
main(int argc, char *argv[])
{
  int current_runnable;
  printf("sys_numprocs test begin \n");
  createfork();   
  current_runnable = numprocs();
  if (current_runnable < 0){
     printf("2", "numprocs failed\n");
     exit();
  }
  else{
     printf("Have %d RUNNABLE\n", current_runnable);
  }
  exit();
}