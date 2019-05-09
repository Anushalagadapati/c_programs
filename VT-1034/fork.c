#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    pid_t pid;
    char *message;
    int n;

    printf("fork program starting\n");
    pid = fork();
if(pid)
{
printf("parent,childpid=%d\n",pid);
printf("parentpid=%d\n",getpid());
}
else
{
printf("child pid=%d\n",getpid());
printf("child parent=%d\n",getppid());
}
}


