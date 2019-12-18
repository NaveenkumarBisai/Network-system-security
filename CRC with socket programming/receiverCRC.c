#include<netinet/in.h>
#include<netdb.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#define PORT 4444
void main(){
	int clientSocket,i,j,temp;
	struct sockaddr_in serverAddr;
	char p[17],rem[4];
	char div[4]="1001";
	//socket
	clientSocket =socket(PF_INET,SOCK_STREAM,0);
	printf("[+]client socket created sucessfully \n");
	memset(&serverAddr,'\0',sizeof(serverAddr));
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(PORT);
	serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	//conect
	connect(clientSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
	printf("[+]connected to server.\n");
	//recv(clientSocket,buffer,1024,0);
	recv(clientSocket,p,17,0);

	printf("[+] Data Recv: ");
	for(i=0;i<17;i++)
		printf("%c",p[i]);
	for(i=0;i<17;i++)
	{
		temp=i;
		if(p[i]=='1')
		{
			for(j=0;j<4;j++)
			{
				if(p[temp]==div[j])
				{
					p[temp]='0';
					rem[j]='0';
				}
				else
				{
					p[temp]='1';
					rem[j]='1';
				}
				temp=temp+1;
			}
		}
	}
	printf("\nremainder:");
	for(j=0;j<4;j++)
		printf("%c",rem[j]);
	printf("\n");
	i=0;
	for(j=0;j<4;j++)
		if(rem[j]=='0')
			i++;
		if(i==4)
			printf("received date is error free\n");
		else
			printf("received data contains error\n");
//	printf("[+]Closing the connection\n");
	}
