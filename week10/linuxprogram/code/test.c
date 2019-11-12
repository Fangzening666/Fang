#include"my.h"
int g=10;
char a[100]={0};

int main()
{
	pid_t pid;
	int i;
	static int k=20;
	printf("\ntest:pid=%d,&k=%16p,&g=%16p\n",getpid(),&k,&g);
	for(i=0;i<10;i++)
{
	printf("test:g=%d,k=%d\n",g++,k++);
}
	return 0;
}

