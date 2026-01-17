#include <bits/stdc++.h>
using namespace std;
struct Process {
   int process_id; 
   int b;
   int at;
};
void turnaroundtime(Process proc[], int n, int weight[], int time[]) {
   for (int i = 0; i < n; i++)
   time[i] = proc[i].b + weight[i];
}
void waitingtime(Process proc[], int n, int weight[]) {
   int rt[n];
   for (int i = 0; i < n; i++)
   rt[i] = proc[i].b;
   int flag = 0, t = 0, minm = INT_MAX;
   int st = 0, ft;
   bool flag2 = false;
   while (flag != n) {
      for (int j = 0; j < n; j++) {
         if ((proc[j].at <= t) && (rt[j] < minm) && rt[j] > 0) {
            minm = rt[j];
            st = j;
            flag2 = true;
         }
      }
      if (flag2 == false) {
         t++;
         continue;
      }
      rt[st]--;
      minm = rt[st];
      if (minm == 0)
         minm = INT_MAX;
        if (rt[st] == 0) {
            flag++;
            flag2 = false;
            ft = t + 1;
           weight[st] = ft -
            proc[st].b -
            proc[st].at;
            if (weight[st] < 0)
               weight[st] = 0;
         }

         t++;
   }
}
void findavgTime(Process proc[], int n) {
   int weight[n], time[n], total_weight = 0,
   total_time = 0;

   waitingtime(proc, n, weight);
  
   turnaroundtime(proc, n, weight, time);
   cout << "Processes ";
   cout<< " Burst time " ;
   cout<< " Waiting time ";
   cout<< " Turn around time\n";
   for (int i = 0; i < n; i++) {
      total_weight = total_weight + weight[i];
      total_time = total_time + time[i];
      cout << " " << proc[i].process_id << "\t\t" << proc[i].b << "\t\t " << weight[i] << "\t\t " << time[i] << endl;
   }
   cout << "Average waiting time = ";
   cout<< (float)total_weight / (float)n; 
   cout << "\nAverage turn around time = " ;
   cout<< (float)total_time / (float)n;
}

int main() {
    	cout<<"\n\n**********short Job First ************\n";
  Process proc[] = { { 1, 11, 2 }, { 2, 2, 8 }, { 3, 9, 3 }, { 4, 3, 1 },{5,5,5},{6,2,7},{7,4,8} };
    int n = sizeof(proc) / sizeof(proc[0]);
   findavgTime(proc, n);
      cout<<"\n\n";
   return 0;
}
