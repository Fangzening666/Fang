#include"/home/mouslet/Fang/linuxprogram/week8/code/header/myheader.h"

void WriteInFile_1()
{

      int fp;

      char buf[1024];

      if( ( fp = open( "/home/mouslet/Fang/linuxprogram/week8/code/main/test.txt", O_CREAT|O_APPEND|O_RDWR,0666))< 0)
{
      perror( "open" );
}

      else 
{

      printf( "Open file:test.txt\n");
}

      printf( "Please input your data( < 1024 bytes ) :\n" );
		scanf( "%s", buf );

      if( write( fp, buf, strlen( buf ) ) < 0 )
{

      perror( "write" );
}

      else
{

      printf( "Written Success!\n" );
}

      getchar();

      if( close( fp) < 0 )
{
		perror("close");
}
		else
{
	printf("Close file:test.txt\n");
}
}


