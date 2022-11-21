#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>
int main()
{
int serverfd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if(serverfd==-1)
{
perror("S error\n");// Socket error
exit(0);
}
struct sockaddr_in server,client;
server.sin_family = AF_INET;
server.sin_port = htons(5000);
server.sin_addr.s_addr = inet_addr("127.0.0.1");
int b=bind(serverfd, (struct sockaddr *)&server, sizeof(server));
if(b==-1)
{
perror("B error\n");// Binding error
exit(0);
}
listen(serverfd,5);
int size=sizeof(struct sockaddr);
char snd[20],rcv[20];
while(1)
{
int clientfd=accept(serverfd, (struct sockaddr *)&client,&size);
if(clientfd==-1)
{
perror("a error\n");// Accept error
exit(0);
}
printf("Connection accepted\n");
for(;;)
{
int r=recv(clientfd, rcv, sizeof(rcv),0);
rcv[r]='\0';
printf("Client : %s\n",rcv);
if(strcmp(rcv,"stop")==0)// To stop the conversation stop key use
break;
printf("Server : ");
scanf("%s",snd);
send(clientfd,snd,strlen(snd),0);
}
}
}