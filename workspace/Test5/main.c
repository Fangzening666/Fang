#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

#define MAX 100

int main(){
	struct timeval tv1,tv2;
	float diff;
	FILE*f1 = NULL;
	FILE*f2 = NULL;
	char des[20];
	char list[MAX];
	
	printf("请输入目标文件名：");
	scanf("%s", des);
	gettimeofday(&tv1,NULL);
	f1 = fopen("/etc/passwd", "rt");
	if(f1==NULL)
	{
		exit(1);
	} 
	f2 = fopen(des,"wt");
	if(f2==NULL){
		exit(1);
	}
	while(!feof(f1)){
		if(fputc(fgetc(f1),f2)==EOF)
			perror("写目标文件出错");
	}
	fclose(f1);
	fclose(f2);
	printf("复制“/etc/passwd”文件为“%s”文件成功！		\n",des);
	gettimeofday(&tv2,NULL);
	diff= 1000000*(tv2.tv_sec-tv1.tv_sec)+(tv2.tv_usec-tv1.tv_usec);
	diff/=1000000;
	printf("tv2_usec-tv1_usec; %f\n",diff);
	exit(0);
}
