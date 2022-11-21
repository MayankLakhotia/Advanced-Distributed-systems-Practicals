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
int clientfd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if(clientfd==-1)
{
perror("S error\n");//Socket Error
exit(0);
}
struct sockaddr_in server,client;
server.sin_family = AF_INET;
server.sin_port = htons(5000);
server.sin_addr.s_addr = inet_addr("127.0.0.1");
int c=connect(clientfd, (struct sockaddr *)&server, sizeof(server));
if(c==-1)
{
perror("C error\n");//Connection error
exit(0);
}
printf("Connection successful\n");
char snd[20], rcv[20];
while(1)
{
printf("Client : ");
scanf("%s",snd);
send(clientfd,snd,strlen(snd),0);
if(strcmp(snd,"stop")==0)// To stop the conversation stop key use
break;
int r=recv(clientfd, rcv, sizeof(rcv),0);
rcv[r]='\0';
printf("Server : %s\n",rcv);
}
}/* when one client is with server other have to wait when one client leave
other can join and complete its work with server. */