#include<iostream>
using namespace std;
#include<sys/types.h>
#include<unistd.h>
int main()
{
        //make two process which run same
        //program after this instruction
        fork();

        cout<<"Hello world!\n";
        return 0;
}
