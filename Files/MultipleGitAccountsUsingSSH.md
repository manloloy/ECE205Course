# Managing Multiple GitHub Accounts Using SSH

## Overview

In this module, we extend your Git and GitHub knowledge by showing how to manage multiple GitHub accounts (e.g., personal and academic) on the same machine using SSH authentication. Students will learn how to securely configure Git to work with more than one identity, enabling seamless project collaboration and identity separation.

This workflow is essential for students or developers contributing to both personal and institutional GitHub repositories.

---

## Objectives

- Understand SSH authentication for Git.
- Create and configure multiple SSH keys for separate GitHub accounts.
- Use `~/.ssh/config` to alias multiple GitHub identities.
- Set up Git remotes to target specific accounts.
- Set local Git identity (`user.name`, `user.email`) per project.
- Practice pushing code to different GitHub accounts from the same system.

---

## Key Terminology

| Term            | Description |
|------------------|-------------|
| **SSH**          | A secure protocol used to authenticate and communicate with remote servers (like GitHub). |
| **Public Key**   | A shareable SSH key uploaded to GitHub to allow secure authentication. |
| **Private Key**  | A confidential SSH key stored locally and used to authenticate with GitHub. |
| **SSH Config File** | A file (`~/.ssh/config`) that defines host-specific SSH settings and aliases. |
| **Host Alias**   | A nickname for a Git server (like `github-personal`) used to distinguish accounts. |

---

## Prerequisites

- Git installed and basic Git commands understood.
- GitHub account created and accessible.
- SSH installed (default on Ubuntu/MacOS; install `openssh-client` if needed).

---

## Step-by-Step: Managing Two GitHub Accounts with SSH

### Account Setup Example

| Identity       | GitHub Username | SSH Key Name        | SSH Alias          |
|----------------|------------------|---------------------|--------------------|
| Academic       | `christobear`    | `~/.ssh/christobear`| `github-christobear` |
| Personal       | `manloloy`       | `~/.ssh/manloloy`   | `github-manloloy`    |

---

## Step 1: Generate SSH Keys for Each Account

```bash
ssh-keygen -t ed25519 -C "your_email@hawaii.edu" -f ~/.ssh/christobear
ssh-keygen -t ed25519 -C "you@personalmail.com" -f ~/.ssh/manloloy
```

Press enter for no passphrase when prompted, or use one for additional security.

---

## Step 2: Add Public Keys to GitHub

### For each account:
1. Log into the appropriate GitHub account.
2. Go to **Settings → SSH and GPG Keys → New SSH Key**.
3. Copy the contents of the public key:
```bash
cat ~/.ssh/christobear.pub
cat ~/.ssh/manloloy.pub
```
4. Paste the key and give it a name like "UH Laptop Key" or "Personal VM".

---

## Step 3: Create/Edit Your SSH Config File

Edit the file `~/.ssh/config` using `vi`, `nano`, or your preferred editor:

```bash
vi ~/.ssh/config
```

Add the following:

```ssh
Host github-christobear
    HostName github.com
    User git
    IdentityFile ~/.ssh/christobear

Host github-manloloy
    HostName github.com
    User git
    IdentityFile ~/.ssh/manloloy
```

This tells SSH which key to use for each account based on the alias.

---

## Step 4: Test Each SSH Alias

```bash
ssh -T git@github-christobear
ssh -T git@github-manloloy
```

Expected output:
- "Hi christobear! You've successfully authenticated..."
- "Hi manloloy! You've successfully authenticated..."

---

## Step 5: Create or Clone Repos Using the Correct Identity

When creating or cloning repos, use the SSH alias:

```bash
# Clone using personal account
git clone git@github-manloloy:manloloy/gitpractice.git

# Clone using academic account
git clone git@github-christobear:christobear/lab-submission.git
```

---

## Step 6: Add a Remote with the Right Identity

```bash
git remote add origin git@github-christobear:christobear/project1.git
```

To verify:
```bash
git remote -v
```

---

## Step 7: Set Local Git Identity per Project

For each project, set the correct name/email:

```bash
git config user.name "Your Academic Name"
git config user.email "your_email@hawaii.edu"
```

For personal repos:
```bash
git config user.name "Your Personal Name"
git config user.email "you@personalmail.com"
```

---

## Step 8: Commit and Push

```bash
git add .
git commit -m "Initial commit"
git push -u origin master
```

Git will automatically use the SSH key based on the remote alias (e.g., `github-christobear` or `github-manloloy`).

---

## Practice Exercise: Two-Account Workflow

1. Create one repo using your academic account.
2. Create another repo using your personal account.
3. Push a Hello World C++ file to each using the correct identity.
4. Check GitHub web interface to verify authorship.
5. Try pushing changes from a different machine with the same SSH keys.

---

## Optional: Removing Global Defaults

To avoid confusion, you can remove global name/email:

```bash
git config --global --unset user.name
git config --global --unset user.email
```

This ensures all projects explicitly declare their identity.

---

## Troubleshooting

| Issue | Solution |
|-------|----------|
| Auth fails | Make sure public key is added to GitHub. Test with `ssh -T`. |
| Wrong identity in commit | Check with `git config user.email`. Fix with `git config`. |
| Pushed to wrong account | Remove remote with `git remote remove origin` and re-add. |
| Push fails | Check branch name, SSH config, or permissions. |
| Wrong key used | Run with `GIT_SSH_COMMAND="ssh -v"` to debug. |

---

## Final Notes

Using SSH aliases to manage multiple GitHub identities is a powerful technique for students and professionals alike. This setup prevents credential conflicts, promotes clean commit histories, and improves security. Mastering this will help you operate professionally across personal, academic, and organizational projects.

**SSH Multi-Account Cheat Sheet**: [multi-account-cheatsheet.md](../Handouts/multi-account-cheatsheet.md)

```bash
# View current SSH connections
ssh -vT git@github-christobear
```

---
