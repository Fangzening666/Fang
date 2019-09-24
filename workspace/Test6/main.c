
#include"ourhdr.h"
#include<fcntl.h>

#define BUFFSIZE 10

int main()
{
	int n;
	char buf[BUFFSIZE];
	while((n=read(STDIN_FILENO,buf,BUFFSIZE))>0)
	if(write(STDIN_FILENO,buf,n)!=n)
		perror("write error");
		if(n<0)
	
		perror("read error");
		
	exit(0);
}
