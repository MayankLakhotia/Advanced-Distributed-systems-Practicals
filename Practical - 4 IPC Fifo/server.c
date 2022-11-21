//server.c
#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/sem.h>
int main() {
int file1,file2;
char a[20];
mkfifo("f1",0666);
perror("Client");
mkfifo("f2",0666);
perror("Server");
file1= open("f1", O_RDWR);
file2= open("f2", O_RDWR);
//printf("ID = %d\n",getpid());
if(fork())
{
while(1)
{
read(file1,a,sizeof(a));
printf("Message received from server = %s\n",a);
}
}
else
{
while(1)
{
printf("Enter a message to client...\n");
scanf("%s",a);
write(file2,a,strlen(a)+1);
}
}
}