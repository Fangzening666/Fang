#include"my.h"   
int main()      
{      
    pid_t pid;      
    int cnt = 0;      
    pid = vfork();     
    if(pid<0)     
    printf("error in fork!\n");     
    else if(pid == 0)     
    {     
        cnt++;     
        printf("cnt=%d\n",cnt);     
        printf("I am the child process,pid is %d\n",getpid());
		_exit(0);     
    }     
    else   
    {     
        cnt++;     
        printf("cnt=%d\n",cnt);     
        printf("I am the parent process,pid is %d\n",getpid());     
    }     
    return 0;   
}

