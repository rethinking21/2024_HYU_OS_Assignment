#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
 char *buf = "Hello xv6!";
 int ppppid;
 int ret_val;
 ret_val = myfunction(buf);
 ppppid  = getpid();
 printf(1, "Return value : 0x%x\n", ret_val);
 printf(1, "Return value : 0x%d\n", ppppid);
 exit();
};