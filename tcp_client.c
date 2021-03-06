#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<sys/socket.h>  
#include<sys/types.h>  
#include<unistd.h>  
#include<netinet/in.h>  
#include "exch.h"
#define PORT 6666  
int main(int argc,char **argv)  
{  
    unsigned char RemotePorts[10];
    int RemotePort=0;
    int sockfd;  
    int err,n;  
    int mode;
    char mode_c;

    struct sockaddr_in addr_ser;  
    char sendline[20],recvline[20];  

    printf("Input Mode:(1=send,2=rec)");  
    scanf("%c",&mode_c); 

    mode=asctohex(mode_c);
    printf("mode=%d\n",mode);
      
    sockfd=socket(AF_INET,SOCK_STREAM,0);  
    if(sockfd==-1)  
    {  
        printf("socket error\n");  
        return -1;  
    }  

    printf("Input Connect Port:");  
    scanf("%s",&RemotePorts); 

    RemotePort=strtoint(RemotePorts);
    printf("RemotePort=%d\n",RemotePort);
      
    bzero(&addr_ser,sizeof(addr_ser));  
    addr_ser.sin_family=AF_INET;  
    addr_ser.sin_addr.s_addr=htonl(INADDR_ANY);  
    addr_ser.sin_port=htons(RemotePort);  
    err=connect(sockfd,(struct sockaddr *)&addr_ser,sizeof(addr_ser));  
    if(err==-1)  
    {  
        printf("connect error\n");  
        return -1;  
    }  
      
    printf("connect with server...\n");  
      
    while(1)  
    {  
	switch(mode)
	{
		case 1:
			//printf("Input your words:");  
        		//scanf("%s",&sendline);  
          
        		//send(sockfd,sendline,strlen(sendline),0);  
			send(sockfd,"ABCDEFG",7,0);
			usleep(500000);
		break;
		case 2:
			//printf("waiting for server...\n");  
      
        		n=recv(sockfd,recvline,100,0);  
        		recvline[n]='\0';  
          
        		printf("recv data is:%s\n",recvline);  
		break;
		default:
		break;	
	}
        
      
        
    }  
      
      
    return 0;  
}  