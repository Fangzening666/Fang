#include"/home/mouslet/Fang/linuxprogram/week8/code/header/myheader.h"

void AlterFileAuthority_1() //修 改文件权限
{
	   FILE *fp = NULL;   
    char pp[100];//文件名字
    //int x,fd,n;  
	int fd,n;
    printf("输入你修改权限的文件名字：");
    scanf("%s",pp);  
    if(((fp=fopen(pp,"r"))==NULL)&&((fp=fopen(pp,"w"))==NULL)&&((fp=fopen(pp,"x"))==NULL))
    {
        printf("创建: %s失败\n",pp);
    }
	printf( "0.读，写，执行\n1.读\n2.写\n3.执行\n" );
	printf( "Please Input Your Choice:" );
	scanf( "%d",&n );
    //printf("请输入修改的权限是：\n");
   // scanf("%d",&x);
    fd = fileno(fp);
	switch( n )
	{
	case 0 : fchmod(fd,S_IRWXU); break; //读，写，执行
	case 1 : fchmod(fd,S_IRUSR); break; //读
	case 2 : fchmod(fd,S_IWUSR); break; //写
	case 3 : fchmod(fd,S_IXUSR); break; //执行
	default: printf( "You have a wrong choice!\n" );
	}

    //fchmod(fd, x);
   // printf("成功修改文件：%s为%d",pp,x);
}





