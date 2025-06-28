# Lecture Module 09A: Introduction to Git and GitHub

## Overview

In this module, we introduce Git as a version control system and GitHub as a platform for hosting code repositories. This is a foundational topic in modern software development and critical for collaboration in professional and academic environments.

Students will learn to initialize repositories, manage source code using Git commands, and interact with GitHub using remote repositories. We will also discuss basic workflows including pull/push/merge, resolving conflicts, and troubleshooting remotes.

---

## Objectives

- Understand the role of Git as a version control tool.
- Learn how to initialize and manage a local Git repository.
- Understand what GitHub is and how it relates to Git.
- Practice connecting a local repo to GitHub via HTTPS.
- Learn basic Git commands: `add`, `commit`, `push`, `pull`, `status`, `log`.
- Understand remotes, branches, and merging.
- Review collaboration scenarios and how to resolve merge issues.

---

## Key Terminology

| Term     | Description |
|----------|-------------|
| **Repository (Repo)** | A directory tracked by Git; stores history and versions. |
| **Local Repo** | The Git repository on your local machine. |
| **Remote Repo** | The version of your repository hosted on GitHub (or another service). |
| **Origin** | The default alias for your GitHub remote URL. |
| **Main** | The default branch of your repository. Previously called `master`. |
| **Branch** | A separate version of your code used for development or features. |
| **Commit** | A snapshot of your changes with a message explaining the update. |
| **Merge** | Combining changes from one branch into another. |

---

## GitHub: Why and How

GitHub is a platform that hosts remote repositories and enables sharing, collaboration, issue tracking, and project management.

- We will use GitHub in this course to manage your lab submissions and to help you practice best practices in source control.
- You must create a GitHub account using your **UH email** if you do not already have one.

---

## Setup Instructions

### Step 1: Create a GitHub Account

Go to [https://github.com/](https://github.com/) and sign up with your UH email address. This is free and will be required for future labs.

### Step 2: Install Git

Install Git on your system:
- Ubuntu: `sudo apt install git`
  ** This class uses an Uhunix or an Ubuntu Desktop VM** Just in case you want to also use git on your Mac or Windows computer, I include the extra information below.
- macOS: Use Homebrew: `brew install git`
- Windows: Download and install from [https://git-scm.com/downloads](https://git-scm.com/downloads)

### Step 3: Set Up Git on Your System

```bash
git config --global user.name "Your Name"
git config --global user.email "your_email@hawaii.edu"
```

---

## Git Workflow Example: Hello World Program

Create a new folder and file for testing Git.

```bash
mkdir gitpractice
cd gitpractice
touch hello.cpp
```

Edit `hello.cpp`:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, Git!" << endl;
    return 0;
}
```

### Initialize Git

```bash
git init
git add hello.cpp
git commit -m "Initial Hello World commit"
```

---

## Connecting to GitHub

### Create a Remote Repository

1. Log into GitHub.
2. Click **New Repository**.
3. Name it `gitpractice`.
4. **Do not** initialize with README or .gitignore.

### Add Remote
**make sure to replace yourusername with your git username**
```bash
git remote add origin https://github.com/yourusername/gitpractice.git
```

### Verify the Remote

```bash
git remote -v
```

If you mistyped the remote URL:

```bash
git remote remove origin
```

Then re-add it.

---

## Push Code to GitHub

### GitHub now requires a Personal Access Token (PAT)

GitHub no longer accepts passwords for HTTPS pushes. Follow these steps:

#### Step 1: Generate Token
- Go to: [https://github.com/settings/tokens](https://github.com/settings/tokens)
- Click **Generate new token (classic)**
- Select `repo` scope
- Save the token securely

#### Step 2: Push


```bash
git push -u origin main
# OR if you got an error about refspec not found try the command below.
git push -u origin master
```

Git will prompt:

```
Username: yourusername
Password: <paste your token>
```

#### Optional Credential Helpers

Avoid storing credentials permanently on shared systems.

```bash
git config --global credential.helper cache
```

---

## Common Git Commands

| Command | Description |
|---------|-------------|
| `git status` | Shows the current changes and staged files. |
| `git add <file>` | Adds a file to the staging area. |
| `git commit -m "message"` | Commits staged changes. |
| `git log` | Shows commit history. |
| `git push` | Uploads commits to remote repo. |
| `git pull` | Downloads updates from remote. |
| `git branch` | Lists branches. |
| `git checkout -b <branch>` | Creates and switches to a new branch. |
| `git merge <branch>` | Merges another branch into current branch. |

---



---

## Additional Practice: Working with Git on a Different Computer

Once you’ve successfully pushed your first project to GitHub, try the following steps on a **different computer**, lab machine, or virtual machine to practice cross-device collaboration and project continuity.

---

### Step 0: Set Up Git Identity (if not already configured)

If this is the first time you're using Git on this machine, run:

```bash
git config --global user.name "Your Name"
git config --global user.email "your_email@hawaii.edu"
```

**NOTE:** On this second computer, you may want to setup a different token and also setup the credential helper if you have not done so on the previous machine. You will find this convinient. If your machine ever gets compromised you can remove the key from your account.


---

### Step 1: Clone the Repository

Log in to GitHub and find your `gitpractice` repository. Copy the **HTTPS** URL.

Then on the second machine:

```bash
git clone https://github.com/yourusername/gitpractice.git
cd gitpractice
```

You now have a copy of your repository on this computer.

---

### Step 2: Modify and Push Changes

Make a small change to your `hello.cpp` file. For example, change the message:

```cpp
cout << "Hello again from a different machine!" << endl;
```

Then:

```bash
git add hello.cpp
git commit -m "Update from different computer"
git push
```

If prompted, paste your GitHub token again.

---

### Step 3: Check That the Push Was Successful

Return to the original computer or open GitHub in the browser and confirm the update appears in the repository's history and file view.

---

## Optional Challenge: Create a Branch and Merge It

### Step 1: Create and Switch to a New Branch

```bash
git checkout -b newfeature
```

Make changes (like adding a comment or new file), then:

```bash
git add .
git commit -m "Added new feature on branch"
git push -u origin newfeature
```

You now have a new branch hosted on GitHub.

---

### Step 2: Merge Branch Back into Main

Return to the `main` branch:

```bash
git checkout main
git pull
```

Merge the branch:

```bash
git merge newfeature
```

Then push the updated main branch:

```bash
git push
```

---

### Step 3: Delete the Merged Branch (Optional)

```bash
git branch -d newfeature        # Delete local branch
git push origin --delete newfeature  # Delete remote branch
```

---

**You’ve now practiced the full GitHub workflow across machines and learned how to use branches to manage features and changes.**


## Git for Collaboration

Teams can:
- Work on different branches.
- Merge code together using `git merge`.
- Resolve merge conflicts manually.

Best practice:
- Communicate changes.
- Pull before you push.
- Use pull requests on GitHub for reviewing changes.

---

## Troubleshooting

| Issue | Fix |
|-------|-----|
| Check origin | `git remote -v` and check to see you have correctly added your github account |
| Remote typo | `git remote remove origin` then re-add correctly |
| Push fails | Check token, internet, branch setup |
| Wrong branch | `git branch`, then `git checkout main` |
| Credential issues | Clear cache or re-authenticate |

---

## Final Notes

Git is essential for tracking progress, backing up your work, and collaborating with others. Mastering Git and GitHub early in your programming education will prepare you for both academic and industry success.

**git Cheat Sheet**: [git Cheat Sheet](../Handouts/gitCheatSheet.md)
