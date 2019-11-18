#include "my.h"

int mian()
{
	int pid,status,r;
	if((pid=fork())<0)
{
	perror("failed to fork@\n");
	return -1;

}
	else if(pid==0)
{
	printf("%d : child is running now!\n",getpid());
	sleep(10);
	printf("%d : child is exit now!\n",getpid());
	exit(0);
}
	else

{
	printf("%d : parent is waiting zoombie now\n",getpid());
	r=waitpid(pid,&status,0);
	
}
}

