
#include<iostream>
using namespace std;

void waiting_time(int processes[], int n,
						int b[], int w[])
{
	w[0] = 0;

	// calculate waiting time
	for (int i = 1; i < n ; i++ )
		w[i] = b[i-1] + w[i-1] ;
}

// Here we find turn around time
void turnaround_time( int processes[], int n,
				int b[], int w[], int time[])
{
	
	for (int i = 0; i < n ; i++)
		time[i] = b[i] + w[i];
}

//Here we find average time
void average_time( int processes[], int n, int b[])
{
	int w[n], time[n], total_weight= 0, total_time = 0;

	waiting_time(processes, n, b, w);

	turnaround_time(processes, n, b, w, time);

	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";

for (int i=0; i<n; i++)
	{
		total_weight = total_weight + w[i];
		total_time = total_time + time[i];
		cout << " " << i+1 << "\t\t" << b[i] <<"\t "
			<< w[i] <<"\t\t " << time[i] <<endl;
	}

	cout << "Average waiting time = ";
		cout<< (float)total_weight / (float)n;
	cout << "\nAverage turn around time = ";
	cout<< (float)total_time / (float)n;
}

int main()
{
	   	cout<<"\n\n**********FCFS ************\n";
 int processes[]= { 1,2,3,4,5 };
 int n = sizeof processes / sizeof processes[0];

	int bursttime[] = {10,5,8,1,2};

	average_time(processes, n, bursttime);
	    cout<<"\n\n";
	return 0;
}
