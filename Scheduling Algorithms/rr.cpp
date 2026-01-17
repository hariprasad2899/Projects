
#include<iostream>
using namespace std;


void findWaitingTime(int processes[], int n,
			int b[], int wt[], int q)
{
	
	int temp[n];
	for (int i = 0 ; i < n ; i++)
		temp[i] = b[i];

	int t = 0;

	while (1)
	{
		bool done = true;

		for (int i = 0 ; i < n; i++)
		{
		if (temp[i] > 0)
			{
				done = false; 

				if (temp[i] > q)
				{
					t += q;

					
					temp[i] -= q;
				}

			else
				{

					t = t + temp[i];

					wt[i] = t - b[i];

					temp[i] = 0;
				}
			}
		}

		if (done == true)
		break;
	}
}

void turn_around_time(int processes[], int n,
						int b[], int wt[], int totaltime[])
{
	for (int i = 0; i < n ; i++)
		totaltime[i] = b[i] + wt[i];
}

void findavgTime(int processes[], int n, int b[],
									int q)
{
	int wt[n], totaltime[n], total_weight = 0, total_totaltime = 0;

	findWaitingTime(processes, n, b, wt, q);

	turn_around_time(processes, n, b, wt, totaltime);

	cout << "PN\t "<< " \tb "
		<< "      WT" << "         totaltime\n";

	for (int i=0; i<n; i++)
	{
		total_weight = total_weight + wt[i];
		total_totaltime = total_totaltime + totaltime[i];
		cout << " " << i+1 << "\t\t" << b[i] <<"\t "
			<< wt[i] <<"\t\t " << totaltime[i] <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_weight / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_totaltime / (float)n;
}

int main()
{
int processes[] = { 1, 2, 3,4,5};
	int n = sizeof processes / sizeof processes[0];

	int burst_time[] = {10,5,8,1,2};

int q = 2;
	cout<<"\n\n*******Round Robin*******\n\n";
	findavgTime(processes, n, burst_time, q);
	cout<<"\n\n";
	return 0;
}

