#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int main()
{
        int a=fork();
        if(a<0){cout<<"cchild not created";}
        else if(a==0){
                cout<<"child process!!!!";
                sleep(10);
        }
        else{
                wait(NULL);
                cout<<"parent process!!!";
        }
        return 0;
}
