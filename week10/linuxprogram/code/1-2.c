#include"my.h"

int i=100;
int main()
{
	pid_t pid=vfork();
	if(pid==-1)
{
	perror("vfork");
	return -1;
}
	else if(pid==0)
{
	i=200;
	printf("child:i=%d pid:%d\n",i,getpid());
	exit(0);
}
	else
{	
	printf("parent:i=%d pid:%d\n",i,getpid());
}
	return 0;
}

