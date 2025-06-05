# SFML Setup and First Test Project (Ubuntu + Terminal + vi)

This module walks you through installing and configuring SFML in your **VirtualBox Ubuntu Desktop** environment, writing and compiling a test program, and using a `Makefile`.

#### **NOTE: If you've already setup your machine using the first lecture, you can skip to the test in Step 4. If you have some missing packages that are needed, review the setup steps below to make sure you have everything you need installed.**
---

## Task 1: Install VirtualBox

Download and install the latest version of VirtualBox for your host operating system:

- [VirtualBox Downloads](https://www.virtualbox.org/wiki/Downloads)

---

## Task 2: Install Ubuntu Desktop (LTS)

1. Download the latest LTS release of **Ubuntu Desktop**:
   - [Ubuntu Desktop (LTS)](https://ubuntu.com/download/desktop)
2. In VirtualBox:
   - Create a new VM for Ubuntu 64-bit.
   - Allocate 2GB+ RAM and 20GB+ disk space.
   - Mount the downloaded `.iso` during creation.
3. Install Ubuntu inside the VM.
   - Create a username and password.
   - Use the default installation settings.

*Search online for “install Ubuntu in VirtualBox” if you need help.*

---

## Task 3: Install C++ Compiler

1. Open a terminal in your Ubuntu VM.
2. Run the following commands:

```bash
sudo apt-get update
sudo apt-get install build-essential manpages-dev
```

3. Test it:

```bash
vi hello.cpp
```

Paste:

```cpp
#include <iostream>
int main() {
    std::cout << "Hello, world!\n";
    return 0;
}
```

Compile and run:

```bash
g++ hello.cpp -o hello
./hello
```

---

## Task 4: Install SFML

1. Install SFML using the Ubuntu package manager:

```bash
sudo apt-get install libsfml-dev
```

2. Visit and bookmark the SFML site:
   - [SFML Official Website](https://www.sfml-dev.org/)

3. Test a sample from the official install page:

```cpp
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
```

Save as `test.cpp`, then compile:

```bash
g++ test.cpp -o test -lsfml-graphics -lsfml-window -lsfml-system
./test
```

---

## Task 5: First SFML Animation

### Goal:
Create a window (500x500) and animate a 50x50 square moving from the left to the right side.

### 1. Create the file:

```bash
vi firsttest.cpp
```

Paste the following:

```cpp
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "First SFML Test");
    sf::RectangleShape square(sf::Vector2f(50.f, 50.f));
    square.setFillColor(sf::Color::Red);
    float x = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        // Update position
        x += 0.5;  // adjust speed as needed
        if (x > 500) x = 0;
        square.setPosition(x, 225);

        window.clear();
        window.draw(square);
        window.display();
    }

    return 0;
}
```

---

### 2. Create a Makefile

```bash
vi Makefile
```

Paste this:

```makefile
firsttest: firsttest.cpp
	g++ firsttest.cpp -o firsttest -lsfml-graphics -lsfml-window -lsfml-system
```

---

### 3. Compile and Run

```bash
make
./firsttest
```

---

## Notes

- Use `vi` to edit files (`:wq` to save and exit).
- `make` compiles the program using the `Makefile`.
- The square should move smoothly from left to right.

---

## Troubleshooting

- If `#include <SFML/...>` doesn't work, ensure `libsfml-dev` is installed.
- Use `sudo apt-get install libsfml-dev` again if unsure.
- Confirm that VirtualBox Guest Additions is installed for smoother graphics.

---

Let me know when you're ready to build the next project or add audio, keyboard input, or game logic.
