#include"my.h"

#define BUFFSIZE 4096 

int printFdInfo(int fd);
int main(void) 
{	
	/*int fd = open("./test.dat",O_RDWR);	
	if(-1 == fd)
{                 
	printf("file openerror\n");		
	return -1;         
}*/          
	pid_t   pid;
	pid = vfork();
int fd = open("./test.dat",O_RDWR);	
	if(-1 == fd)
{                 
	printf("file openerror\n");		
	return -1;         
}         
	if (pid< 0)
{                
	printf("fork error");        
} 
	else if (pid == 0) 
{          
	/* child */					     	  	
printf("*********************child*******************\n");						
printFdInfo(fd);		
printf("child seek %ld\n",lseek(fd,		3,SEEK_CUR));					
printf("*********************child*******************\n");
	_exit(0);        
} 
	else 
{                
	sleep(2);                               
	/* parent */			
printf("*********************parent*******************\n");		
printFdInfo(fd);		
printf("parent seek cur %ld\n",lseek(fd,	0,SEEK_CUR));			
printf("*********************parent*******************\n");        }  		
return 0;
} 

int printFdInfo(int fd)
{	struct stat sb;  	
	if (fstat(fd, &sb) == -1)
{		
perror("stat");		
exit(EXIT_FAILURE);	
} 	
printf("File type:                "); 	
switch (sb.st_mode & S_IFMT) 
{		
case S_IFBLK:  printf("block device\n");            break;		
case S_IFCHR:  printf("character device\n");        break;		
case S_IFDIR:  printf("directory\n");               break;		
case S_IFIFO:  printf("FIFO/pipe\n");               break;		
case S_IFLNK:  printf("symlink\n");                 break;		
case S_IFREG:  printf("regular file\n");            break;		
case S_IFSOCK: printf("socket\n");                  break;		
default:       printf("unknown?\n");                break;	
} 	
printf("I-node number:            %ld\n", (long) sb.st_ino); 	
printf("Mode:                     %lo (octal)\n",                   (unsigned long) sb.st_mode); 	
printf("Link count:               %ld\n", (long) sb.st_nlink);	
printf("Ownership:                UID=%ld   GID=%ld\n",                   (long) sb.st_uid, (long) sb.st_gid); 	
printf("Preferred I/O block size: %ld bytes\n",                   (long) sb.st_blksize);	
printf("File size:                %lld bytes\n",                   (long long) sb.st_size);	
printf("Blocks allocated:         %lld\n",                   (long long) sb.st_blocks); 	
printf("Last status change:       %s", ctime(&sb.st_ctime));	
printf("Last file access:         %s", ctime(&sb.st_atime));	
printf("Last file modification:   %s",ctime(&sb.st_mtime));		
return 0;
}


