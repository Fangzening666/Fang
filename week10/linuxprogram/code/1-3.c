#include"my.h"

int argc;
char *argv[32];
int param_parse(char *buff)
{
	if(buff==NULL)
		return -1;
	char *ptr = buff;
	char *tmp = ptr;
	
	argc = 0;
	while((*ptr)!='\0')
{
	if((*ptr)==' '&&*(ptr+1)!=' ')
{
	*ptr = '\0';
	argv[argc]=tmp;
	tmp=ptr+1;
	argc++;
}
	ptr++;
	
}
	argv[argc++] = tmp;
	argv[argc] = NULL;
	return 0;
}

int do_exec()
{
	int pid = 0;
	pid = fork();
	if(pid<0)
{
	perror("fork");
	return -1;
}
	else if(pid==0)
{
	execvp(argv[0],argv);
	exit(0);
}
	int statu;
	wait(&statu);
	if(WIFEXITED(statu))
{
	printf("%s",strerror(WEXITSTATUS(statu)));
	return 0;
}
}
int main()
{
	while(1)
{
	printf("shell> ");
	char buff[1024]={0};
	scanf("%[^\n]%*c",buff);
	printf("%s\n",buff);
	param_parse(buff);
	do_exec();
}
	return 0;
}
