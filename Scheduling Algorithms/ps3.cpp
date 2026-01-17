#include<bits/stdc++.h>
using namespace std;
 
struct Process
{
    int process_id;  
    int b;
    int priority; 
};
 
bool compare(Process a, Process b)
{
    return (a.priority > b.priority);
}
 
void waittime(Process proc[], int n,
                     int w[])
{
    w[0] = 0;
 
    for (int  i = 1; i < n ; i++ )
        w[i] =  proc[i-1].b + w[i-1] ;
}
 
void turn_around_time( Process proc[], int n,
                         int w[], int time[])
{
   for (int  i = 0; i < n ; i++)
        time[i] = proc[i].b + w[i];
}
 
void findavgTime(Process proc[], int n)
{
    int w[n], time[n], total_weight = 0, total_time = 0;
 
   waittime(proc, n, w);
 
   turn_around_time(proc, n, w, time);
 
  cout << "\nProcesses  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";
 
 for (int  i=0; i<n; i++)
    {
        total_weight = total_weight + w[i];
        total_time = total_time + time[i];
        cout << "   " << proc[i].process_id << "\t\t"
             << proc[i].b << "\t    " << w[i]
             << "\t\t  " << time[i] <<endl;
    }
 
    cout << "\nAverage waiting time = "
         << (float)total_weight / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_time / (float)n;
}
 
void ps(Process proc[], int n)
{
   sort(proc, proc + n, compare);
 
    cout<< "Order in which processes gets executed \n";
    for (int  i = 0 ; i <  n; i++)
        cout << proc[i].process_id <<" " ;
 
    findavgTime(proc, n);
}
 
int main()
{
    
  cout<<"\n\n*************Priority Scheduling**************\n";
    Process proc[] = {{1,8 , 6}, {2, 12, 3}, {3, 8, 2},{4,11,4},{5,9,1},{6,10,6}};
    int n = sizeof proc / sizeof proc[0];
    ps(proc, n);
    cout<<"\n\n";
    return 0;
}
