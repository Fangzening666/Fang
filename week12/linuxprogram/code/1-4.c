#include"my.h"

int main(int argc,char *argv[])
{
	int i,j,status;
	int pid[3];
	for(i=0;i<3;i++)
{
	
	pid[i]=fork();
	if(pid[i]<0)
{
	perror("fork failed!\n");
	return -1;
}

	if(pid[i]>0)
{
	printf("This is child process pid=%d\n",pid[i]);
}
	else 
{
	printf("This is father process pid=%d\n",pid[i]);
	exit(EXIT_SUCCESS);
}
}
	return EXIT_SUCCESS;
}
