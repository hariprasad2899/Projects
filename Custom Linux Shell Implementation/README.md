# Custom Linux Shell Implementation

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

---


**Note**: This shell is a learning project and should not be used as a production shell. Always test commands in a safe environment.
