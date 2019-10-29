#include"/home/mouslet/Fang/linuxprogram/week8/code/header/myheader.h"

void WriteInFile_1()
{

     FILE *fpIn;//文件打开指针
    char pp[100];//文件名字
    unsigned char buf[1024]="";
    printf("输入你想写的文件名字：");
    scanf("%s",pp);
    if((fpIn=fopen(pp,"ab+"))==NULL)
    {
        printf("创建: %s失败\n",pp);
    }
    printf("打开文件成功，请输入你想写入的数据:\n");
    scanf("%s",buf);
    fwrite(buf,sizeof(char),1024,fpIn);
    fclose(fpIn);  
    printf("写入完成\n");

}


