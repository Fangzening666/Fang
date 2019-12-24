#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

const int Port = 8888;
pthread_mutex_t g_mutext;

struct pthread_data{
    struct sockaddr_in client_addr;
    int sock_fd;
};

void *serveForClient(void * arg);

int main(void){
    int sock_fd;
    struct sockaddr_in mysock;
    struct pthread_data pdata;
    socklen_t sin_size = sizeof(struct sockaddr_in);
    struct sockaddr_in client_addr;
    

    //初始化socket
    sock_fd = socket(AF_INET,SOCK_STREAM,0);

    //编辑地址信息
    memset(&mysock, 0, sizeof(mysock));
    mysock.sin_family = AF_INET;
    mysock.sin_port = htons(Port);
    mysock.sin_addr.s_addr = INADDR_ANY;

    //绑定地址，然后监听
    bind(sock_fd,(struct sockaddr *)&mysock,sizeof(struct sockaddr));
    if(listen(sock_fd,10) < -1){
        printf("listen error.\n");
    }

    printf("listening...\n");
    while(1){
        //accpet
		pthread_t pt;
		int *new_fd=(int *)malloc(sizeof(int));   
		new_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &sin_size);
        pdata.sock_fd = new_fd;
        pthread_create(&pt, NULL, serveForClient, (void *)&pdata);
		pthread_detach(pt);
    }
    close(sock_fd);
    return 0;
}

void *serveForClient(void *arg){
    struct pthread_data *pdata = (struct pthread_data*)arg;
    int new_fd = pdata->sock_fd;
    char recvbuf[1024];
    char sendbuf[1024] = "recv successfully.\n";
    while(1){
        recv(new_fd, recvbuf, sizeof(recvbuf), 0);
        fputs(recvbuf,stdout);
        strcpy(sendbuf, recvbuf);
        if(strcmp(recvbuf,"exit\n") == 0){
            send(new_fd, "connection close.\n", sizeof("connection close.\n"), MSG_NOSIGNAL);
            break;
        }
        send(new_fd, sendbuf, sizeof(sendbuf), 0);
        memset(recvbuf,0,sizeof(recvbuf));
    }
    pthread_exit(0);
}
/*
void *serveForClient(void *arg){
	FILE *fp;
	int n;
    struct pthread_data *pdata = (struct pthread_data*)arg;
    int new_fd = pdata->sock_fd;
    char recvbuf[1024];
    char sendbuf[1024] = "recv successfully.\n";
    while(1){
        if(recv(new_fd, recvbuf, sizeof(recvbuf), 0)>0){
			if(fp=fopen("ser.txt","a+")<0){
			perror("创建文件失败\n");
			}
			if((n=fwrite(recvbuf,1,strlen(recvbuf),fp))<0){
				perror("写入文件失败\n");
			}
		}
        send(new_fd, sendbuf, sizeof(sendbuf), 0);
    }
    pthread_exit(0);
}*/
