#include"/home/mouslet/Fang/linuxprogram/week8/code/header/myheader.h"


void ReadInFile_1() //读文件
{

        FILE *fp = NULL;   
    char pp[100];//文件名字
    unsigned char buf[1024];  
    int readCnt;   
    printf("输入你读取的文件名字：");
    scanf("%s",pp);  
    if((fp=fopen(pp,"r"))==NULL)
    {
        printf("创建: %s失败\n",pp);
    }
    readCnt = fread(buf,1024,1,fp);  /* 返回值为0 */ 
    printf("打开文件成功，下面就是文件%s的数据:\n",pp);  
    printf("readCnt = %d\n",readCnt);  
    fclose(fp);  
    printf("%s",buf);

}



