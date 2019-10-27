#include"/home/mouslet/Fang/linuxprogram/week8/code/header/myheader.h"

void ViewFileAuthority_1() //查看文件权限
{
char *path = "/bin/ls";
char *argv[4] = {"Is", "-I", "/home/mouslet/Fang/linuxprogram/week8/code/main/test.txt", NULL};
execv( path,argv );
}




