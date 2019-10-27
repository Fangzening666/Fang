#include"/home/mouslet/Fang/linuxprogram/week8/code/header/myheader.h"

void CreateFile_1() //1.创建新文件
{
      int fp;

      if( ( fp = open( "/home/mouslet/Fang/linuxprogram/week8/code/main/test.txt",O_CREAT|O_TRUNC|O_RDWR,0666) )< 0)
{

      perror( "open" );
}
		else{

      printf( "Create file:test.txt\n" );
}

      getchar();

      if( close( fp )< 0 ){

      perror( "close" );
		}

      else{

      printf( "Close file:test.txt\n" );

      }

}

