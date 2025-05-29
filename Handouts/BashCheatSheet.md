# Bash Cheat Sheet for Beginners

This module serves as a quick reference for commonly used Bash commands and operations. It's designed for beginners who are just starting with the Linux terminal environment.

---

## Navigating the File System

| Command               | Description                              |
|-----------------------|------------------------------------------|
| `pwd`                | Show current directory (Print Working Directory) |
| `ls`                 | List files in current directory           |
| `ls -l`              | List files with details                   |
| `ls -a`              | Show all files including hidden files     |
| `cd dirname`         | Change into a directory                   |
| `cd ..`              | Go up one directory level                 |
| `cd ~`               | Go to home directory                      |
| `cd -`               | Go to previous directory                  |

---

## Creating and Removing Files/Directories

| Command                   | Description                       |
|---------------------------|-----------------------------------|
| `touch filename`         | Create an empty file              |
| `mkdir dirname`          | Make a new directory              |
| `rm filename`            | Remove a file                     |
| `rm -r dirname`          | Remove a directory and contents   |
| `rmdir dirname`          | Remove an empty directory         |

---

## Viewing and Editing Files

| Command                  | Description                                  |
|--------------------------|----------------------------------------------|
| `cat filename`          | Display file contents                        |
| `less filename`         | View file contents with scroll capability    |
| `head filename`         | View the first 10 lines                      |
| `tail filename`         | View the last 10 lines                       |
| `vi filename`           | Edit a file using the vi editor              |
| `nano filename`         | Edit a file using nano (simpler editor)      |

---

## vi Basics

| Mode or Command         | Description                                 |
|--------------------------|---------------------------------------------|
| `i`                    | Enter insert mode                           |
| `Esc`                  | Exit insert mode                            |
| `:w`                   | Save file                                   |
| `:q`                   | Quit                                        |
| `:wq`                  | Save and quit                               |
| `:q!`                  | Quit without saving                         |
| `h`, `j`, `k`, `l`     | Move left, down, up, right in normal mode    |

---

## File Permissions

| Command                   | Description                        |
|---------------------------|------------------------------------|
| `chmod +x filename`      | Make a file executable              |
| `ls -l`                  | View permissions                    |
| `chmod 755 filename`     | Set specific permissions            |

---

## Compiling and Running C/C++ Code

| Command                         | Description                      |
|----------------------------------|----------------------------------|
| `gcc file.c -o program`         | Compile a C file                 |
| `./program`                     | Run the compiled C program       |
| `g++ file.cpp -o program`       | Compile a C++ file               |
| `./program`                     | Run the compiled C++ program     |

---

## Miscellaneous

| Command                   | Description                          |
|---------------------------|--------------------------------------|
| `clear`                 | Clear the terminal screen             |
| `history`               | Show command history                  |
| `man command`           | Show manual page for a command        |
| `echo "text"`           | Print text to the terminal            |
| `exit`                  | Close the terminal session            |

---

## Redirecting Input and Output

| Command                         | Description                          |
|----------------------------------|--------------------------------------|
| `command > file.txt`            | Redirect output to file (overwrite)  |
| `command >> file.txt`           | Append output to file                |
| `command < input.txt`           | Read input from file                 |
| `command1 | command2`           | Pipe output of one command to another |

---

## Useful Shortcuts

| Shortcut           | Description                                 |
|--------------------|---------------------------------------------|
| `Ctrl + C`        | Cancel running command                      |
| `Ctrl + D`        | Logout or end input                         |
| `Tab`             | Auto-complete filenames and directories     |
| `Up/Down Arrows`  | Navigate command history                    |

---

## Example Workflow

```bash
cd ~
mkdir labs
cd labs
mkdir Lab01
cd Lab01
vi hello.c
gcc hello.c -o hello
./hello
```

This creates directories, edits a file with `vi`, compiles it, and runs the program.

---

## Final Notes

- Practice navigating and editing with the terminal frequently.
- Use `man` to learn about any command (e.g., `man ls`).
- Don’t be afraid to experiment — most mistakes are harmless and fixable.

```bash
echo "You are ready to use the Bash shell!"
```
