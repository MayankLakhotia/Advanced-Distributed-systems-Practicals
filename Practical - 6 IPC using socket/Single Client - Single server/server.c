#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<unistd.h>
int main()
{
int recevfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
if(recevfd==-1)
{
perror("S error"); //Socket Error
exit(0);
}
struct sockaddr_in server,client;
server.sin_family = AF_INET;
server.sin_port=htons(5000);
server.sin_addr.s_addr=INADDR_ANY;
int b=bind(recevfd, (struct sockaddr *)&server, sizeof(server));
if(b==-1)
{
perror("b error"); //Bind Error
exit(0);
}
char rcv[20], snd[20];
while(1)
{
int size=sizeof(server);
int len=recvfrom(recevfd, rcv, sizeof(rcv),0,(struct sockaddr *)
&client,&size);
rcv[len]='\0';
if(strcmp(rcv,"stop")==0)
break;
printf("Client : %s\n", rcv);
printf("Sender : ");
scanf("%s",snd);
sendto(recevfd,snd,strlen(snd),0,(struct sockaddr *)&client,sizeof(client));
if(strcmp(snd,"stop")==0) // To stop the conversation stop key use
break;
}
close(recevfd);
}