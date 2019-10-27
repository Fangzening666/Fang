#include"/home/mouslet/Fang/linuxprogram/week8/code/header/myheader.h"

void menu_1(){
int n;

      while(1)
{

		printf( "0. 退出\n1.创建新文件\n2.写文件\n3.读文件\n" );
		printf( "4. 修改文件权限\n5.查看文件权限\n" ); 
		printf( "Please Input your Choice(0-5):" );
		scanf( "%d", &n);
		switch (n)
{
		case 0 : exit(0); break; 
		case 1 : CreateFile_1(); break;
		case 2 : WriteInFile_1(); break;
		case 3 : ReadInFile_1(); break;
		case 4 : AlterFileAuthority_1(); break;
		case 5 : ViewFileAuthority_1(); break;
		default: printf( "You have a wrong choice!\n" );
}
		printf("\n");
}
}
