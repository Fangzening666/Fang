#include"my.h"

int main()
{
	pid_t pid[3];
	int count=0;
	pid[0]=fork();
	if(pid[0]<0)
{
	perror("fork failed!\n");
	return -1;
}
	pid[1]=fork();
	if(pid[1]<0)
{
	perror("fork failed!\n");
	return -1;
}
	pid[2]=fork();
	if(pid[2]<0)
{
	perror("fork failed!\n");
	return -1;
}
	printf("this is process\n");
	return 0;
}
