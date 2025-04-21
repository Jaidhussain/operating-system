#include<iostream>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
        int n,fd;
        fd=open("filea.txt",O_RDONLY);
        char b[50];
        n=read(fd,b,15);
        write(1,b,15);
        return 0;
}
