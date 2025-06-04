# Introduction to Unix/Linux (Ubuntu) for C/C++ Programming

In this class, you will be working in a **Unix/Linux** environment. 

---

## What is Unix/Linux?

- Unix is the **Operating System** we’ll use for all programming and terminal work.
- Linux (like Ubuntu) is a Unix-like operating system—just like Windows and macOS, it manages files, hardware, and programs.
- In the early portion of this course, students will ssh into a unix system to program
- As early as possible students should start using working in **Ubuntu Desktop**, using a **VirtualBox VM**.

---
## UH Unix
- MacOS
   1. Open the **Terminal** Application.
   2. Type: ```ssh <uhusername>@uhunix.hawaii.edu```
   3. Enter your own UH Password
- Window
   1. Download Putty here: [https://www.putty.org/](https://www.putty.org/). Then run the application
   2. In host type uhunix.hawaii.edu
   3. Type your uhusername in the username section
   4. Make sure the port is 22
   5. Start the session.

---
## Setting Up Ubuntu Desktop in a Virtual Machine (Do this sometime in the first week. Ask your Instructor and TA for help)

You will download a pre-built **Ubuntu Virtual Machine**. This avoids VPN setup issues and ensures all students work in the same environment.

1. **Install VirtualBox**  
   [https://www.virtualbox.org/wiki/Downloads](https://www.virtualbox.org/wiki/Downloads)

2. **Download Ubuntu Desktop(Most recent is 24.04.02 LTS)**  
   [https://ubuntu.com/download/desktop](https://ubuntu.com/download/desktop)

3. **Open VirtualBox:**
   - Open VirtualBox
   - Create a new VM
   - CPU: allocate 2-4 cores minimum. If you can allocate more, I would recommend it.
   - RAM: 6gb if possible or 8+gb if you can
   - Disk Space: I would recommend a fixed disk at 15GB/20GB
   - This is a virtual machine, so the the ram and cpu will be freed when the VM is off.

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

