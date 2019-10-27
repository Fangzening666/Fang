#include"/home/mouslet/Fang/linuxprogram/week8/code/header/myheader.h"

void AlterFileAuthority_1() //修 改文件权限
{
int n;
printf( "0.读，写，执行1.读2.写3.执行\n" );
printf( "Please Input Your Choice:" );
scanf( "%d",&n );
switch( n )
{
case 0 : chmod( "/home/mouslet/Fang/linuxprogram/week8/code/main/test.txt", S_IRWXU ); break; //读，写，执行
case 1 : chmod( "/home/mouslet/Fang/linuxprogram/week8/code/main/test.txt", S_IRUSR ); break; //读
case 2 : chmod( "/home/mouslet/Fang/linuxprogram/week8/code/main/test.txt", S_IWUSR ); break; //写
case 3 : chmod( "/home/mouslet/Fang/linuxprogram/week8/code/main/test.txt", S_IXUSR ); break; //执行
default: printf( "You have a wrong choice!\n" );
}

}





