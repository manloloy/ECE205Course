# Lab 05C: Collaborative SFML Playground

## Objective
Work in a team of 2-3 students to build a shared graphical application using GitHub. Students will practice the collaborative workflow of adding collaborators, branching, pulling, pushing, and resolving merge conflicts.
Working in git by yourself can be straightforward (once you practice the basics enough). When working in a team, there are a lot of issues. Use this lab to try out collaborating with some other students in your class. This lab should be used to give you an idea of how git can be used to collaborate and common issues that may occur when multiple people are working on a project at the same time.
A secondary goal is to realize that separation of tasks and files can allow for smoother collaboration with less issues.

## Requirements
- 1 GitHub repository per group.
- Every student must have at least **2 commits** and **1 merge** reflected in the history.
- The project must use **Inheritance** and separate files (`.hpp`, `.cpp`).
- A single `Makefile` must build the entire group project.

---

## The Project: The Modular Playground
Your team will build a shared SFML screen. Each student is responsible for adding a unique "Entity" that inherits from a common base class and behaves differently on screen.

### 1. Setup (Student A - The Lead)
1. Create a new private repository on GitHub named `Lab05C_Playground`.
2. Go to **Settings > Collaborators** and add your partner(s).
3. Create a local folder and initialize the repository.
4. Create `Entity.hpp` (Base Class):
   - `sf::Vector2f position`
   - `virtual void update(float dt) = 0;`
   - `virtual void draw(sf::RenderWindow& window) = 0;`
   - `virtual ~Entity() {}`
5. Create a `main.cpp` that maintains a `std::vector<Entity*>`.
6. **Commit and Push** to the `main` branch.

### 2. Contributing (Students B and C)
1. **Clone** the repository.
2. Create a new branch for your specific entity (e.g., `git checkout -b add-bouncing-box`).
3. Create a new class file (e.g., `BouncingBox.hpp` and `BouncingBox.cpp`) that inherits from `Entity`.
   - Student B: Implement an entity that bounces off the window edges.
   - Student C: Implement an entity that follows the mouse or pulses in size.
4. Modify `main.cpp` to include your header and `push_back` your new entity type into the shared vector.
5. **Commit and Push** your branch to GitHub.

### 3. Merging and Conflict Resolution
1. On GitHub, create a **Pull Request** to merge your branch into `main`.
2. Partners must review and **Merge** the Pull Requests.
3. If multiple students modify the `main.cpp` include list or the vector logic simultaneously, a **Merge Conflict** will occur.
   - Pull the latest changes: `git pull origin main`.
   - Resolve the conflict markers (`<<<<<<< HEAD`) in the code, save, and commit.

### 4. Build Automation
1. One student must create a `Makefile` that compiles all group members' `.cpp` files and links SFML.
2. Every student must `git pull` the final version to verify all entities appear on the same screen.

---

## Submission Checklist
- [ ] Show the TA the GitHub **Commit History** showing contributions from all members.
- [ ] Demonstrate the compiled program running with all team members' entities active simultaneously.
- [ ] Show the `Makefile` used to build the multi-file project.

---

## Common Commands Recap
| Action | Command |
| :--- | :--- |
| **Download repo** | `git clone <url>` |
| **Get latest changes** | `git pull origin main` |
| **Create branch** | `git checkout -b <branch_name>` |
| **Stage changes** | `git add .` |
| **Save locally** | `git commit -m "message"` |
| **Upload changes** | `git push origin <branch_name>` |
