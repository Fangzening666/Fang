#include <sys/types.h>
#include <fcntl.h>
#include "ourhdr.h"

int main(int argc,char *argv[])
{
	int accmode,val;
	if(argc!=2)
		perror("usage:a.out<descriptor#>");
	if((val=fcntl(atoi(argv[1]),F_GETFL,0))<0)
		perror("fcntl error for fd %d",atoi(argv[1]));
	accmode==val&O_ACCMODE;
	if 		(accmode==O_RDONLY)	printf("read only");
}
