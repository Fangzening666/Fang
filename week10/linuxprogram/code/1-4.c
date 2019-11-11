#include"my.h"

int global = 5;

int main()
{
pid_t pid;
int cnt = 0,t = 0;
pid = fork();
//pid = vfork();
if(pid<0)
printf("error in fork!\n");
else if(pid == 0)
{
t = 0;
while(t < 4)
{
cnt++;
global++;
printf("global = %d\n",global);
printf("cnt = %d\n",cnt);
printf("I am the child process,pid is %d\n",getpid());
t++;
}
// exit(0);
// _exit(0);
// return 0;
}
else
{
t = 0;
while(t < 4)
{
cnt++;
global++;
printf("global = %d\n",global);
printf("cnt = %d\n",cnt);
printf("I am the father process,ppid is %d\n",getppid());
t++;
}
}
return 0;
}

