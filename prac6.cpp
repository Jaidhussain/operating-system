#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
using namespace std;
void memoryinfo()
{
        cout<<"------------Memory information --------------"<<endl;
        system("free -h | head -4 > sysinfo.txt");

        system("cat sysinfo.txt");
}
int main()
{
        memoryinfo();
        return 0;
}
