#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
getlev(void){
  struct proc *p;
  enum queuelevel lv;
  p = myproc();
  lv = p->qlevel;

  if (lv==MLFQ_L0) return 0;
  else if (lv==MLFQ_L1) return 1;
  else if (lv==MLFQ_L2) return 2;
  else if (lv==MLFQ_L3) return 3;
  else if (lv==MOQ) return 99;

  return -1;
}

//Project 02
int 
sys_yield(void){
  yield();
  return 0;
}

int
sys_getlev(void){
  return getlev();
}

int
sys_setpriority(void){
  int pid;
  int priority;
  if (argint(0, &pid) < 0) return -1;
  else if (argint(1, &priority) < 0) return -1;
  return setpriority(pid, priority);
}

int
sys_setmonopoly(void){
  int pid;
  int password;
  if (argint(0, &pid) < 0) return -1;
  else if (argint(1, &password) < 0) return -1;
  return setmonopoly(pid, password);
}

int
sys_monopolize(void){
  monopolize();
  return 0;
}

int
sys_unmonopolize(void){
  unmonopolize();
  return 0;
}