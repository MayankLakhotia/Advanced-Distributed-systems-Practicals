#include <stdio.h>
#include <unistd.h>
int main()
{
int pipefds[2];
int isPoss;
int f1, f2;
char writemsg1[20];
char writemsg2[20];
printf("enter first message\n");
fgets(writemsg1,sizeof(writemsg1),stdin);
printf("enter second message\n");
fgets(writemsg2,sizeof(writemsg2),stdin);
char Readmsg[20];
isPoss = pipe(pipefds);
if (isPoss == -1)
{
printf("Can not create pipe\n");
return 1;
}
f1 = fork();
f2 = fork();
if (f1 > 0)
{
read(pipefds[0], Readmsg, sizeof(Readmsg));
printf("Child1 Process - Reading from M1 is %s\n", Readmsg);
read(pipefds[0], Readmsg, sizeof(Readmsg));
printf("Child1 Process - Reading from M2 is %s\n", Readmsg);
}
else if (f2 > 0)
{
printf("Child2 Process - Writing to pipe M1 is %s\n", writemsg1);
write(pipefds[1], writemsg1, sizeof(writemsg1));
printf("Child2 Process - Writing to pipe M2 is %s\n", writemsg2);
write(pipefds[1], writemsg2, sizeof(writemsg2));
}
return 0;
}