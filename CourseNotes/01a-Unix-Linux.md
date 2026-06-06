# Introduction to Unix/Linux (Ubuntu) for C/C++ Programming

In this class, you will be working in a **Unix/Linux** environment. 

---

## What is Linux?

- Linux is the **Operating System** we’ll use for all programming and terminal work.
- Linux (like Ubuntu) is a Unix-like operating system—just like Windows and macOS, it manages files, hardware, and programs.
- In the early portion of this course, students will **SSH** into a remote server to program.
- As early as possible, students should start working in **Ubuntu Desktop** using a **VirtualBox VM** on their own machines.

---

## Accessing the Course Server

For the first portion of the course, we will use a dedicated lab server: **jipys.com**.

---
### Connection Instructions
- **Video Guide:** [How to log in (MacOS & Windows)](https://drive.google.com/file/d/1S-SSow904T3TN9DGh_hGRiG4m-qkcx5b/view?usp=drive_link)  
  *Note: The video uses `uhunix.hawaii.edu`. Replace that address with **jipys.com**.*

#### MacOS / Linux
1. Open the **Terminal** Application.
2. Type: `ssh <uhusername>@jipys.com` (e.g., `ssh johndoe@jipys.com`)
   If you get an error you can try `ssh -o PubkeyAuthentication=no <uhusername>@jipys.com`. Your computer may be trying to use an ssh key but you will use username and password in this course.
3. Enter the default password: **`ECE205_Start!`**
   - **Note:** Your password will **not show** as you type for security reasons.
4. Your connection will reset and you must login using your new password.
5. If this is your first time logging in to the server or your username was reset, then you will be prompted to change your password to your own custom password. Pick something secure that you can easily remember.
6. **Current Password** Type the default password again
7. **New password:** Type your own secure password.
8. **Retype new password:** Confirm your new password.
9. **Connection Closed:** Once the password is changed, the server will automatically close your session.
10. **Re-Login:** You must open a new Terminal or PuTTY session and log in using your **new password**.

#### Windows
1. Download and run **PuTTY** here: [Putty Download](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html).
2. In the **Host Name** field, type: `jipys.com`
3. Ensure the **Port** is set to `22`.
4. Click **Open**.
5. When prompted for `login as:`, type your **UH username**.
6. Enter the default password: **`ECE205_Start!`**
   - **Note:** Your password will **not show** as you type.
7. If this is your first time logging in to the server or your username was reset, then you will be prompted to change your password to your own custom password. Pick something secure that you can easily remember.
8. **Current password** Type the default password again
9. **New password:** Type your own secure password.
10. **Retype new password:** Confirm your new password.
11. **Connection Closed:** Once the password is changed, the server will automatically close your session.
12. **Re-Login:** You must open a new Terminal or PuTTY session and log in using your **new password**.

---
### Reset your own password
If you want to change your password at any time. Log in and use the command `passwd`

---
### Course Server Purpose 
This server is the primary environment used to introduce the basics of Linux, Bash, and Vim. During the first one or two weeks of the course, it provides a quick and reliable way to get started without needing to configure your own system.

Once your virtual machine (VM) is set up, you may choose to use it as your primary development environment for the remainder of the course. The shared server will remain available for practice, experimentation, and completing command-line exercises.

Keep in mind that SSH provides terminal access only. As a result, applications that require a graphical user interface (GUI) or graphics libraries cannot be run directly through a standard SSH session.

   
---
## Setting Up Ubuntu Desktop in a Virtual Machine (Do this sometime in the first week. Ask your Instructor and TA for help)
**Even if you can access the course server you need to still setup a virtual machine.** The virtual machine allows you to install
the sfml library which is used for some labs and your final project. **Optionally**: you may get C++ and SFML working on Windows and Mac
by following online guides or videos. **However, your instructor will not provide support for those alternative methods.**

To get your VM running, follow the instructions below:

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
   
4. **Starting your VM and Install necessary tools**
   - Start your vm and use the username and password you created. If you need additional help, ask your Instructor or TA.
   - Start the **Terminal** application and run the following command:

     ```sudo apt update && sudo apt install -y build-essential make manpages-dev libsfml-dev git```
   
   - These tools should be sufficient for the course for now.
6. **VIM SETTINGS**
   - your vim settings may be a bit weird when your first start using vim. If you notice weird things with the backspace and arrow keys come back to this section
     
     In your terminal run the following command:
```bash
cat >> ~/.vimrc << 'EOF'
set backspace=indent,eol,start
set nocompatible
set number
EOF
```
if you then run `cat ~/.vimrc` you should see your .vimrc file contains the following lines:
    
```bash
set backspace=indent,eol,start
set nocompatible
set number 
```

---
## Bash/VIM video
The video may use differnt servers or older versions of Ubuntu but the bash and vim content is still useful.
[Intro to Bash & VIM](https://drive.google.com/file/d/1n4sVdBegET4n0ZKzsyrBvtb8vUj7B2r2/view?usp=sharing)

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

**Bash Cheat Sheet** for the course: [Bash Cheat Sheet](../Handouts/BashCheatSheet.md)

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

**vim Cheat Sheet** for the course: [vim Cheat Sheet](../Handouts/viCheatSheet.md)

---

## Additional Resources


- **Bash Cheat Sheet** for the course: [Bash Cheat Sheet](../Handouts/BashCheatSheet.md)

- **vim Cheat Sheet** for the course: [vim Cheat Sheet](../Handouts/viCheatSheet.md)



## A Side Note On Bash (Not part of the course but programming and linux related)
### Introduction to Bash Scripting

**Note:** Bash programming is not the focus of this course. However, these examples demonstrate how to create shell scripts to automate tasks and run complex sequences of terminal commands locally on your system. 

Every Bash script should start with the "shebang" line: `#!/bin/bash`. This tells the operating system which interpreter to use to execute the script.

---

#### 1. Hello World Script
This is a basic script that outputs text to the terminal.

**Create a file named `hello.sh`:**
```bash
#!/bin/bash
echo "Hello, World!"
```

**Make the script executable:**
```bash
chmod +x hello.sh
```

**Run the script:**
```bash
./hello.sh
```

---

#### 2. Branching and Input
Bash scripts can handle logic and user input using a syntax similar to other programming languages.

**Create a file named `check_val.sh`:**
```bash
#!/bin/bash

echo "Enter a number:"
read num

if [ $num -gt 100 ]; then
    echo "That is a large number."
else
    echo "That is a small number."
fi
```

**Make the script executable:**
```bash
chmod +x check_val.sh
```

**Run the script:**
```bash
./check_val.sh
```

---

#### 3. Automating File Structures
One of the most powerful uses of Bash is automating repetitive directory and file creation. This script initializes a standard C++ project structure.

**Create a file named `setup_project.sh`:**
```bash
#!/bin/bash

echo "Enter your project name:"
read project

# Create the main directory
mkdir $project
cd $project

# Create subdirectories
mkdir src
mkdir include
mkdir build

# Create a sample source file
touch src/main.cpp
echo "#include <iostream>" >> src/main.cpp
echo "int main() { std::cout << \"Project $project initialized.\" << std::endl; return 0; }" >> src/main.cpp

# Create an empty Makefile
touch Makefile

echo "Structure for '$project' created:"
ls -R
```

**Make the script executable:**
```bash
chmod +x setup_project.sh
```

**Run the script:**
```bash
./setup_project.sh
```

