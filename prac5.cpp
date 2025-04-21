#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
        cout<<"-------------system kernel --------------"<<endl;
        system("uname -r ");
        cout<<"------------cpu information -------------"<<endl;
        system("lscpu | head -8 > cpuinfo.txt");
        system("cat cpuinfo.txt");
        return 0;
}
