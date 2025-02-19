# pipex

Pipex is a program that simulates bash pipes `|` between two files and a chain of simple commands.

## General Requirements  

- Must follow the [Norminette](https://github.com/42School/norminette) style guide.
- Allowed functions: open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid
- Projects should not have memory leaks or terminate unexpectedly.
- Must submit a Makefile with specified rules that compiles the program.

## Requirements

The first argument of the program is an inpput file, the last program is an output file, the middle arguments are shell commands to be chained.

```./pipex file1 cmd1 cmd2 ... cmdn file2```

Behaves like

```< file1 cmd1 | ... | cmdn > file2```

Or, 

```./pipex here_doc LIMITER cmd cmd1 file```

Behaves like

```cmd << LIMITER | cmd1 >> file```

Beware of managing file descriptors properly. A bad use of them could cause the program to not be able to process long command chains, hang forever or produce incorrect results.
