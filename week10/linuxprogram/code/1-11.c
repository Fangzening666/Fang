#define FILE_PATH "file_point" 
int main(int argc, const char *argv[])
{    
pid_t pid;    
//char *sh = malloc(16);    
char sh[16];    FILE *fp;         
char ss[16] = {0};     
strcpy(sh, "hello kitty");     
fp = fopen(FILE_PATH, "r+");    
if (fp == NULL)    
{           
printf("fopen failed.\n");        
return -1;     
}        
pid = fork();    
if (pid < 0)    
{           
printf("fork failed.\n");        
return 0;    
}       
else if (pid == 0)    
{           
sleep(5);        
int ret;        
printf("pid: %d\tThis is child.\n", getpid());        
printf("[child] sh: %p %s\n", sh, sh);         
printf("[Child] ss: %s\n", ss);        
printf("-----------------------\n");        
// 设置读取文件开头        
ret = fseek(fp, SEEK_SET, 0);         
if (ret < 0)        
{               
perror("[child] fseek..");            
exit(-1);        
}            
char buf[16] = {0};        
ret = fread(buf, 1, strlen(sh), fp);        
if (ret < 0)        
{               
perror("fread: ");            
return -1;         
}           
if (ret == 0)        
{               
if (feof(fp))               
{                      
printf("end the file\n");                   
return 0;               
}            
printf("error.\n");            
return -1;        
}         
printf("[child] buf: %s\n", buf);         
exit(0);   
}    
else if (pid > 0)    
{        
printf("pid: %d\tThis is parent.\n", getpid());        
printf("[parent] sh: %p %s\n", sh, sh);         
strcpy(ss, "Hello World");        
printf("[Parent] ss: %s\n", ss);         
fwrite(sh, 1, strlen(sh), fp);         
// 设置读取文件开头        
fseek(fp, SEEK_SET, 0);         
char buf[16] = {0};        
int ret = fread(buf, 1, strlen(sh), fp);        
if (ret < 0)        
{            
perror("fread: ");            
return -1;        
}        
if (ret == 0)        
{            
if (feof(fp))               
{                   
printf("end the file\n");                   
return 0;               
}            
printf("error.\n");            
return -1;        
}         
printf("[parent] buf: %s\n", buf);    
}     
int rt;    
pid_t pd = wait(&rt);    
printf("Child %d exit states %d\n", pd, rt);    
return 0;}

