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
mkdir lab4
cd lab4
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
3. Name it `lab4`.
4. **Do not** initialize with README or .gitignore.

### Add Remote

```bash
git remote add origin https://github.com/yourusername/lab4.git
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

We will use Git extensively in this course starting with **Lab04A**.

```bash
# Summary commands:
git init
git add .
git commit -m "Initial commit"
git remote add origin <URL>
git push -u origin main
```
