#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>
int main(int argc, char* argv[]){
int fd[2];
if(pipe(fd) == -1){
printf("An error occured with opening the pipe\n");
return 1;
}
int id = fork();
if(id==0){
close(fd[0]);
int x;
printf("Input a no.");
scanf("%d",&x);
if (write(fd[1], &x, sizeof(int)) == -1){
printf("An error occured with the pipe\n");
return 2;
}
close(fd[1]);
}else{
close(fd[1]);
int y;
read(fd[0], &y, sizeof(int));
close(fd[0]);
printf("Got from child Process %d\n",y);
}
return 0;
}