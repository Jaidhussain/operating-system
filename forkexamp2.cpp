#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
void forkexample()
{
        if(fork()==0)
        {
                printf("hello from child!\n");
                execlp("/bin/is","",NULL);
        }
        else
        {
                wait(NULL);
                printf("Hello from parent!\n");
        }
}
int main()
{
        forkexample();
        return 0;
}
