#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 4444
int main(){
	int sockfd,val,i,j=0,x=0,temp;
	char ch[10],p[4],con[14],conv[17],rem[4],real[17];
	struct sockaddr_in serverAddr;
	int newSocket;
	struct sockaddr_in newAddr;
	socklen_t addr_size;


	sockfd = socket(AF_INET, SOCK_STREAM,0);
	memset(&serverAddr,'\0',sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr =inet_addr("127.0.0.1");

	bind(sockfd,(struct sockaddr*)&serverAddr, sizeof(serverAddr));

	listen(sockfd,5);
	newSocket=accept(sockfd,(struct sockaddr*)&newAddr, &addr_size);
	printf("enter the message\n");
	scanf("%[^\n]%*c", ch);

	printf("enter the keyword\n");
	scanf("%[^\n]%*c",p);

	for(i=0;i<2;i++)
	{
		val=ch[i];
		j=0;
		while(val>0)
		{	
			if((val%2)==0)
				con[j++]='0';
			else
				con[j++]='1';
			val/=2;	}
			j=j-1;
			while(j>=0)
			{
				conv[x]=con[j];
				real[x]=con[j];
				x++;
				j--;
			}	

		}
		printf("converted binary msg:");
		for(i=0;i<14;i++)
			printf("%c",conv[i]);
		printf("\n");
		for(i=14;i<17;i++)
			conv[i]='0';
		for(i=0;i<17;i++)
		{
			temp=i;
			if(conv[i]=='1')
			{
				for(j=0;j<4;j++)
				{
					if(conv[temp]==p[j])
					{
						conv[temp]='0';
						rem[j]='0';
					}
					else
					{
						conv[temp]='1';
						rem[j]='1';
					}
					temp=temp+1;
				}
			}
			else
			{
			}
		}
		i=14;
		j=1;
		while(j<4)
		{
			real[i]=rem[j];
			i++;
			j++;
		}
		send(newSocket,real,strlen(real),0);
//send(newSocket,p,strlen(p),0);
		printf("[+] closing the connection\n");
		return 0;
	}
