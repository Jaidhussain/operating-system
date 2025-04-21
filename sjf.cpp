                        //SJF SCHEDULING
#include <iostream>
using namespace std;

//shortest process on arrival time


int shortest(int*burst,int*arrival,int time,int number)
{
        int index=-1;
        for(int i=0; i<number; i++)
        {
                if(arrival[i]<=time && burst[i]!=0)
                {
                        if(index==-1)
                                index=i;
                        else if(burst[index]> burst[i])
                                index=i;
                }
        }
        return index;
}
//controller
void controller(int *burst,int *arrival,int n)
{
        int *finish = new int[n];
        int *temp_burst = new int[n];
        for(int i=0; i<n; i++)
                temp_burst[i] = burst[i];
        int temp, control = 1;

        //finding the starting time
        int start=arrival[0];

        for(int i=1;i<n;i++)
                if(arrival[i]<start)
                        start=arrival[i];

        //finding maximum time required
        int max = start;
        for(int i=0; i<n;i++)
                max +=burst[i];

//process control at Every second
        cout<<"****************Gantt chart********************\n";
        cout<<"start\tprogram NO. \tEnd\n";

        for(int i=start; i<max; i++)
        {
                temp=shortest(burst,arrival,i,n);
                if(temp !=-1)
                        control=temp;
                if(control !=-1)
                        burst[control]--;
                if(burst[control]==0)
                        finish[control]=i+1;
                cout<<i<<"\t "<<control+1<<"\t\t"<<(i+1)<<"\n";
        }
//printing turn-around and waiting time
        double turn = 0,wait =0;
        cout<<"*************Final chart**************\n";
        cout<<"program NO.\tTurnaround\tWaiting\n";

        for(int i=0; i<n; i++)
        {
                cout<<i+1<<"\t\t";
                temp=finish[i] - arrival[i];
                cout<<temp<<"\t\t";
                turn =turn + temp;
                temp = finish[i] - (arrival[i] + temp_burst[i]);
                cout<<temp<<"\n";
                wait = wait+temp;
        }

        cout<<"\n\nAverage waiting time :"<<(wait/n)<<"\n";
        cout<<"Average Turnaround time :"<<(turn/n)<<"\n";
}
int main()
{
        cout<<"Enter the Number of process:";
        int n;
        cin>>n;
        cout<<"Enter Detail of each program...\n";
        int *burst=new int[n];
        int *arrival = new int[n];

        for(int i=0; i<n;i++)
        {
                cout<<"Burst time of program"<<i+1<<":";
                cin>>burst[i];
                cout<<"Arrival time of program"<<i+1<<":";
                cin>>arrival[i];
        }
        controller(burst,arrival,n);
        return 0;
}
