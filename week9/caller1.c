#include"my.h"
int main()
{
int ret;
printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
ret=system("/home/mouslet/Fang/week9/test1");
printf("after calling!\n");
sleep(100);
return 0;
}
