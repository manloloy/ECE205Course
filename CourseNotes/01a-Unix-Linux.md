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

### First Time Login: Password Change
The first time you log in, the system will require you to change your password immediately.

1. **Current password:** Enter the default password (**`ECE205_Start!`**).
2. **New password:** Type your own secure password.
3. **Retype new password:** Confirm your new password.
4. **Connection Closed:** Once the password is changed, the server will automatically close your session.
5. **Re-Login:** You must open a new Terminal or PuTTY session and log in using your **new password**.
---
### Connection Instructions
- **Video Guide:** [How to log in (MacOS & Windows)](https://drive.google.com/file/d/1S-SSow904T3TN9DGh_hGRiG4m-qkcx5b/view?usp=drive_link)  
  *Note: The video uses `uhunix.hawaii.edu`. Replace that address with **jipys.com**.*

#### MacOS / Linux
1. Open the **Terminal** Application.
2. Type: `ssh <uhusername>@jipys.com` (e.g., `ssh johndoe@jipys.com`)
3. Enter the default password: **`ECE205_Start!`**
   - **Note:** Your password will **not show** as you type for security reasons.

#### Windows
1. Download and run **PuTTY** here: [https://www.putty.org/](https://www.putty.org/).
2. In the **Host Name** field, type: `jipys.com`
3. Ensure the **Port** is set to `22`.
4. Click **Open**.
5. When prompted for `login as:`, type your **UH username**.
6. Enter the default password: **`ECE205_Start!`**
   - **Note:** Your password will **not show** as you type.

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
   - Open your .vimrc file by typeing ```vim ~/.vimrc```
   - make sure the file contains the following contents

     ```
     set backspace=indent,eol,start
     set nocompatible
     set number 
     ```

---
## Bash/VIM vide
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

