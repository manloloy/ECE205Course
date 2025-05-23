# Introduction to Unix/Linux (Ubuntu) for C/C++ Programming

In this class, you will be working in a **Unix/Linux** environment, specifically using **Ubuntu Desktop** via a pre-built VirtualBox VM.

---

## What is Unix/Linux?

- Unix is the **Operating System** we’ll use for all programming and terminal work.
- Linux (like Ubuntu) is a Unix-like operating system—just like Windows and macOS, it manages files, hardware, and programs.
- This course assumes you are working in **Ubuntu Desktop**, provided as a downloadable **VirtualBox VM**.

---

## Setting Up Your Environment

You will download a pre-built **Ubuntu Virtual Machine**. This avoids VPN setup issues and ensures all students work in the same environment.

1. **Install VirtualBox**  
   https://www.virtualbox.org/wiki/Downloads

2. **Download Ubuntu VM Image**  
   *(Link will be provided by the instructor.)*

3. **Import the VM into VirtualBox:**
   - Open VirtualBox
   - Go to `File` → `Import Appliance`
   - Select the downloaded `.ova` file
   - Click through and start the VM

---

## Basic Bash Commands to Know

| Command | Description |
|--------|-------------|
| `pwd` | Print working directory |
| `cd` | Change directory |
| `mkdir` | Make a directory |
| `ls` | List contents of a directory |
| `touch file.txt` | Create an empty file or update timestamp |
| `rm file.txt` | Remove file |
| `mv file1 file2` | Move or rename a file |
| `cp file1 file2` | Copy a file |
| `man command` | View manual for a command (e.g., `man cp`) |
| `tab` | Auto-complete filenames or commands |
| `↑` | Access command history (press up key) |

---

## Using `vi` Text Editor

You will use `vi` (specifically, `vim`) to write and edit your C and C++ programs.

### First Time? Run `vimtutor`

Ubuntu includes a built-in tutorial for `vim`. To get started, open the terminal and type:


### Common `vi` Commands (in **command mode**):

| Command | Description |
|---------|-------------|
| `:w` | Save file |
| `:q!` | Quit without saving |
| `:wq` | Save and quit |
| `:wq!` | Force save and quit |

---

## Additional Resources


- **Unix Command Cheat Sheet**:  
  [link](Unix Cheat Sheet)

- **VIM Command Cheat Sheet**

