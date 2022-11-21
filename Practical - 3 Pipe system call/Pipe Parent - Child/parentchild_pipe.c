#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
int main()
{
int pipefds[2];
int returnstatus;
int pid;
char writemessages[2][20] = {"Hi", "Hello"};
char readmessage[20];
returnstatus = pipe(pipefds);
if (returnstatus == -1)
{
printf("Unable to create pipe\n");
return 1;
}
pid = fork();
bool cont = true;
// bool terminate = false;
int cnt = 0;
while (cont)
{
if (cnt % 2 == 0)
{
// Child process
if (pid == 0)
{
printf("Child process what you want to do \n 1. Write \n 2. Read \n 3.Quit");
int choice;
scanf("%d", &choice);
switch (choice)
{
// Write
case 1:
printf("Child Writing to pipe - Message 1 is %s\n",writemessages[0]);
write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
printf("Child Writing to pipe - Message 2 is %s\n",writemessages[1]);
write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
break;
// Read
case 2:
read(pipefds[0], readmessage, sizeof(readmessage));
printf("Child Reading from pipe – Message 1 is %s\n",readmessage);
read(pipefds[0], readmessage, sizeof(readmessage));
printf("Child Reading from pipe – Message 2 is %s\n",readmessage);
break;
case 3:
printf("Child Stop Conversation, Conversation ended no one left tochat with");
cont = false;
break;
}
}
else
{ // Parent process
printf("Parent process what you want to do \n 1. Write \n 2. Read \n 3.Quit");
int choice;
scanf("%d", &choice);
switch (choice)
{
// Write
case 1:
printf("Parent Writing to pipe - Message 1 is %s\n",writemessages[0]);
write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
printf("Parent Writing to pipe - Message 2 is %s\n",writemessages[1]);
write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
break;
// Read
case 2:
read(pipefds[0], readmessage, sizeof(readmessage));
printf("Parent Reading from pipe – Message 1 is %s\n",readmessage);
read(pipefds[0], readmessage, sizeof(readmessage));
printf("Parent Reading from pipe – Message 2 is %s\n",readmessage);
break;
case 3:
printf("Parent Quiting Conversation, Conversation ended no oneleft to chat with");
cont = false;
break;
}
}
}
else
{
// Child process
if (pid == 0)
{
printf("Child process what you want to do \n 1. Write \n 2. Read \n 3.Quit");
int choice;
scanf("%d", &choice);
switch (choice)
{
// Write
case 1:
printf("Child Writing to pipe - Message 1 is %s\n",writemessages[0]);
write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
printf("Child Writing to pipe - Message 2 is %s\n",writemessages[1]);
write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
break;
// Read
case 2:
read(pipefds[0], readmessage, sizeof(readmessage));
printf("Child Reading from pipe – Message 1 is %s\n",readmessage);
read(pipefds[0], readmessage, sizeof(readmessage));
printf("Child Reading from pipe – Message 2 is %s\n",readmessage);
break;
case 3:
printf("Child Quiting Conversation, Conversation ended no one leftto chat with");
cont = false;
break;
}
}
else
{ // Parent process
printf("Parent process what you want to do \n 1. Write \n 2. Read \n 3.Quit ");
int choice;
scanf("%d", &choice);
switch (choice)
{
// Write
case 1:
printf("Parent Process - Writing to pipe - Message 1 is %s\n",writemessages[0]);
write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
printf("Parent Process - Writing to pipe - Message 2 is %s\n",writemessages[1]);
write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
break;
// Read
case 2:
read(pipefds[0], readmessage, sizeof(readmessage));
printf("Parent Process - Reading from pipe – Message 1 is %s\n",readmessage);
read(pipefds[0], readmessage, sizeof(readmessage));
printf("Parent Process - Reading from pipe – Message 2 is %s\n",readmessage);
break;
case 3:
printf("Parent Quiting Conversation, Conversation ended no oneleft to chat with");
cont = false;
break;
}
}
cnt++;
}
}
return 0;
}