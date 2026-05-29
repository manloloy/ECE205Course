# Lab 05C: Collaborative SFML Playground

## Objective
Work in a team of 2-3 students to build a shared graphical application using GitHub. Students will practice the collaborative workflow of adding collaborators, branching, pulling, pushing, and resolving merge conflicts.
Working in git by yourself can be straightforward (once you practice the basics enough). When working in a team, there are a lot of issues. Use this lab to try out collaborating with some other students in your class. This lab should be used to give you an idea of how git can be used to collaborate and common issues that may occur when multiple people are working on a project at the same time.
A secondary goal is to realize that separation of tasks and files can allow for smoother collaboration with less issues.

Even if the work is not your portion, you should help or shadow your other team members to get an understanding from different member's points of view.

## Requirements
- 1 GitHub repository per group.
- Every student must have at least **2 commits** and **1 merge** reflected in the history.
- The project must use **Inheritance** and separate files (`.hpp`, `.cpp`).
- A single `Makefile` must build the entire group project.

---

## The Project: The Modular Playground
Your team will build a shared SFML screen. Each student is responsible for adding a unique "Entity" that inherits from a common base class and behaves differently on screen.
There are templates below the lab instructions that can be used to get each team member started.

### 1. Setup (Student A - The Lead)
1. Create a new private repository on GitHub named `Lab05C_Playground`.
2. Go to **Settings > Collaborators** and add your partner(s) git hub account(s).
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
# Collaborative SFML Playground (Starter Templates)

To assist with the collaborative workflow, use the following templates. Student A should initialize the repository with the Base Class and the Main skeleton. Students B and C should use the Derived Class templates as a starting point.

## 1. Entity.hpp (Base Class - Everyone Needs This)
```cpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity {
public:
    virtual ~Entity() {} // Required for polymorphic cleanup
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif
```

## 2. Student B Template (e.g., BouncingBox.hpp)
```cpp
#ifndef BOUNCINGBOX_HPP
#define BOUNCINGBOX_HPP

#include "Entity.hpp"

class BouncingBox : public Entity {
public:
    BouncingBox(sf::Vector2f pos, sf::Vector2f vel);
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
};

#endif
```

## 3. Student C Template (e.g., PulsingCircle.hpp)
```cpp
#ifndef PULSINGCIRCLE_HPP
#define PULSINGCIRCLE_HPP

#include "Entity.hpp"
#include <cmath>

class PulsingCircle : public Entity {
public:
    PulsingCircle(sf::Vector2f pos);
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::CircleShape shape;
    float totalTime;
};

#endif
```

## 4. main.cpp Skeleton (Student A Starts This)
```cpp
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.hpp"
// Students B and C will need to add their #includes here during their merge
// #include "BouncingBox.hpp"
// #include "PulsingCircle.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Collaborative Playground");
    sf::Clock clock;

    std::vector<Entity*> entities;

    // TODO: Each student adds their entity creation here
    // entities.push_back(new BouncingBox({100, 100}, {200, 200}));

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        // Update all
        for (auto e : entities) e->update(dt);

        window.clear();
        // Draw all
        for (auto e : entities) e->draw(window);
        window.display();
    }

    // Cleanup
    for (auto e : entities) delete e;

    return 0;
}
```

## 5. Makefile Template
```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Add your .cpp files here as you add them to the project
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = playground

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
```
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
