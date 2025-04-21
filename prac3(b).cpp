#include<iostream>
#include<unistd.h>
using namespace std;
int main(){
        cout<<"same program different code:"<<endl;
        pid_t id = fork();
        if(id > 0)
        {
        cout<<"i am parent process"<<getpid()<<endl;
        }
        else if(id == 0)
        {
        cout<<"i am child process"<<getpid()<<endl;
        }
        else
        {
        cout<<"no child process created"<<getpid()<<endl;
        }
        return 0;
}
