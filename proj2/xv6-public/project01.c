#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
 const int student_id = 123456789;
 int my_pid, my_gpid;
 my_pid  = getpid();
 my_gpid = getgpid();

 printf(1, "My student id is %d\n", student_id);
 printf(1, "My pid is %d\n", my_pid);
 printf(1, "My gpid is %d\n", my_gpid);

 exit();
};