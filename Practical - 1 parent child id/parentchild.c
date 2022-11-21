#include<stdio.h>
#include<unistd.h>
int main()
{
int p;
p=fork();
if(p<0)
{
printf("cannot be executed");
}
else if(p==0)
{
printf("child process id %d \n",getpid());
}
else{
printf("parent process id %d \n",getppid());
}
return 0;
}