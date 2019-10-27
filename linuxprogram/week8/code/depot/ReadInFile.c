#include"/home/mouslet/Fang/linuxprogram/week8/code/header/myheader.h"


void ReadInFile_1() //读文件
{

      int fp;

      char *buf;

      int front,rear;

      if( ( fp = open( "/home/mouslet/Fang/linuxprogram/week8/code/main/test.txt", O_RDWR,0666 ) )< 0 )
{

      perror( "open" );
}

      else{
      printf( "Open file:test.txt\n" );
}

      getchar();

      rear = lseek( fp, 0, SEEK_END );

      front = lseek( fp, 0, SEEK_SET ); //设置文 件指针位置

	  front = rear - front;

      buf = ( char * ) malloc( front );
	  if( read( fp, buf, front+1 ) < 0 ){

      perror( "read" );
}

      else{

      printf( "Read Success!\n" );
}

      printf( "%s\n", buf );
	  getchar();
	  if(close(fp)<0)
{
	  perror("close");
}
	  else
{
	  printf("Close file:test.txt\n");
}

}



