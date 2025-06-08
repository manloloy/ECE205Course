# Module 09B: Git Cheat Sheet for Beginners

## Module Objective

This module provides a concise Git cheat sheet tailored for students learning version control for the first time. The commands listed here are essential for navigating Git during development and collaboration, including what is required for course Lab and Lecture modules (Lab04A, Lab03C, Lecture09A). Each command is accompanied by a clear explanation. This reference is designed to be printed or bookmarked and will help you build confidence with Git workflows.

---

## Table of Contents

- [Basic Git Configuration](#basic-git-configuration)
- [Repository Setup](#repository-setup)
- [Working with Files](#working-with-files)
- [Committing Changes](#committing-changes)
- [Branches and Merging](#branches-and-merging)
- [Working with Remotes](#working-with-remotes)
- [Common Troubleshooting](#common-troubleshooting)
- [Credential Management](#credential-management)

---

## Basic Git Configuration

```bash
git config --global user.name "Your Full Name"
git config --global user.email "your@email.hawaii.edu"
```

Sets your identity for commits.

```bash
git config --global core.editor "vi"
```

Sets your default text editor for Git. You can also use `nano` or `code`.

---

## Repository Setup

```bash
git init
```

Initializes a new Git repository in the current folder.

```bash
git clone <repo-url>
```

Copies a repository from GitHub to your local machine.

---

## Working with Files

```bash
git status
```

Shows the state of your working directory and staging area.

```bash
git add <file>
git add .
```

Stages one file or all files for the next commit.

```bash
git rm <file>
```

Removes a file from the staging area and your local folder.

```bash
git mv old_name new_name
```

Renames a file under version control.

---

## Committing Changes

```bash
git commit -m "Your commit message here"
```

Records changes to the repository. Messages should be short but descriptive.

```bash
git log
```

Shows the commit history for the current branch.

```bash
git diff
```

Displays changes between working directory and last commit.

---

## Branches and Merging

```bash
git branch
```

Lists all local branches.

```bash
git branch <branch-name>
```

Creates a new branch.

```bash
git checkout <branch-name>
```

Switches to the specified branch.

```bash
git merge <branch-name>
```

Merges changes from the given branch into the current one.

---

## Working with Remotes

```bash
git remote -v
```

Lists all configured remotes and their URLs.

```bash
git remote add origin <repo-url>
```

Adds a new remote named `origin`.

```bash
git push -u origin main
```

Pushes your local branch to GitHub. The `-u` flag sets `origin main` as default for future pushes.

```bash
git pull
```

Downloads and integrates changes from the remote repository.

---

## Common Troubleshooting

```bash
git remote remove origin
```

Removes a mistaken or broken remote.

```bash
git reset --hard
```

Resets all local changes. **Use with caution**.

```bash
git clean -fd
```

Deletes untracked files and directories.

```bash
git checkout -- <file>
```

Restores a file to the last committed version.

---

## Credential Management

GitHub no longer supports password authentication for HTTPS. You must use a Personal Access Token (PAT).

### Creating a Personal Access Token

1. Go to https://github.com/settings/tokens
2. Click **Generate new token (classic)**
3. Set a name and select `repo` scope
4. Click Generate and copy the token

### Using the Token

When you push for the first time, Git will ask for:

```
Username: your_github_username
Password: <paste your token here>
```

### Saving Credentials Temporarily or Permanently

Temporary (recommended on shared computers):

```bash
git config --global credential.helper cache
```

Stores credentials for 15 minutes.

Permanent (not recommended on shared computers):

```bash
git config --global credential.helper store
```

Stores credentials in plain text locally.

---

## Additional Notes

- Use `make clean` in makefiles to remove build artifacts (`.o` files, executables).
- Use `make all` or simply `make` to build default targets in your Makefile.
- Practice pulling and merging your own work before collaborating with others.

---

## Suggested Practice

After completing this module:

1. Clone a new repo from GitHub.
2. Write a small program (e.g., hello world).
3. Commit and push it.
4. Try creating a new branch, make a change, and merge it.
5. Test your ability to use `git pull` from another machine or directory.

```bash
# Example quick setup
mkdir lab4
cd lab4
git init
touch main.cpp
git add main.cpp
git commit -m "Initial commit"
git remote add origin https://github.com/<your-username>/lab4.git
git push -u origin main
```

---

End of Module 09B
