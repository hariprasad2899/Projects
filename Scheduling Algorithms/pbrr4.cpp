
#include <iostream>
#include <queue>   	
#include <fstream>	
#include <cstdlib>     
using namespace std;
void c_bq(); 
class data
{	public:
	string PID;
	int AT, CPU1, IO, CPU2, priority, time, w, finish_time,wio ; 
	bool is_in_any_queue; 
	data() 
	{
		AT = 0; CPU1 = 0; IO = 0; CPU2 = 0; priority = 0 ; finish_time = 0; wio = 0; time = 0; w=0 ; is_in_any_queue = false;
	}
};	
	string temp;
	data p[5]; 			
	data check;				
	data r_process; 	
	data object[5];			
	int total_cpu_time = 0 ;
	int cpu_time = 0;
	int quantum = 0;
	int idle_time = 0;
	int processes_range;
	int total_lines = 0;
	queue<data> readyqueue;
	queue<data> bq;
int main()
{
	cout<<"\n\n ******Priority Based Round Robin Algorithm *********\n";
	cout << "Enter Quantum: "<<endl;
	cin >> quantum ;
	
p[0].AT=0;
p[1].AT=3;
p[2].AT=6;
p[3].AT=8;
p[4].AT=11;
p[0].PID="p1";
p[1].PID="p2";
p[2].PID="p3";
p[3].PID="p4";
p[4].PID="p5";
p[0].CPU1=6;
p[1].CPU1=4;
p[2].CPU1=8;
p[3].CPU1=15;
p[4].CPU1=13;
p[0].CPU2=8;
p[1].CPU2=11;
p[2].CPU2=6;
p[3].CPU2=11;
p[4].CPU2=7;
p[0].priority=2;
p[1].priority=4;
p[2].priority=5;
p[3].priority=1;
p[4].priority=3;
p[0].IO=15;
p[1].IO=10;
p[2].IO=12;
p[3].IO=9;
p[4].IO=18;
for (int i=0 ; i <=4 ; i++)
	{
			total_cpu_time = total_cpu_time + (p[i].CPU1 + p[i].CPU2 + p[i].IO) ; 
	} 
	for(int i=0;i<=4;i++)
	{
		for(int j=0;j<4-i;j++)
		{
			if(p[j].AT > p[j+1].AT)
			 {			 
				check = p[j];
				p[j] = p[j+1];
				p[j+1]=check;
			 }
		}
	}

	
	cpu_time = p[0].AT; 
	if (cpu_time != 0) 
	{
		idle_time = idle_time + cpu_time;
	}
	while (cpu_time <= total_cpu_time)
	{
		for (int i=0 ; i<=4 ; i++)
		{
			if (p[i].AT <= cpu_time && p[i].is_in_any_queue == false)
			{
				if (p[i].CPU1 == 0 )
				{
					p[i].wio = cpu_time + p[i].IO;
					bq.push(p[i]);
					p[i].is_in_any_queue = true;
				}
				else
				{
				readyqueue.push(p[i]);
				p[i].is_in_any_queue = true;
				}
			}
		}
		c_bq(); //Function Call

	
		int N = readyqueue.size();
		if (N==0)
		{
			int P = bq.size();
			if (N+P == 0) 
			{
				cout <<"Output Table Shown Below"<<endl;
				for (int i=0 ; i <=4 ; i++)
				{
						if (i==0)
						{ cout << "Process\t" ; cout <<"AT\t"; cout <<"FT\t"; cout <<"time\t"; cout <<"w\t"<<endl;};
						cout << p[i].PID<<"\t";cout << p[i].AT<<"\t";cout << p[i].finish_time<<"\t";cout << p[i].time<<"\t";cout << p[i].w<<"\t";cout <<endl;
				}
				float w;
				float time;
				w = p[0].w + p[1].w + p[2].w + p[3].w + p[4].w;
				w = w/5;
				time = p[0].time + p[1].time + p[2].time + p[3].time + p[4].time;
				time = time/5;	
				cout << "Average Waiting Time is: "<<w<<endl;
				cout << "Average TurnAroundTime is: "<<time<<endl;
				float y = (cpu_time-1)-idle_time;
				float x = cpu_time-1;
				float result ;
				result = (y/x)*100 ;
				cout << "CPU utilization percentage is : " << result <<"%"<<endl;
				cpu_time  = total_cpu_time+1;		
			}
			idle_time = idle_time + 1;
			cpu_time = cpu_time + 1;
		}
		else 
		{
			if (N != 1)
			{
				for (int i=0 ; i<N ; i++)
				{
					object[i] = readyqueue.front();
					readyqueue.pop();
				}
				for (int i=0 ; i< N ; i++)
				{
					for (int j= 0 ; j< ((N-1)-i) ; j++)
					{
						if (object[j].priority > object[j+1].priority)
						{
							check = object[j];
							object[j]= object[j+1];
							object[j+1] = check;
						}
						if (object[j].priority == object[j+1].priority) 
						{
							if (object[j].AT == object[j+1].AT)
							{
								int u = atoi (&object[j].PID[1]); 
								int v = atoi (&object[j+1].PID[1]);
								if (u > v )
								{
									check = object[j];
									object[j]= object[j+1];
									object[j+1] = check;
								}	
							}
							else
							{
								if (object[j].AT > object[j+1].AT)  
								{
									check = object[j];
									object[j]= object[j+1];
									object[j+1] = check;
								}
							}
							
						}
					}
				}
				for (int i=0; i<N ; i++)
				{
					readyqueue.push(object[i]);
				}
			}
			r_process = readyqueue.front(); 
			readyqueue.pop();	
		if (r_process.CPU1 != 0)
			{
				if (r_process.CPU1 > quantum)
				{
					r_process.CPU1 = r_process.CPU1 - quantum;
					cpu_time = cpu_time + quantum;
					readyqueue.push(r_process); 
				}
				else
				{
					int b = r_process.CPU1;
					cpu_time = cpu_time + b;
					r_process.CPU1 = 0;
					r_process.wio = cpu_time + r_process.IO; 
					bq.push(r_process); 
				}
			}
			else
			{
				if (r_process.CPU2 > quantum)
				{
					r_process.CPU2 = r_process.CPU2 - quantum;
					cpu_time = cpu_time + quantum;
					readyqueue.push(r_process);  
				}
				else 
				{
					int b = r_process.CPU2;
					cpu_time = cpu_time + b;
					r_process.CPU2 = 0;
					r_process.finish_time = cpu_time;
					r_process.time =r_process.finish_time - r_process.AT ; 

					if (r_process.PID == "P1")
					{
						int z=0;
						z = p[z].CPU1+p[z].CPU2;
						p[0].time = r_process.time;
						p[0].w = r_process.time - z;
						p[0].finish_time = r_process.finish_time ;

					}
					if (r_process.PID == "P2")
					{
						int z=1;
						z = p[z].CPU1+p[z].CPU2;
						p[1].time = r_process.time;
						p[1].w = r_process.time - z;
						p[1].finish_time = r_process.finish_time ;
					}
					if (r_process.PID == "P3")
					{
						int z=2;
						z = p[z].CPU1+p[z].CPU2;
						p[2].time = r_process.time;
						p[2].w = r_process.time - z;
						p[2].finish_time = r_process.finish_time ;
					}
					if (r_process.PID == "P4")
					{
						int z=3;
						z = p[z].CPU1+p[z].CPU2;
						p[3].time = r_process.time;
						p[3].w = r_process.time - z;
						p[3].finish_time = r_process.finish_time ;
					}
					if (r_process.PID == "P5")
					{
						int z=4;
						z = p[z].CPU1+p[z].CPU2;
						p[4].time = r_process.time;
						p[4].w = r_process.time - z;
						p[4].finish_time = r_process.finish_time ;
					}
				}
			}
		}
	}

cout<<"\n\n";
}
void c_bq()
{
		int N = bq.size();
		if (N == 0)
		{
			return;
		}
		else if (N!= 1) 
			{
				for (int i=0 ; i<N ; i++)
				{
					object[i] = bq.front();
					bq.pop();			
				}
				for (int i=0 ; i< N ; i++)
				{
					for (int j= 0 ; j< ((N-1)-i) ; j++)
					{
						if (object[j].wio > object[j+1].wio)
						{
							check = object[j];
							object[j]= object[j+1];
							object[j+1] = check;
						}
					}
				}
				for (int i=0; i<N ; i++)
				{
					bq.push(object[i]);
				}
			}
		for (int i=0 ; i<N ; i++)
		{
			check = bq.front();
			if (check.wio <= cpu_time) 
			{
			bq.pop();
			readyqueue.push(check);
			}
		}		
}
