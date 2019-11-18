#include "my.h"

int main()
{
	clock_t start,finish;
	double duration;
	pid_t pid;
	int k,status;
	pid=fork();
	if(pid<0)
{
	perror("fork failed!\n");
	return -1;
}
	else if(pid==0)
{
	start = clock();
	printf("child %d : running!\n",getpid());
	while(1);
	exit(120);
	finish = clock();
}
	else
{
	
	if((k=wait(&status))!=0)
{
	if(WIFEXITED(status))
{
	printf("child exit with exit!\nexit code =%d\n",WEXITSTATUS(status));
}
	else if(WIFSIGNALED(status))
{
	
	printf("child terminataed with signal!\n signal number =%d\n",WTERMSIG(status));

}
		
}
	duration=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("duration=%f seconds\n",duration);
	exit(0);
}

}
