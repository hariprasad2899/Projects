
#include <iostream>
using namespace std;

struct process{
    int priority;
    int burst_T;
    int tt_time;
    int total_time=0;
};

struct queues{
    int priority_start;
    int priority_end;
    int total_time=0;
    int length = 0;
    process *p;
    bool exec = false;
};

bool nComp(queues q[]){
    bool a=false;
    int countInc=0;
        for(int i=0;i<3;i++){
                countInc=0;
            for(int j=0;j<q[i].length;j++){
                if(q[i].p[j].burst_T != 0){
                    a=true;
                }
                else{
                    countInc+=1;
                }
            }
            if(countInc==q[i].length){

                q[i].exec = true;
            }
        }
        return a;
}



void sort_ps(queues q){
    
    for(int i=1;i<q.length;i++){
        for(int j=0;j<q.length-1;j++){
            if(q.p[j].priority<q.p[j+1].priority){
                process temp = q.p[j+1];
                q.p[j+1] = q.p[j];
                q.p[j] = temp;
            }
        }
    }
}


void comp_timer(queues q[]){
    bool a = nComp(q);
    for(int i=0;i<3;i++){
        if(q[i].exec==false){
            for(int j=0;j<q[i].length;j++){
                if(q[i].p[j].burst_T!=0){
                    q[i].p[j].total_time+=1;
                }
            }
            q[i].total_time+=1;
        }
    }
}

int main(){
cout<<"\n\nMultilevel priority	Queue\n";
   queues q[3];
    q[0].priority_start = 7;
    q[0].priority_end = 9;
    q[1].priority_start = 4;
    q[1].priority_end = 6;
    q[2].priority_start = 1;
    q[2].priority_end = 3;

    int no_of_processes,priority_of_process,burst_T_of_process;
    cout<<"Enter the number of processes\n";
    cin>>no_of_processes;
    process p1[no_of_processes];

    for(int i=0;i<no_of_processes;i++){
        cout<<"Enter the priority of the process\n";
        cin>>priority_of_process;
        cout<<"Enter the burst time of the process\n";
        cin>>burst_T_of_process;
        p1[i].priority = priority_of_process;
        p1[i].burst_T = burst_T_of_process;
        p1[i].tt_time = burst_T_of_process;
        for(int j=0;j<3;j++){
        if(q[j].priority_start<=priority_of_process && priority_of_process<=q[j].priority_end){
            q[j].length++;
        }
        }
    }

    for(int i =0;i<3;i++){
        int len = q[i].length;
        q[i].p = new process[len];
    }


    int a=0;
    int b=0;
    int c=0;

    for(int i =0;i<3;i++){
        for(int j=0;j<no_of_processes;j++){
            if((q[i].priority_start<=p1[j].priority) && (p1[j].priority<=q[i].priority_end)){
                if(i==0){
                    q[i].p[a++] = p1[j];

                    }
                else if(i==1){
                    q[i].p[b++] = p1[j];
                    }
                else{
                    q[i].p[c++] = p1[j];
                    }
            }
        }
    }

    a--;b--;c--;
    for(int i=0;i<3;i++){
        cout<<"Queue "<<i+1<<" : \t";
        for(int j=0;j<q[i].length;j++){
            cout<<q[i].p[j].priority<<"->";
        }
        cout<<"NULL\n";
    }


   int timer = 0;
    int l =-1;
    int rr_timer = 4;
    int counter=0;
    int counterps=0;
    int counterfcfs=0;
    while(nComp(q)){
        if(timer == 10){
            timer = 0;
        }
        l+=1;
        if(l>=3){
            l=l%3;
        }

      if(q[l].exec == true){
                cout<<"Queue "<<l+1<<" completed\n";
            l+=1;
            if(l>=3){
                l=l%3;
            }
            continue;
        }

    
        if(l==0){
            cout<<"Queue "<<l+1<<" in hand\n";
           if(rr_timer == 0){
                rr_timer = 4;
            }

            for(int i=0;i<q[l].length;i++){
                if(q[l].p[i].burst_T==0){
                    counter++;
                    continue;
                }
                if(counter == q[l].length){
                    break;
                }
                while(rr_timer>0 && q[l].p[i].burst_T!=0 && timer!=10){
                    cout<<"Executing queue 1 and "<<i+1<<" process for a unit time. Process has priority of "<<q[l].p[i].priority<<"\n";
                    q[l].p[i].burst_T--;
                    comp_timer(q);
                    rr_timer--;
                    timer++;

                }
                if(timer == 10){
                    break;
                }
                if(q[l].p[i].burst_T==0 && rr_timer ==0){
                    rr_timer = 4;
                    if(i == (q[i].length-1)){
                        i=-1;
                    }
                    continue;
                }
                if(q[l].p[i].burst_T==0 && rr_timer > 0){
                    if(i == (q[i].length-1)){
                        i=-1;
                    }
                    continue;
                }
                if(rr_timer <= 0){
                    rr_timer = 4;
                    if(i == (q[i].length-1)){
                        i=-1;
                    }
                    continue;
                }

            }
        }


        else if(l==1){
            cout<<"Queue "<<l+1<<" in hand\n";
            sort_ps(q[l]);
            //Priority Scheduling
            for(int i=0;i<q[l].length;i++){
                if(q[l].p[i].burst_T==0){
                    counterps++;
                    continue;
                }
                if(counterps == q[l].length){
                    break;
                }
                while(q[l].p[i].burst_T!=0 && timer!=10){
                    cout<<"Executing queue 2 and "<<i+1<<" process for a unit time. Process has priority of "<<q[l].p[i].priority<<"\n";
                    q[l].p[i].burst_T--;
                    comp_timer(q);
                    timer++;

                }
                if(timer == 10){
                    break;
                }
                if(q[l].p[i].burst_T==0){
                        continue;
                }

            }
        }
        else{
            cout<<"Queue "<<l+1<<" in hand\n";
          
            for(int i=0;i<q[l].length;i++){
                if(q[l].p[i].burst_T==0){
                    counterfcfs++;
                    continue;
                }
                if(counterfcfs == q[l].length){
                    break;
                }
                while(q[l].p[i].burst_T!=0 && timer!=10){
                    cout<<"Executing queue 3 and "<<i+1<<" process for a unit time. Process has priority of "<<q[l].p[i].priority<<"\n";
                    q[l].p[i].burst_T--;
                    comp_timer(q);

                    timer++;
                }
                if(timer == 10){
                    break;
                }
                if(q[l].p[i].burst_T==0){
                        continue;
                }

            }

        }
        cout<<"Broke from queue "<<l+1<<"\n";
    }

    for(int i=0;i<3;i++){
            cout<<"\nTime taken for queue "<<i+1<<" to execute: "<<q[i].total_time<<"\n";
        for(int j=0;j<q[i].length;j++){
            cout<<"Process "<<j+1<<" of queue "<<i+1<<" took "<<q[i].p[j].total_time<<"\n";
        }
    }

    int sum_tt=0;
    int sum_wt=0;

    cout<<"\n\nProcess     | Turn Around Time | Waiting Time\n";
    for(int i=0;i<3;i++){
            cout<<"Queue "<<i+1<<"\n";
        for(int j=0;j<q[i].length;j++){
            cout<<"Process P"<<j+1<<"\t"<<q[i].p[j].total_time<<"\t\t    "<<q[i].p[j].total_time-q[i].p[j].tt_time<<"\n";
            sum_tt+=q[i].p[j].total_time;
            sum_wt+=q[i].p[j].total_time-q[i].p[j].tt_time;
        }
    }

    cout<<"\n The average turnaround time is : "<<sum_tt/no_of_processes<<endl;
    cout<<"\n The average waiting time is : "<<sum_wt/no_of_processes<<endl;
    
cout<<"\n\n";

}
