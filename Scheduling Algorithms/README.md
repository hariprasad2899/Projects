# CPU Scheduling Algorithms Implementation

A comprehensive collection of CPU scheduling algorithms implemented in C++. This project demonstrates various scheduling techniques used by operating systems to manage process execution and optimize CPU utilization.

## 📋 Project Overview

This project implements seven different CPU scheduling algorithms, each with its own characteristics, advantages, and use cases. The implementations calculate key performance metrics including waiting time, turnaround time, and their averages for process scheduling evaluation.

## 🎯 Implemented Algorithms

### 1. **FCFS (First Come First Serve)** - `fcfs.cpp`
- **Type**: Non-preemptive
- **Principle**: Processes are executed in the order they arrive
- **Characteristics**: Simple, fair, but may cause convoy effect
- **Input**: Process IDs and burst times
- **Output**: Waiting time, turnaround time, and averages

### 2. **SJF (Shortest Job First)** - `sjf2.cpp`
- **Type**: Preemptive/Non-preemptive
- **Principle**: Process with shortest burst time is executed first
- **Characteristics**: Optimal for minimizing average waiting time
- **Input**: Process IDs, burst times, and arrival times
- **Output**: Detailed scheduling table with waiting and turnaround times

### 3. **Round Robin (RR)** - `rr.cpp`
- **Type**: Preemptive
- **Principle**: Each process gets a fixed time quantum for execution
- **Characteristics**: Prevents starvation, suitable for time-sharing systems
- **Input**: Process IDs, burst times, and time quantum
- **Output**: Scheduling sequence with waiting and turnaround times

### 4. **Priority Scheduling (PS)** - `ps3.cpp`
- **Type**: Non-preemptive
- **Principle**: Processes are scheduled based on priority (higher priority first)
- **Characteristics**: Useful for real-time systems, but may cause starvation
- **Input**: Process IDs, burst times, and priorities
- **Output**: Execution order and performance metrics

### 5. **Multi-Level Queue (MLQ)** - `mlq.cpp`
- **Type**: Preemptive
- **Principle**: Processes are classified into different queues based on system/user type
- **Characteristics**: System processes have higher priority than user processes
- **Input**: Number of processes, burst times, and system/user classification
- **Output**: Scheduling table grouped by queue priority

### 6. **Multi-Level Queue Universal (MLQU)** - `mlqu.cpp`
- **Type**: Preemptive with time slicing
- **Principle**: Three-level queue system with different scheduling algorithms per queue
  - Queue 1 (Priority 7-9): Round Robin with time quantum 4
  - Queue 2 (Priority 4-6): Priority Scheduling
  - Queue 3 (Priority 1-3): FCFS
- **Characteristics**: Most sophisticated, combines multiple scheduling strategies
- **Input**: Interactive input for process priority and burst time
- **Output**: Detailed execution log with queue assignments and timing information

### 7. **Priority Based Round Robin (PBRR)** - `pbrr4.cpp`
- **Type**: Preemptive
- **Principle**: Combines priority scheduling with round robin, supports I/O operations
- **Characteristics**: Handles CPU bursts and I/O bursts, priority-based queue management
- **Input**: Time quantum and process data (arrival time, CPU1, I/O, CPU2, priority)
- **Output**: Complete scheduling simulation with I/O handling

## 📁 Project Structure

```
OSD Project 1/
├── fcfs.cpp              # First Come First Serve implementation
├── sjf2.cpp              # Shortest Job First implementation
├── rr.cpp                # Round Robin implementation
├── ps3.cpp               # Priority Scheduling implementation
├── mlq.cpp               # Multi-Level Queue (basic) implementation
├── mlqu.cpp              # Multi-Level Queue (universal) implementation
├── pbrr4.cpp             # Priority Based Round Robin implementation
├── fcfs.txt              # Text file (possibly containing test data)
└── README.md             # This file
```

## 🔧 Requirements

### Compiler
- **C++ Compiler**: GCC (G++) or any C++11 compatible compiler
- **Standard**: C++11 or later

### Libraries
- Standard C++ libraries (`iostream`, `queue`, `algorithm`, `bits/stdc++.h`)

## 🚀 Compilation & Execution

### Compiling Individual Programs

#### Windows (using MinGW or Visual Studio)
```bash
g++ -o fcfs.exe fcfs.cpp
g++ -o sjf.exe sjf2.cpp
g++ -o rr.exe rr.cpp
g++ -o ps.exe ps3.cpp
g++ -o mlq.exe mlq.cpp
g++ -o mlqu.exe mlqu.cpp
g++ -o pbrr.exe pbrr4.cpp
```

#### Linux/Mac
```bash
g++ -o fcfs fcfs.cpp
g++ -o sjf sjf2.cpp
g++ -o rr rr.cpp
g++ -o ps ps3.cpp
g++ -o mlq mlq.cpp
g++ -o mlqu mlqu.cpp
g++ -o pbrr pbrr4.cpp
```

### Running the Programs

#### FCFS
```bash
# Windows
fcfs.exe

# Linux/Mac
./fcfs
```

#### SJF (Shortest Job First)
```bash
# Windows
sjf.exe

# Linux/Mac
./sjf
```

#### Round Robin
```bash
# Windows
rr.exe

# Linux/Mac
./rr
```

#### Priority Scheduling
```bash
# Windows
ps.exe

# Linux/Mac
./ps
```

#### Multi-Level Queue (Basic)
```bash
# Windows
mlq.exe

# Linux/Mac
./mlq
# Follow prompts for number of processes, burst times, and system/user classification
```

#### Multi-Level Queue Universal
```bash
# Windows
mlqu.exe

# Linux/Mac
./mlqu
# Interactive input required:
# - Number of processes
# - Priority for each process (1-9)
# - Burst time for each process
```

#### Priority Based Round Robin
```bash
# Windows
pbrr.exe

# Linux/Mac
./pbrr
# Enter time quantum when prompted
```

## 📊 Sample Output Format

### Common Metrics
All algorithms output:
- **Process ID**: Identifier for each process
- **Burst Time**: Time required for process execution
- **Waiting Time**: Time process waits in ready queue
- **Turnaround Time**: Total time from arrival to completion
- **Average Waiting Time**: Mean waiting time across all processes
- **Average Turnaround Time**: Mean turnaround time across all processes

### Example Output (FCFS)
```
**********FCFS ************
Processes  Burst time  Waiting time  Turn around time
 1          10          0             10
 2          5           10            15
 3          8           15            23
 4          1           23            24
 5          2           24            26
Average waiting time = 14.4
Average turn around time = 19.6
```

## 🔍 Algorithm Details

### FCFS (First Come First Serve)
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- **Best For**: Batch systems, simple process management
- **Limitations**: Poor performance with varying burst times (convoy effect)

### SJF (Shortest Job First)
- **Time Complexity**: O(n²) for non-preemptive, O(n² log n) for preemptive
- **Space Complexity**: O(n)
- **Best For**: Minimizing average waiting time
- **Limitations**: May cause starvation, requires knowledge of burst times

### Round Robin
- **Time Complexity**: O(n × q) where q is time quantum
- **Space Complexity**: O(n)
- **Best For**: Time-sharing systems, interactive processes
- **Limitations**: Performance depends on time quantum selection

### Priority Scheduling
- **Time Complexity**: O(n log n) for sorting
- **Space Complexity**: O(n)
- **Best For**: Real-time systems, processes with defined priorities
- **Limitations**: May cause starvation for low-priority processes

### Multi-Level Queue
- **Time Complexity**: Varies based on queue implementation
- **Space Complexity**: O(n)
- **Best For**: Systems with different process categories
- **Limitations**: May cause starvation in lower priority queues

### MLQU (Multi-Level Queue Universal)
- **Time Complexity**: O(n × total_time) - most complex
- **Space Complexity**: O(n)
- **Best For**: Complex systems requiring multiple scheduling strategies
- **Features**: Time slicing, multiple queue levels, different algorithms per queue

### PBRR (Priority Based Round Robin)
- **Time Complexity**: O(n × total_burst_time)
- **Space Complexity**: O(n)
- **Best For**: Systems with I/O operations and priority requirements
- **Features**: Handles I/O bursts, priority-based queue management

## 📈 Performance Comparison

Each algorithm has different characteristics:

| Algorithm | Avg Waiting Time | Response Time | Throughput | Starvation Risk |
|-----------|------------------|---------------|------------|-----------------|
| FCFS      | High (for mixed) | High          | Medium     | No              |
| SJF       | Low              | Medium        | High       | Yes             |
| Round Robin| Medium           | Low           | Medium     | No              |
| Priority  | Low (high-prio)  | Low (high-prio)| Medium    | Yes             |
| MLQ       | Low (system)     | Low (system)  | High       | Yes             |
| MLQU      | Varies           | Low           | High       | Yes (low queue) |
| PBRR      | Medium           | Medium        | Medium     | Yes             |

## 🧪 Testing

### Test Case for FCFS
- Processes: [1, 2, 3, 4, 5]
- Burst Times: [10, 5, 8, 1, 2]

### Test Case for SJF
- Processes: [{1,11,2}, {2,2,8}, {3,9,3}, {4,3,1}, {5,5,5}, {6,2,7}, {7,4,8}]
- Format: {Process ID, Burst Time, Arrival Time}

### Test Case for Round Robin
- Processes: [1, 2, 3, 4, 5]
- Burst Times: [10, 5, 8, 1, 2]
- Time Quantum: 2

## 💡 Key Concepts Demonstrated

1. **Process Scheduling**: How operating systems select processes for CPU execution
2. **Preemption**: Interrupting running processes to allow others to execute
3. **Time Quantum**: Fixed time slice allocated to each process in Round Robin
4. **Priority Management**: Assigning and managing process priorities
5. **Queue Management**: Organizing processes into different priority queues
6. **Performance Metrics**: Calculating waiting time, turnaround time, and averages

## 🎓 Educational Value

This project is ideal for:
- Understanding CPU scheduling algorithms
- Learning operating system concepts
- Comparing different scheduling strategies
- Analyzing performance metrics
- Implementing complex data structures (queues, priority queues)

## 🔧 Customization

To modify test cases:
1. Edit the arrays in `main()` function of each file
2. For interactive programs (MLQ, MLQU, PBRR), provide input as prompted
3. Recompile and run to see results

## 📝 Notes

- **MLQU** requires interactive input and provides detailed execution logs
- **PBRR** handles processes with I/O operations and multiple CPU bursts
- Some algorithms use hardcoded test data; modify the `main()` function for custom inputs
- All algorithms assume all processes arrive at time 0 unless specified (SJF includes arrival times)

## 🤝 Contributing

This is an educational project. Suggestions for improvements, additional algorithms, or optimizations are welcome.

## 📄 License

This project is intended for educational purposes.

## 🙏 Acknowledgments

- Operating Systems Concepts (textbook references)
- CPU Scheduling Algorithm research papers
- C++ Standard Template Library documentation
