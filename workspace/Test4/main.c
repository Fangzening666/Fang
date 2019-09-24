#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

int main(){
	struct timeval tv1,tv2;
	float diff;
	
	int fdsrc, fddes, nbytes;
	int flags=O_CREAT | O_TRUNC | O_WRONLY;
	int z;
	char buf[20], src[20];
	char des[20];
	printf("请输入目标文件名：");
	scanf("%s", des);
	gettimeofday(&tv1,NULL);
	fdsrc = open("/etc/passwd", O_RDONLY);
	if(fdsrc<0){
		exit(1);
	} 
	fddes = open(des, flags, 0644);
	if(fddes<0){
		exit(1);
	}
	while((nbytes=read(fdsrc, buf, 20))>0){
		z = write(fddes, buf, nbytes);
		if(z<0)
			perror("写目标文件出错");
	}
	close(fdsrc);
	close(fdsrc);
	printf("复制“/etc/passwd”文件为“%s”文件成功！		\n",des);
	gettimeofday(&tv2,NULL);
	diff= 1000000*(tv2.tv_sec-tv1.tv_sec)+(tv2.tv_usec-tv1.tv_usec);
	diff/=1000000;
	printf("tv2_usec-tv1_usec; %f\n",diff);
	exit(0);

}
