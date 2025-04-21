#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void forkexample()
{
        int p;
        p=fork();
        if(p==0)
        {
                printf("Hello from child!\n");
                printf("i am the child process having PID %d\n",getpid());
                printf("my parent PID %d\n",getpid());
        }
        else
        {
                printf("Hello from parent!\n");
                printf("i am the parent process having PID %d\n",getpid());
                printf("my child PID %d\n",p);
        }
        return 0;

}
