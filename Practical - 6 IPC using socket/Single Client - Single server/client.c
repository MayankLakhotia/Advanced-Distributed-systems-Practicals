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
int sendfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
if(sendfd==-1)
{
perror("S error"); //Socket Error
exit(0);
}
struct sockaddr_in server,client;
server.sin_family = AF_INET;
server.sin_port=htons(5000);
server.sin_addr.s_addr=INADDR_ANY;
char snd[20], rcv[20];
while(1)
{
printf("Client : ");
scanf("%s", snd);
int size=sizeof(client);
sendto(sendfd, snd, strlen(snd), 0, (struct sockaddr *)&server ,sizeof(server));
if(strcmp(snd,"stop")==0) // To stop the conversation stop key use
break;
int len=recvfrom(sendfd, rcv,sizeof(rcv), 0,(struct sockaddr*)&client,&size);
rcv[len]='\0';
if(strcmp(rcv,"stop")==0) // To stop the conversation stop key use
break;
printf("Server : %s\n", rcv);
}
close(sendfd);
}