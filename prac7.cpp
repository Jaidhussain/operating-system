#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
        int n,fd,fd1;
        fd=open("filea.txt",O_RDONLY);
        char b[50];
        n=read(fd,b,15);
        fd1=open("filea",O_CREAT|O_WRONLY,0642);
        write(fd1,b,n);
        return 0;
}
