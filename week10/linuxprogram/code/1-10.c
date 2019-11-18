#include "my.h"

int main(int argc, char** argv){
    pid_t pid;
    int fd = open("./test.dat", O_RDWR|O_TRUNC, 0);
    if(fd == -1){
        printf("open fails\n");
        exit(1);
    }
    char buf[] = "databuffer\n\0";
    if((pid = fork()) < 0){
        printf("fork error\n");
        return -1;
    }else if(pid == 0){
        write(fd, buf, strlen(buf));
        fsync(fd);
        close(fd);
        return 0;
    }
 
    wait(NULL);
    memset(buf, 0, sizeof(buf)/sizeof(char));
    lseek(fd, 0, SEEK_SET);
    read(fd, buf, sizeof(buf)/sizeof(char)-1); 
    printf("%s\n", buf);
    return 0;
}
