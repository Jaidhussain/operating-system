#include<iostream>
using namespace std;
#include<unistd.h>
int main()
{
        char a[30];
        read(0,a,10);   //read will return total no of characters read

        write(1,a,10);  //write will return total no of characters written
        return 0;
}
