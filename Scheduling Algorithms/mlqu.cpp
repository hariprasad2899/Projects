#include <bits/stdc++.h>
using namespace std;
int main()
{
	int p[20],b[20], s[20], w[20],time[20],i, k, n, temp;
	float w_avg, total_avg;
	cout<<"*********Multilevel Queue********\n";
	cout<<"Enter the number of processes:";
	cin>>n;
		for(i=0;i<n;i++)
	{
		p[i] = i;
	cout<<"Enter the Burst Time of Process:";
		cin>>b[i];
		cout<<"System/User Process (0/1) ? ";
		cin>>s[i];
	}
	
		for(i=0;i<n;i++)
		for(k=i+1;k<n;k++)
			if(s[i] > s[k])
			{
			temp=p[i];
			p[i]=p[k];
			p[k]=temp;
			temp=b[i];
			b[i]=b[k];
			b[k]=temp;
			temp=s[i];
			s[i]=s[k];
			s[k]=temp;
			}
	w_avg = w[0] = 0;
	total_avg = time[0] = b[0];
	for(i=1;i<n;i++)
	{
		w[i] = w[i-1] + b[i-1];
		time[i] = time[i-1] + b[i];
		w_avg = w_avg + w[i];
		total_avg = total_avg + time[i];
	}
	cout<<"\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME";
	for(i=0;i<n;i++){
		cout<<"\n";cout<<p[i];
		cout<<"\t\t";cout<< s[i];
		cout<<"\t\t\t";cout<<b[i];
		cout<<"\t\t ";cout<<w[i];
		cout<<"\t\t";cout<< time[i] ;
	
	}
	cout<<"\nAverage Waiting Time is --- "<<w_avg/n;
	cout<<"\nAverage Turnaround Time is ---" <<total_avg/n;
	cout<<"\n";
	return 0;
}
