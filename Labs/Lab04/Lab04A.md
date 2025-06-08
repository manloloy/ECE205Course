# Lab04A: GitHub & Version Control

## Objective

- Learn to use Git and GitHub for version control
- Practice creating, committing, pushing, pulling, and merging code
- Gain experience working with Personal Access Tokens (PATs) for GitHub authentication

## Background

Version control is an essential tool for software development and research computing. Git is a distributed version control system that allows you to track changes, collaborate with others, and maintain history. GitHub is a remote service that hosts Git repositories online. In this lab, you will initialize a local Git repository, connect it to GitHub, push changes, and pull updates.

As of 2021, GitHub no longer supports password authentication for Git operations over HTTPS. You must use a **Personal Access Token (PAT)** instead.

## Prerequisites

- Git must be installed on your system (`git --version`)
- A GitHub account created with your UH email address

## Part 1: GitHub Setup and Hello World Commit

### 1. Create a GitHub Account

If you do not already have one, go to:  
https://github.com  
Register with your **@hawaii.edu** email address.

### 2. Generate a Personal Access Token (PAT)

GitHub no longer accepts password-based login for pushing code.

#### Instructions:
- Go to: https://github.com/settings/tokens
- Click “**Generate new token (classic)**”
- Write a note for what the key will be used for. Something like `uhunixlab` or 'ece205uhunix'
- give it an expiration. These tokens generally expire for security reasons. You can pick no expiration but the access token will be valid until your remove it from your account.
- Click “**Generate token**”
- Copy and save your token in a secure place (you won’t be able to view it again). 

### 3. Create a New Repository on GitHub

- Navigate to https://github.com
- Click “New Repository”
- Name the repository: `Lab04`
- You can give it a description
- Make it private (public repos can be shared with others, you can also change this to public later if needed)
- Do not initialize with a README (you’ll add that yourself)

### 4. Local Setup and Initial Commit

```bash
mkdir Lab04
cd Lab04
git init
touch main.cpp
vi main.cpp
```

Write a basic Hello World program in `main.cpp`.

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
```

```bash
git add main.cpp
git commit -m "Initial hello world commit"
git branch -M main
git remote add origin https://github.com/<your-username>/Lab04.git
git push -u origin main
```

> When prompted:
> - **Username:** your GitHub username  
> - **Password:** paste your PAT (Personal Access Token)

If you check the repositiory that you created online you will see the main branch now has the main.cpp file there. 
You can now change files and periodically commit and merge them with the main branch to save your changes. Your changes are tracked so if your code breaks,
you can always revert to an older version and start again from their while still review your newer code for changes.

There is still one problem. Saving your token as text is really annoying.
In step 5, you will learn to save your git credentials so you can always interact with your repos.
For this course you can use the Permantly option below. Only do this for your personal VMs or your UH unix accounts. 
After the class is over, you can remove your keys from your github account to secure your accounts. 

### 5. Saving Git Credentials (Optional)

#### Temporarily (recommended on shared computers)

```bash
git config --global credential.helper cache
```

This will store credentials in memory for 15 minutes.

#### Permanently (not recommended on shared computers)

```bash
git config --global credential.helper store
```

This stores credentials in `~/.git-credentials`.

## Part 2: Pull, Modify, and Push Again
** First confirm that you have pushed your code successfully to github.** In this section we will 
delete the local code and pull from the repo, make changes, push, and merge them

### 1. Delete Local Folder (Simulate Fresh Clone)

```bash
cd ..
rm -rf Lab04
```

### 2. Clone from GitHub

```bash
git clone https://github.com/<your-username>/Lab04.git
cd Lab04
```

### 3. Add More Files + Makefile

Create the following files:
- `main.cpp`
- `helper.cpp`
- `helper.hpp`
- `Makefile`

#### Example content for each:

`main.cpp`:
```cpp
#include <iostream>
#include "helper.hpp"
using namespace std;

int main() {
    printMessage();
    return 0;
}
```

`helper.cpp`:
```cpp
#include <iostream>
using namespace std;

void printMessage() {
    cout << "More advanced Hello World!" << endl;
}
```

`helper.hpp`:
```cpp
#ifndef HELPER_HPP
#define HELPER_HPP

void printMessage();

#endif
```

`Makefile`:
```makefile
all: program

program: main.o helper.o
	g++ -o program main.o helper.o

main.o: main.cpp helper.hpp
	g++ -c main.cpp

helper.o: helper.cpp helper.hpp
	g++ -c helper.cpp

clean:
	rm -f *.o program
```

### 4. Build and Run

```bash
make
./program
```

### 5. Clean Build

```bash
make clean
```

This removes object files (`*.o`) and the compiled executable (`program`), allowing for a fresh rebuild.

### 6. Commit and Push Changes

```bash
git add .
git commit -m "Added helper files and Makefile"
git push
```

The ``` git add .``` automatically adds all new/changed files. After pushing, you should see all your code in the github repo.

## Submission

- [ ] Show your TA the repo on Github
- [ ] Show your TA the main branch changes you made. Click on the main branch to view the branch. There should be at least 2 commits.

---
