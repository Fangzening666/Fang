#include <fcntl.h>
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include<sys/stat.h>
#include<string.h>
 

int main(void)

{

 

        int fd;

        char buf1[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
 		 char *buf ="hellowhellow";/*用来写入的字符串*/
		char buf2[5];
       

        if ((fd = open("test.txt",O_RDWR|O_CREAT,0644)) < 0)/*使用追加方式打开文件*/

                printf("open error! \n");
		if(write(fd,buf1,sizeof(buf1))!=sizeof(buf1))//将buf写入到fd
		perror("buf1 write into fd1 error");


        if (lseek(fd,5,SEEK_SET) < 0) /*将文件的偏移量设置为5*/
 
                printf("lseek error! \n");

        if  (read(fd,buf2,(sizeof(buf2))) != (sizeof(buf2)))    /*从偏移量为5处读出五个字符*/

                printf("read error! \n");

        else
				buf2[5] = '\0';
                printf("read:%s\n",buf2);/*将读出的字读输出*/
	if (lseek(fd,10,SEEK_SET) < 0) /*将文件的偏移量设置为5*/
 
                printf("lseek error! \n");	
       if (write(fd,buf,strlen(buf)) != strlen(buf))    /*将字符串buf2写入文件*/

              printf("write error! \n");

}
