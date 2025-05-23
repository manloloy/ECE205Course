# C++ Module: Singleton Design Pattern

This module introduces the **Singleton Design Pattern** in C++. It is an SFML-independent module, but an optional SFML example is included at the end to illustrate a common use case.

---

## What Is the Singleton Pattern?

The **Singleton** pattern ensures that a class has only one instance and provides a global point of access to that instance. It's used when exactly one object is needed to coordinate actions across the system.

Typical use cases:
- Global configuration managers
- Logging systems
- Resource managers
- Game state managers

---

## Why Use a Singleton?

Creating a Singleton avoids:
- Duplicate instances of a class when only one is needed
- Having to pass around a reference to the one global object
- Race conditions when using shared resources

---

## Step-by-Step: Simple Singleton (Thread-Unsafe)

Create a file named `singleton.hpp`:

```cpp
#ifndef SINGLETON_HPP
#define SINGLETON_HPP

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void doSomething();

private:
    Singleton() = default;
    ~Singleton() = default;

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

#endif
```

Create a file `singleton.cpp`:

```cpp
#include "singleton.hpp"
#include <iostream>

void Singleton::doSomething() {
    std::cout << "Singleton instance doing something.\n";
}
```

Main test: `main.cpp`

```cpp
#include "singleton.hpp"

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    s1.doSomething();

    if (&s1 == &s2) {
        std::cout << "s1 and s2 are the same instance.\n";
    } else {
        std::cout << "Error: Multiple instances exist.\n";
    }

    return 0;
}
```

---

## Thread Safety (C++11 and Onward)

This implementation is thread-safe **because** `static` local variables are initialized in a thread-safe manner in modern C++.

---

## Makefile

```makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = main.cpp singleton.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = singleton_example

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
```

---

## SFML Example (Optional)

This SFML example shows a singleton `GameStats` class that tracks and prints score.

Create a file `gamestats.hpp`:

```cpp
#ifndef GAMESTATS_HPP
#define GAMESTATS_HPP

class GameStats {
public:
    static GameStats& getInstance();

    void incrementScore();
    int getScore() const;

private:
    GameStats() : score(0) {}
    int score;

    GameStats(const GameStats&) = delete;
    GameStats& operator=(const GameStats&) = delete;
};

#endif
```

Create `gamestats.cpp`:

```cpp
#include "gamestats.hpp"

GameStats& GameStats::getInstance() {
    static GameStats instance;
    return instance;
}

void GameStats::incrementScore() {
    score++;
}

int GameStats::getScore() const {
    return score;
}
```

Create `main.cpp`:

```cpp
#include <SFML/Graphics.hpp>
#include "gamestats.hpp"
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 300), "Singleton SFML Example");
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(50, 100);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                GameStats::getInstance().incrementScore();
        }

        scoreText.setString("Score: " + std::to_string(GameStats::getInstance().getScore()));

        window.clear();
        window.draw(scoreText);
        window.display();
    }

    return 0;
}
```

Makefile for SFML version:

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp gamestats.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = sfml_singleton

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
```

Make sure `arial.ttf` is in the same directory.

---
