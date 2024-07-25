#include "types.h"
#include "defs.h"
#include "param.h"  // why?
#include "mmu.h" // why?
#include "proc.h"

#define NULL 0

// Simple getgpid
int
getgpid(void)
{
 struct proc *curproc = myproc();
 int gpid = 0;
 if (curproc->parent == NULL || curproc->parent->parent == NULL) 
  return -1; // error: there is no gproc
 gpid = curproc->parent->parent->pid;
 return gpid;
}

//Wrapper for getgpid
int
sys_getgpid(void)
{
 return getgpid();
}
