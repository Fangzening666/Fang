#include"/home/mouslet/Fang/linuxprogram/week8/code/header/myheader.h"

void CreateFile_1() //1.创建新文件
{
    FILE *fpIn;//文件打开指针
    char pp[100];//文件名字s
    //unsigned char buf[128];
    printf("输入你想创建的文件名字：");
    scanf("%s",pp);
    if((fpIn=fopen(pp,"ab+"))==NULL)
    {
        printf("文件不存在，即将创建一个文件: %s\n",pp);
    }
    printf("创建成功，返回主菜单，继续你的选择。\n");

}

