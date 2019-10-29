#include <stdio.h>
#include<string.h>
#include<sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/stat.h>
#include<syslog.h>
#include<stdlib.h>

void CreateFile_1() ;			//创建一个新的"txt"文件
void WriteInFile_1();			//向文件中写入字符串
void ReadInFile_1();			//读取文件中的字符串
void AlterFileAuthority_1();	//修改文件权限
void ViewFileAuthority_1();		//查看文件权限并修改文件权限
void menu_1();					//文件管理系统菜单
