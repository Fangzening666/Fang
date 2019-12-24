#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<errno.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <time.h>
const int Port = 8888;

#define IF_NAME "eth0"
int get_local_ip(char * ifname, char * ip)
{
    char *temp = NULL;
    int inet_sock;
    struct ifreq ifr;

    inet_sock = socket(AF_INET, SOCK_DGRAM, 0); 

    memset(ifr.ifr_name, 0, sizeof(ifr.ifr_name));
    memcpy(ifr.ifr_name, ifname, strlen(ifname));

    if(0 != ioctl(inet_sock, SIOCGIFADDR, &ifr)) 
    {   
        perror("ioctl error");
        return -1;
    }

    temp = inet_ntoa(((struct sockaddr_in*)&(ifr.ifr_addr))->sin_addr);     
    memcpy(ip, temp, strlen(temp));

    close(inet_sock);

    return 0;
}
int main(void){
    int sock_fd;
    char buf[1024], sendbuf[1024], recvbuf[1024];
    struct sockaddr_in server_addr;
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);//初始化socket
    if(sock_fd == -1){
        printf("%s\n",strerror(errno));
        return 0;
    }

    bzero(&server_addr, sizeof(server_addr));//编辑服务端地址信息
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(Port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//inet_addr(“127.0.0.1”)

    int tmp = connect(sock_fd, (struct sockaddr *)(&server_addr), 
        sizeof(struct sockaddr));//连接服务端socket
    if(tmp == -1){
        printf("%s\n",strerror(errno));
        return 0;
    }
//获取IP
	char ip[1024] = {0};

    get_local_ip(IF_NAME, ip);

    if(0 != strcmp(ip, ""))
        printf("%s ip is %s\n",IF_NAME, ip);
//获取系统时间
time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	printf("%d\\%d\\%d\n ",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
	printf("%d:%d:%d\n",p->tm_hour+8,p->tm_min,p->tm_sec);
//系统时间添加到IP字符串中
	char str[20];
	sprintf(str,"%d",(1900+p->tm_year));
	strcat(ip," ");
	strcat(ip,str);
	sprintf(str,"%d",(1+p->tm_mon));
	strcat(ip,"\\");
	strcat(ip,str);
	sprintf(str,"%d",p->tm_mday);
	strcat(ip,"\\");
	strcat(ip,str);
	sprintf(str,"%d",p->tm_hour+8);
	strcat(ip," ");
	strcat(ip,str);
	sprintf(str,"%d",p->tm_min);
	strcat(ip,":");
	strcat(ip,str);
	sprintf(str,"%d",p->tm_sec);
	strcat(ip,":");
	strcat(ip,str);
	printf("%s\n",ip);
	printf("%d\n",strlen(ip));
    while(1){
        send(sock_fd, ip, strlen(ip), MSG_NOSIGNAL);
        recv(sock_fd, recvbuf, sizeof(recvbuf), 0);
    }
    close(sock_fd);
    return 0;
}
