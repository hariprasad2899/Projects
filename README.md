# Projects

# 1)  Tourist Behavior Analysis

A comprehensive big data analytics project that analyzes tourist behavior patterns using photo metadata from Flickr. This project performs geospatial clustering and seasonal trend analysis on tourist activity data from San Francisco and India to identify popular locations and temporal patterns.

## 📋 Project Overview

This project analyzes tourist behavior by processing photo metadata from social media platforms (Flickr) to:
- **Cluster tourist locations** using density-based clustering algorithms (HDBSCAN and OPTICS)
- **Identify popular tourist spots** through geospatial clustering
- **Analyze seasonal trends** in tourist visits using time-series analysis
- **Visualize patterns** on maps and charts

## 🎯 Key Features

1. **Metadata Processing**: Preprocesses raw photo metadata using NLP techniques (tokenization, stemming, stopword removal)
2. **Geospatial Clustering**: 
   - HDBSCAN (Hierarchical Density-Based Spatial Clustering)
   - OPTICS (Ordering Points To Identify the Clustering Structure)
3. **Seasonal Trend Analysis**: Polynomial regression to identify seasonal patterns in tourist visits
4. **Geographic Visualization**: Interactive maps showing cluster locations using Basemap
5. **Multi-Dataset Support**: Analysis performed on both San Francisco and India datasets

## 📁 Project Structure

```
Big Data Project/
├── GROUP_1.ipynb                          # Main Jupyter notebook with all analysis
├── Filtered1M.csv                         # Raw San Francisco dataset
├── fullindia.csv                          # Raw India dataset
├── TP1M.csv                               # Processed San Francisco data (intermediate)
├── TP_op1M.csv                            # Preprocessed San Francisco data (final)
├── TP1Mfullindia.csv                      # Processed India data (intermediate)
├── preprocessed_india_data.csv            # Preprocessed India data (final)
├── sf_hdb_before_clusters.png            # San Francisco: Before clustering
├── sf_hdb_after_clusters.png             # San Francisco: After HDBSCAN clustering
├── sf_optics_after_clusters.png          # San Francisco: After OPTICS clustering
├── sf_arrivalOfTouristsInParticularMonth.png  # San Francisco: Seasonal trends
├── sf_averageNoOfTouristsInParticularMonth.png # San Francisco: Monthly averages
├── india_hdb_before_clusters.png         # India: Before clustering
├── india_hdb_after_clusters.png          # India: After HDBSCAN clustering
├── india_optics_after_clusters.png       # India: After OPTICS clustering
├── india_arrivalOfTouristsInParticularMonth.png  # India: Seasonal trends
├── india_averageNoOfTouristsInParticularMonth.png # India: Monthly averages
└── README.md                              # This file
```

## 🔧 Technologies Used

### Python Libraries
- **pandas**: Data manipulation and analysis
- **numpy**: Numerical computing
- **nltk**: Natural Language Processing (tokenization, stemming, stopwords)
- **scikit-learn**: Machine learning (PolynomialFeatures, LinearRegression, OPTICS)
- **hdbscan**: Hierarchical density-based clustering
- **matplotlib**: Data visualization
- **mpl_toolkits.basemap**: Geographic mapping
- **folium**: Interactive map creation

### Data Processing
- Text preprocessing (lowercasing, stemming, stopword removal)
- Geospatial coordinate conversion (degrees to radians)
- Time-series data aggregation

### Clustering Algorithms
- **HDBSCAN**: Hierarchical density-based clustering with noise detection
- **OPTICS**: Density-based clustering that finds clusters of varying densities

## 📊 Dataset Description

### Data Fields
The datasets contain photo metadata with the following key fields:
- **LineNo**: Line number
- **PhotoID**: Unique photo identifier
- **UserID**: User who took the photo
- **DateTaken**: Timestamp when photo was taken
- **Latitude**: GPS latitude coordinate
- **Longitude**: GPS longitude coordinate
- **Accuracy**: GPS accuracy level

### Dataset Details
- **San Francisco Dataset** (`Filtered1M.csv`): ~2,671 records of photos taken in San Francisco area
- **India Dataset** (`fullindia.csv`): Photos taken across India

**Time Range**: 2004-2013 (10 years of data)

## 🚀 Getting Started

### Prerequisites

```bash
pip install pandas numpy nltk scikit-learn hdbscan matplotlib basemap folium
```

### Installation

1. Clone or download this repository
2. Install required Python packages:
   ```bash
   pip install pandas numpy nltk scikit-learn hdbscan matplotlib basemap folium
   ```
3. Download NLTK stopwords (automatically done in the notebook):
   ```python
   import nltk
   nltk.download('stopwords')
   ```

### Running the Analysis

1. Open `GROUP_1.ipynb` in Jupyter Notebook or JupyterLab
2. Ensure the CSV data files are in the same directory:
   - `Filtered1M.csv` (for San Francisco analysis)
   - `fullindia.csv` (for India analysis)
3. Run the notebook cells sequentially:
   - **Cells 1-6**: Metadata processing for San Francisco
   - **Cells 7-13**: Metadata processing for India
   - **Cells 14-27**: HDBSCAN clustering for both datasets
   - **Cells 14-20**: OPTICS clustering for both datasets
   - **Cells 21-27**: Seasonal trend analysis for both datasets

## 📈 Analysis Workflow

### 1. Metadata Processing
- Extract relevant columns from raw CSV files
- Apply text preprocessing (lowercasing, stemming, stopword removal)
- Clean and normalize geospatial coordinates and dates
- Output: Preprocessed CSV files ready for clustering

### 2. Geospatial Clustering

#### HDBSCAN Clustering
- Parameters:
  - `min_cluster_size=20`: Minimum points in a cluster
  - `metric='haversine'`: Distance metric for geographic coordinates
  - `algorithm='best'`: Algorithm variant
- Output: Cluster labels and exemplar points for each cluster

#### OPTICS Clustering
- Parameters:
  - `min_samples=10`: Minimum samples in a neighborhood
  - `max_eps=100`: Maximum distance for clustering
  - `metric='haversine'`: Geographic distance metric
- Output: Cluster assignments with varying densities

### 3. Seasonal Trend Analysis
- Aggregate photo counts by month and year (2004-2013)
- Apply polynomial regression (degree 2-3) for each month
- Calculate Mean Absolute Error (MAE) for trend predictions
- Visualize seasonal patterns and tourist arrival trends

### 4. Visualization
- **Before/After Clustering Maps**: Show data distribution and identified clusters
- **Seasonal Trend Charts**: Display monthly patterns and tourist arrivals
- **Color-coded Clusters**: Different colors for each cluster, black for outliers

## 📊 Results and Insights

The analysis generates several visualizations:

1. **Cluster Maps**: Identify popular tourist locations and hotspots
2. **Seasonal Patterns**: Understand peak tourism months
3. **Trend Analysis**: Predict future tourist behavior patterns
4. **Geographic Distribution**: Visualize spatial patterns of tourist activity

### Key Outputs
- Preprocessed datasets for further analysis
- Cluster representatives (exemplars) for each identified cluster
- Seasonal component metrics for each month
- High-resolution map visualizations (300 DPI)

## 🔍 Algorithm Details

### HDBSCAN
- **Advantages**: Handles noise, finds clusters of varying densities, no need to specify number of clusters
- **Use Case**: Identifying tourist hotspots with natural groupings
- **Time Complexity**: O(n log n) for building minimum spanning tree

### OPTICS
- **Advantages**: Handles varying cluster densities, identifies hierarchical structure
- **Use Case**: Finding both dense and sparse tourist areas
- **Time Complexity**: O(n²) in worst case, O(n log n) with spatial indexing

### Polynomial Regression
- **Purpose**: Model seasonal trends over the 10-year period
- **Method**: Degree 2-3 polynomial features with linear regression
- **Metrics**: Mean Absolute Error (MAE) for model evaluation

## 📝 Code Organization

### Metadata Processing Section
- **San Francisco Processing**: Cells 1-6
- **India Processing**: Cells 7-13
- Functions: Text cleaning, stemming, stopword removal

### Clustering Section
- **HDBSCAN Implementation**: Separate cells for SF and India
- **OPTICS Implementation**: Separate cells for SF and India
- Functions: Coordinate conversion, clustering, visualization

### Seasonal Analysis Section
- **Time-series Aggregation**: Monthly and yearly grouping
- **Regression Analysis**: Polynomial fitting for each month
- **Visualization**: Trend plots and seasonal component charts

## 📈 Performance Metrics

### Clustering Evaluation
- Number of clusters identified
- Noise/outlier points detected
- Cluster density and spread

### Regression Evaluation
- Mean Absolute Error (MAE) per month
- Seasonal component values
- Trend prediction accuracy

## 🎓 Key Concepts Demonstrated

1. **Big Data Processing**: Handling large-scale geospatial datasets
2. **NLP Techniques**: Text preprocessing for metadata cleaning
3. **Unsupervised Learning**: Density-based clustering algorithms
4. **Time-Series Analysis**: Seasonal pattern detection
5. **Geographic Information Systems**: Spatial data visualization
6. **Data Mining**: Extracting patterns from social media data

## 🔧 Configuration Options

### Clustering Parameters
- `min_cluster_size`: Adjust cluster sensitivity (default: 20)
- `min_samples`: Control neighborhood size (default: 10)
- `max_eps`: Set maximum distance for clustering (default: 100)

### Map Visualization
- `projection`: Map projection type (default: 'merc')
- `resolution`: Map resolution (default: 'l' for low)
- `dpi`: Image quality (default: 300)

## 📝 Notes

- The coordinate conversion to radians is necessary for the haversine distance metric
- Outliers (noise points) are labeled as -1 in cluster labels
- The analysis covers a 10-year period (2004-2013) for comprehensive trend analysis
- Maps use Mercator projection for accurate geographic representation
- Some text preprocessing is applied to numeric fields (may need refinement for production use)

## 🐛 Known Limitations

- Text preprocessing applied to numeric coordinates (consider separate handling)
- HDBSCAN and OPTICS require coordinate conversion for geographic data
- Basemap library may have installation issues on some systems (consider alternatives like Cartopy)

## 🔄 Future Enhancements

- Add more clustering algorithms (DBSCAN, K-means for comparison)
- Implement real-time data processing for live analysis
- Add sentiment analysis of photo tags
- Create interactive dashboards with Plotly/Dash
- Integrate weather data for correlation analysis
- Expand to more geographic regions

## 🤝 Contributing

This is an academic/research project. For questions or suggestions, please refer to the project documentation or contact the development team.

## 📄 License

This project is for educational and research purposes. Data sources and licensing information can be found in the original Flickr photo metadata.

## 🙏 Acknowledgments

- Flickr for providing photo metadata
- Open-source Python community for excellent data science libraries
- Geographic data visualization tools (Basemap, Folium)
- Contributors and researchers in the field of geospatial analytics

## 📚 References

- HDBSCAN documentation: https://hdbscan.readthedocs.io/
- OPTICS algorithm paper: "OPTICS: Ordering Points To Identify the Clustering Structure"
- Scikit-learn clustering: https://scikit-learn.org/stable/modules/clustering.html
- NLTK documentation: https://www.nltk.org/

## 🎯 Use Cases

- **Tourism Planning**: Identify popular destinations for infrastructure development
- **Seasonal Marketing**: Understand peak tourism periods for promotional campaigns
- **Urban Planning**: Analyze spatial patterns for city development
- **Research**: Academic research on human mobility and behavior patterns

- **Business Intelligence**: Insights for hospitality and travel industry

# 2) CPU Scheduling Algorithms Implementation

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

# 3) Custom Linux Shell Implementation

A fully functional custom Linux shell implementation in C that provides an interactive command-line interface with built-in commands, piping, I/O redirection, and command history support.

## 📋 Project Overview

This project implements a custom Linux shell that mimics the behavior of standard Unix/Linux shells (like bash or sh) while adding custom features. The shell can execute system commands, handle pipes, manage I/O redirection, and provides a set of built-in commands for enhanced user experience.

## 🎯 Features

### Core Functionality
- **Command Execution**: Execute system commands using `fork()` and `execvp()`
- **Built-in Commands**: Custom commands integrated into the shell
- **Piping Support**: Pipe output from one command to another using `|`
- **I/O Redirection**: Support for input/output redirection using `<` and `>`
- **Command History**: Maintain and display command history using GNU Readline library
- **Custom Prompt**: Interactive prompt showing current directory and user information
- **Space Handling**: Automatic handling of unnecessary spaces in commands

### Built-in Commands

1. **`exit`** - Exit the shell
   ```bash
   >>> exit
   ```

2. **`cd <directory>`** - Change current directory
   ```bash
   >>> cd /home/user/documents
   ```

3. **`help`** - Display help information
   ```bash
   >>> help
   ```

4. **`hello`** - Greet the current user
   ```bash
   >>> hello
   welcome username
   ```

5. **`history`** - Display command history with timestamps
   ```bash
   >>> history
   ```

### Advanced Features
- **Process Management**: Proper process creation and synchronization using `fork()` and `wait()`
- **Pipe Implementation**: Inter-process communication using pipes
- **File Descriptor Management**: Proper handling of stdin/stdout redirection
- **Command Parsing**: Tokenization and parsing of user commands
- **Error Handling**: Basic error checking for fork, exec, and pipe operations

## 📁 Project Structure

```
OSD Project 2/
├── code shell.txt                    # Main shell implementation (C source code)
├── Project 2 Linux shell.pdf         # Project documentation
├── Proposal.pdf                      # Project proposal
├── output attachments/               # Screenshots of shell in action
│   ├── Screenshot (26).png
│   ├── Screenshot (27).png
│   ├── Screenshot (28).png
│   ├── Screenshot (29).png
│   ├── Screenshot (30).png
│   └── Screenshot (32).png
└── README.md                         # This file
```

## 🔧 Requirements

### System Requirements
- **Operating System**: Linux/Unix-based system (Ubuntu, Debian, CentOS, etc.)
- **Compiler**: GCC (GNU Compiler Collection)
- **Libraries**: 
  - GNU Readline library (`libreadline-dev`)
  - Standard C libraries (stdlib, string, unistd, sys/wait)

### Installing Dependencies

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install build-essential libreadline-dev
```

#### CentOS/RHEL
```bash
sudo yum install gcc readline-devel
```

#### Fedora
```bash
sudo dnf install gcc readline-devel
```

## 🚀 Compilation & Execution

### Step 1: Prepare the Source File

Copy the contents of `code shell.txt` to a `.c` file:
```bash
cp "code shell.txt" shell.c
# OR rename the file
mv "code shell.txt" shell.c
```

### Step 2: Compile

```bash
gcc -o shell shell.c -lreadline
```

**Compilation Options:**
- `-o shell`: Specifies the output executable name
- `-lreadline`: Links the readline library

### Step 3: Run the Shell

```bash
./shell
```

### Step 4: Exit the Shell

Type `exit` or press `Ctrl+C` to exit the shell.

## 💻 Usage Examples

### Basic System Commands
```bash
>>> ls -la
>>> pwd
>>> cat file.txt
>>> echo "Hello World"
>>> date
```

### Built-in Commands
```bash
>>> help
>>> cd /home/user
>>> hello
>>> history
>>> exit
```

### Piping Commands
```bash
>>> ls -la | grep txt
>>> cat file.txt | wc -l
>>> ps aux | grep bash
```

### I/O Redirection
```bash
>>> ls > output.txt
>>> cat < input.txt
>>> echo "Hello" > file.txt
```

### Combined Operations
```bash
>>> ls -la | grep txt | wc -l
>>> cat file.txt | sort > sorted.txt
```

## 🔍 Code Architecture

### Key Functions

#### `main()`
- Entry point of the shell
- Initializes the shell and enters the main command loop
- Handles command parsing and execution routing

#### `input(char* str)`
- Reads user input using GNU Readline
- Adds commands to history automatically
- Returns 0 on success

#### `Sys_CMD_Execution(char** Pstr1)`
- Executes system commands
- Uses `fork()` to create child process
- Uses `execvp()` to replace process image
- Parent process waits for child completion

#### `PipeExecutionFuncion(char** Pstr1, char** Pstr1pipe)`
- Implements pipe functionality
- Creates pipe using `pipe()` system call
- Forks two processes for piped commands
- Manages file descriptor redirection (stdout/stdin)

#### `UserDefinedCommandsExecution(char** Pstr1)`
- Handles built-in commands (exit, cd, help, hello, history)
- Returns non-zero if command was built-in, 0 otherwise

#### `SPFunction(char* ss, char** Pstr1, char** Pstr1pipe)`
- Parses command string
- Detects pipes and separates commands
- Handles space normalization
- Returns execution flag (0=built-in, 1=system, 2=piped)

#### `refresh_screen()`
- Clears screen and displays welcome message
- Shows current username
- Provides splash screen on startup

### Data Structures

- **Command Parsing**: Uses tokenization with `strsep()`
- **Process Management**: Uses `pid_t` for process IDs
- **Pipe Communication**: Uses integer array for pipe file descriptors

## 🔧 Technical Details

### Process Creation
```c
pid_t threadNumber = fork();
if (threadNumber == 0) {
    // Child process
    execvp(command, arguments);
} else {
    // Parent process
    wait(NULL);
}
```

### Pipe Implementation
```c
int pipe_fd[2];
pipe(pipe_fd);
// First command writes to pipe_fd[1]
// Second command reads from pipe_fd[0]
```

### Readline Integration
- Uses GNU Readline for enhanced input handling
- Automatic history management
- Command-line editing capabilities

## 📊 Features Breakdown

### ✅ Implemented Features

| Feature | Status | Description |
|---------|--------|-------------|
| Basic Command Execution | ✅ | Execute any system command |
| Built-in Commands | ✅ | exit, cd, help, hello, history |
| Piping | ✅ | Connect commands with `\|` |
| I/O Redirection | ✅ | Input/output redirection with `<`, `>` |
| Command History | ✅ | View and navigate command history |
| Custom Prompt | ✅ | Shows current directory |
| Space Handling | ✅ | Removes unnecessary spaces |
| Process Synchronization | ✅ | Proper wait() for child processes |

### ⚠️ Limitations

- Redirection (`<`, `>`) uses `system()` call (not fully integrated)
- Supports single pipe (two commands) - not multiple pipes
- No background process support (`&`)
- No wildcard expansion (`*`, `?`)
- No environment variable expansion (`$VAR`)

## 🐛 Troubleshooting

### Compilation Errors

**Error: `readline/readline.h: No such file or directory`**
```bash
# Solution: Install readline development package
sudo apt-get install libreadline-dev
```

**Error: `undefined reference to 'readline'`**
```bash
# Solution: Link readline library during compilation
gcc -o shell shell.c -lreadline
```

### Runtime Issues

**Command not found errors:**
- Ensure the command exists in system PATH
- Check for typos in command names

**Permission denied:**
- Some commands may require proper file permissions
- Use `chmod` to adjust permissions if needed

**Pipe errors:**
- Ensure both commands in pipe are valid
- Check that first command produces output

## 📝 Code Notes

### Important Constants
- `StringSizeLimit`: 999 (maximum command length)
- `MaximumNoOfCommands`: 999 (maximum arguments)

### Variable Naming Convention
- Function parameters use descriptive names with prefixes (e.g., `Pstr1`, `Pstr1pipe`)
- Local variables use short names (e.g., `a`, `b`, `k`, `m`)

### Memory Management
- Readline library manages input buffer automatically
- History entries should be freed using `free_history_entry()`
- No explicit memory leaks in core shell loop

## 🎓 Educational Value

This project demonstrates:

1. **System Programming**: Direct interaction with OS system calls
2. **Process Management**: Fork, exec, wait operations
3. **Inter-Process Communication**: Pipe implementation
4. **Command Parsing**: String tokenization and parsing
5. **File Descriptors**: stdin/stdout redirection
6. **Library Integration**: Using external libraries (readline)

## 🔄 Extending the Shell

### Adding New Built-in Commands

1. Add command name to `arr[]` array in `UserDefinedCommandsExecution()`
2. Increment `NumberOfCmds` counter
3. Add new case in `switch` statement
4. Implement command logic

Example:
```c
arr[5] = "mycommand";
case 6:
    // Your command implementation
    return 1;
```

### Adding Multiple Pipe Support

Modify `pFunction()` to handle multiple pipe separators and create corresponding processes.

### Adding Background Process Support

Modify `Sys_CMD_Execution()` to detect `&` and avoid `wait()` for background processes.

## 📚 References

- **GNU Readline Library**: Command-line editing and history
- **POSIX System Calls**: fork, exec, wait, pipe
- **Unix Shell Programming**: Command parsing and execution

## 🤝 Contributing

This is an educational project. Suggestions for improvements:
- Multiple pipe support
- Better error messages
- Tab completion
- Environment variable expansion
- Signal handling (Ctrl+C, Ctrl+Z)

## 📄 License

This project is intended for educational purposes.

## 🙏 Acknowledgments

- GNU Readline Library developers
- Unix/Linux shell documentation
- Operating Systems course materials


## 📸 Screenshots

Screenshots of the shell in action are available in the `output attachments/` directory, demonstrating:
- Shell startup and welcome screen
- Built-in command execution
- Piping functionality
- Command history display
- Directory navigation

# 4) Uber and Lyft Price Prediction

A machine learning project that predicts ride prices for Uber and Lyft using various regression models, with an interactive GUI application for price comparison.

## 📋 Project Overview

This project analyzes ride-sharing data from Uber and Lyft to predict fare prices based on various factors such as distance, time, and ride type. The project includes data analysis, machine learning model training, and a user-friendly GUI application for comparing prices between different ride-sharing services.

## ✨ Features

- **Data Analysis**: Comprehensive exploratory data analysis (EDA) with visualizations
- **Price Prediction**: Multiple regression models (Linear and Polynomial) to predict ride prices
- **Time-based Analysis**: Analysis of price variations based on time of day, day of week, and other temporal features
- **Interactive GUI**: Tkinter-based application to compare Uber and Lyft prices for specific routes
- **Visualization**: Multiple plots and charts to visualize price patterns and model performance

## 🔧 Requirements

### Dependencies

```
pandas
numpy
matplotlib
seaborn
scikit-learn
tkinter
```

### Installation

1. Clone this repository or download the project files
2. Install the required dependencies:

```bash
pip install pandas numpy matplotlib seaborn scikit-learn
```

Note: `tkinter` is usually included with Python installations. If not available, install it separately for your operating system.

## 📁 Project Structure

```
SDAI Project/
│
├── Uber and lyft Price Prediction.ipynb    # Main Jupyter notebook with analysis and models
├── cab_rides.csv                           # Dataset file (ensure this is in the same directory)
├── Code_explanation.docx                   # Documentation
├── Project PPT.pdf                         # Project presentation
└── README.md                               # This file
```

## 📊 Dataset

The project uses `cab_rides.csv` which should contain the following columns:
- `distance`: Travel distance
- `cab_type`: Type of cab service (Uber/Lyft)
- `price`: Fare price
- `source`: Pickup location
- `destination`: Drop-off location
- `time_stamp`: Timestamp of the ride
- `name`: Vehicle/ride type name

**Note**: Ensure the `cab_rides.csv` file is placed in the same directory as the notebook before running the code.

## 🚀 Usage

### Running the Notebook

1. Open `Uber and lyft Price Prediction.ipynb` in Jupyter Notebook or JupyterLab
2. Ensure `cab_rides.csv` is in the same directory
3. Run the cells sequentially to:
   - Load and clean the data
   - Train machine learning models
   - Generate visualizations
   - Compare model performance

### Using the GUI Application

The notebook includes a GUI application that allows you to:
1. Select a source location from the dropdown menu
2. Select a destination location from the dropdown menu
3. Click "Submit" to compare Uber and Lyft prices for that route

The GUI will display:
- Average Lyft price
- Average Uber price
- Best price recommendation with vehicle type

## 🤖 Models Implemented

### 1. Linear Regression
- Predicts price based on distance and cab type
- Uses features: `distance`, `cab_type`

### 2. Polynomial Regression
- Uses polynomial features (degree=2) to capture non-linear relationships
- Provides potentially better accuracy for non-linear price patterns

### 3. Time-based Linear Regression
- Incorporates temporal features: `hour`, `day_of_week`, `distance`
- Accounts for price variations based on time

## 📈 Model Performance

The models are evaluated using:
- **RMSE (Root Mean Squared Error)**: Lower is better
- **R² Score**: Higher is better (closer to 1.0)

Run the notebook to see the specific performance metrics for your dataset.

## 📝 Notes

- The dataset is cleaned by removing missing values and duplicates
- Categorical variables are encoded (Lyft: 0, Uber: 1)
- Data is split into training (80%) and testing (20%) sets with a random state of 42
- All timestamps are converted to datetime format for temporal analysis

## 🎯 Use Cases

- Compare ride prices between Uber and Lyft
- Predict ride costs before booking
- Analyze pricing patterns based on distance and time
- Make informed decisions about ride-sharing services

## 📚 Future Enhancements

- Add more advanced models (Random Forest, Gradient Boosting, Neural Networks)
- Include weather data and traffic conditions
- Real-time price comparison API
- Mobile application version
- Surge pricing analysis


