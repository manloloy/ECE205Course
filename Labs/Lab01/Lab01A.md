# Lab01A – Getting Started: Bash, `vi`, and Hello World in C and C++

Welcome to your first lab. In this lab, you will become familiar with basic Linux terminal commands, editing code using the `vi` text editor, and compiling and running your first C and C++ programs. These are essential skills that will support all future programming assignments in this course.

---

## Objectives

- Navigate the Linux file system using the terminal
- Create folders to organize lab work
- Use the `vi` text editor to create and edit files
- Compile and run C and C++ programs
- Verify your environment is correctly set up

---

## Instructions

### Step 1: Open the Terminal

The terminal provides access to the Unix shell. You can open the terminal from the application menu or by right-clicking on the desktop and selecting "Open Terminal."

---

### Step 2: Navigate to Your Home Directory

To ensure you're starting in your home folder, type:

```bash
cd ~
```

---

### Step 3: Create a Directory for All Labs

Organize your work by creating a dedicated folder for labs:

```bash
mkdir labs
cd labs
```

---

### Step 4: Create a Folder for This Lab

Each lab should be kept in a separate folder. Create one for Lab01:

```bash
mkdir Lab01
cd Lab01
```

---

### Step 5: Create and Edit a C File Using `vi`

To begin editing a C file:

```bash
vi hello.c
```

Inside `vi`, follow these steps:

- Press `i` to enter insert mode
- Type or paste the following code:

```c
#include <stdio.h>

int main() {
    printf("Hello, world!\n");
    return 0;
}
```

- Press `Esc` to leave insert mode
- Save and exit by typing:

```
:wq
```

---

### Step 6: Compile and Run the C Program

Use the following commands to compile and run the program:

```bash
gcc hello.c -o hello
./hello
```

Expected output:

```
Hello, world!
```

---

### Step 7: Create and Edit a C++ File Using `vi`

Repeat the process for a C++ version:

```bash
vi hello.cpp
```

Insert the following content:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
```

Save and exit with `:wq`.

---

### Step 8: Compile and Run the C++ Program

Use the following commands:

```bash
g++ hello.cpp -o hello_cpp
./hello_cpp
```

Expected output:

```
Hello, world!
```

---

## Final Step: Verify With Your TA

Show your TA that both programs compile and run correctly. This confirms that your development environment is correctly set up.

---






