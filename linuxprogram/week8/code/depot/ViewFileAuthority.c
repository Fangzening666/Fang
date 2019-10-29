#include"/home/mouslet/Fang/linuxprogram/week8/code/header/myheader.h"

void ViewFileAuthority_1() //查看文件权限
{
/*
 FILE *fp = NULL;   
    struct stat kk;
    int fd;
    char pp[100];//文件名字
    int x;  
    printf("请输入查看权限的文件：");
    scanf("%s",pp);  
    if((fp=fopen(pp,"r"))==NULL)
    {
        printf("创建: %s失败\n",pp);
    }
    fd = fileno(fp);
    fstat (fd, &kk);
    printf("查看文件的权限是：%d",(int)kk.st_mode);
    printf("请输入您想修改的权限是：\n");
    scanf("%d",&x);
    fchmod(fd, x);
    printf("成功修改文件：%s为%d",pp,x);
*/
char *path = "/bin/ls";
char *argv[4] = {"ls", "-l","/home/mouslet/Fang/linuxprogram/week8/code/main", NULL};
execv( path,argv );
}




