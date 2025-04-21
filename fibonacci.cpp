#include<iostream>
#include<pthread.h>
#include<sys/wait.h>
using namespace std;

int limit;

void* fibonacci(void* arg)
{
        int a=0;
        int b=1;
        int c=0;
        cout<<"fibonacci series:";
        while(a<= limit)
        {
                cout<<a<<" ";
                c= a+b;
                a=b;
                b=c;
        }
        cout<<"\n";
        return NULL;
}
int main()
{
        cout<<"Enter the limit of fibonacci series: ";
        cin>>limit;
        pthread_t thread;
        pthread_create(&thread, NULL, fibonacci, NULL);
        wait(NULL);
        pthread_exit(NULL);
        return 0;
}
