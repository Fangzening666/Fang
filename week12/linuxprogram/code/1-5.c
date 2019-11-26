#include "my.h"

int count =0;

int main()
{
	pid_t p1,p2,p3;
	
	int fd[2],n; 
   	char writebuf[20] = {"Hello World!\n"}; //写缓冲区
    char readbuf[20]; //读缓冲区
	int s1,s2,s3,r1,r2,r3;
	if (pipe(fd) < 0) 
    { 
        printf("pipe error"); 
    } 
	p1=fork();
	if(p1<0)
{
	perror("fork1 failed.\n");
	return -1;
}
	else if(p1==0)
{
	close(fd[1]); 
    n=read(fd[0],readbuf,sizeof(readbuf)); 
	printf("%s",readbuf);
	close(fd[0]); 
    write(fd[1],"0123456789\n",11); 
	count+=1;
	printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
	exit(0);
}
	else
{
	printf("parent fork second time.\n");
	p2=fork();
	if(p2<0)
{
	perror("fork1 failed.\n");
	return -1;
}
	else if(p2==0)
{
	//close(fd[1]); 
    //n=read(fd[0],readbuf,sizeof(readbuf)); 
	//printf("%s",readbuf);
	count+=1;
	printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
	exit(0);
}
	else
{
	printf("parent fork second time.\n");
	p3=fork();
	if(p3<0)
{
	perror("fork1 failed.\n");
	return -1;
}
	else if(p3==0)
{	
	//close(fd[1]); 
    //n=read(fd[0],readbuf,sizeof(readbuf));  
	//printf("%s",readbuf);
	count+=1;
	printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
	exit(0);
}
	else
{
	printf("parent waiting\n");
	close(fd[0]); 
    write(fd[1],writebuf,sizeof(writebuf)); 
	r1=wait(&s1);
	r2=wait(&s2);
	r3=wait(&s3);
	printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d\n",r1,WEXITSTATUS(s1),WEXITSTATUS(s2),WEXITSTATUS(s3));
	printf("parent pid+%d,count=%d\n",getpid(),count);
	return 0;
}
}
}
}
