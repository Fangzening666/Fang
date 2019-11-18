#include"my.h"

int main()
{
	pid_t pid;
	pid=fork();
	int s;
	if(pid<0)
{
	perror("fork failed!\n");
	exit(-1);
}
	else if(pid==0)
{
	printf("child is running!\n");
	_exit(12);

}
	else
{
	wait(&s);
	printf("parent is running!exit code=%d\n\n",WEXITSTATUS(s));
	return 0;
}
}
