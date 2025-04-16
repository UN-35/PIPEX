# 🔄 Pipex - Unix Pipe Implementation

## Overview

This project implements a custom Unix pipe mechanism in C, allowing you to execute command pipelines similar to the shell's pipe operator (`|`). Pipex replicates the behavior of the shell command:

```bash
< file1 cmd1 | cmd2 > file2
```

through a program with the following syntax:

```bash
./pipex file1 cmd1 cmd2 file2
```

## 🌟 Features

- Execute external commands by parsing the PATH environment variable
- Redirect standard input/output to and from files
- Pipe command output from one process to another
- Proper error handling for invalid files, commands, and permissions
- No memory leaks

## 📋 Requirements

To compile and run this project, you need:
- A Unix-like operating system (Linux, macOS)
- GCC compiler
- Make

## 🛠️ Installation

1. Clone this repository:
```bash
git clone https://github.com/yourusername/pipex.git
```

2. Navigate to the repository:
```bash
cd pipex
```

3. Compile the project:
```bash
make
```

## 🚀 Usage

### Basic Usage

```bash
./pipex infile "cmd1" "cmd2" outfile
```

### Examples

1. Count the number of lines in the output of ls -l:
```bash
./pipex infile "ls -l" "wc -l" outfile
```
Equivalent to: `< infile ls -l | wc -l > outfile`

2. Count the number of words containing "a1" in infile:
```bash
./pipex infile "grep a1" "wc -w" outfile
```
Equivalent to: `< infile grep a1 | wc -w > outfile`

## 🔍 How It Works

### Architecture

The program works by:
1. Creating a pipe between two processes using the `pipe()` system call
2. Forking into two processes with `fork()`
3. In the child process:
   - Redirecting stdin from the input file
   - Redirecting stdout to the pipe
   - Executing the first command with `execve()`
4. In the parent process:
   - Redirecting stdin from the pipe
   - Redirecting stdout to the output file
   - Executing the second command with `execve()`

### Key Functions

- `child_p()`: Handles the first command execution (reads from infile, writes to pipe)
- `forking()`: Handles the second command execution (reads from pipe, writes to outfile)
- `cmd_path()`: Locates the full path of a command by parsing the PATH environment variable
- `_paths()`: Extracts and splits the PATH environment variable
- Error handling functions to provide meaningful error messages

### Files

- `main.c`: Contains the main execution flow
- `get_path.c`: Functions for finding command paths and error handling
- `ft_split.c`: String splitting function to parse commands and arguments
- `ft_strjoin.c`: String joining function for path construction
- `ft_strlen.c`: String length calculation
- `ft_strncmp.c`: String comparison function
- `ft_strrchr.c`: Find the last occurrence of a character in a string
- `header.h`: Function prototypes and includes

## 🔧 Makefile Commands

- `make`: Compile the project
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Recompile the project from scratch

## 🤔 What I Learned

Through this project, I gained a deeper understanding of:
- Unix processes and how they communicate
- Input/output redirection
- The fork-exec pattern
- Command execution and environment variable handling
- Error handling and memory management in C

## 📝 Notes

This project is part of the 1337 school curriculum, focusing on Unix mechanisms and process handling.

## 📜 License

This project is developed as part of the 1337 school curriculum.
