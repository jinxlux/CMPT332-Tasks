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

/* add new function sys_numprocs */


#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"


uint64
sys_exit(void)
{
  exit();
  return 0;  /* not reached */
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  return wait();
}

uint64
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

/* return how many clock tick interrupts have occurred */
/* since start. */
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

/* return how many numbers of runnable processes */
/* currently */
uint64
sys_numprocs(void)
{
  return numprocs(); 
}

/* CMPT 332 GROUP 25 Change, Fall 2019 */
/* thread create system call */
uint64
sys_threadcreate(void)
{
  uint64 tmain;
  uint64 stack;
  uint64 arg;
  argaddr(0,&tmain);
  argaddr(1,&stack);
  argaddr(2,&arg);

  return threadcreate((void*)tmain,(void*)stack,(void*)arg);
}
/* CMPT 332 GROUP 25 Change, Fall 2019 */
uint64
sys_threadjoin(void)
{
  
  uint64 stack;
  argaddr(0,&stack);

  return threadjoin((void **)stack);
}
/* CMPT 332 GROUP 25 Change, Fall 2019 */
uint64
sys_mtxcreate(void)
{
  uint64 locked;
  argaddr(0,&locked);
  return mtxcreate(locked);
}
/* CMPT 332 GROUP 25 Change, Fall 2019 */
uint64
sys_mtxlock(void)
{
  uint64 lock_id;
  argaddr(0,&lock_id);
  return mtxlock(lock_id);
}
/* CMPT 332 GROUP 25 Change, Fall 2019 */
uint64
sys_mtxunlock(void)
{
  uint64 lock_id;
  argaddr(0,&lock_id);
  return mtxunlock(lock_id);
}