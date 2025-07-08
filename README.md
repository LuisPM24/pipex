# pipex

> A Unix-like command piping project from 42 school, replicating the behavior of shell pipelines using `execve`, `fork`, `dup2`, and `pipe`.

## ✅ Description

`pipex` is a project that recreates shell piping behavior by executing two commands with input/output redirection through a pipe. It involves deep understanding of process creation and file descriptor management in Unix systems.

<br>

## ⚙️ Build

This will generate the executable `pipex`:
```bash
make
```

To execute this program you should use `./pipex` with the bash functions and the files you want to use, as in the example below:
```bash
./pipex infile cat cat outfile
```

This imitates the following command:
```bash
< infile cat | cat > outfile
```
<br>

## 📚 Learn more: DeepWiki

For an in-depth explanation of **file descriptor duplication**, **pipe management**, and the logic behind forking and executing commands with `execve`, check out the dedicated article:

[![Ask DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/LuisPM24/pipex)
