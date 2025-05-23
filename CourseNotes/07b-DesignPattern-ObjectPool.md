# C++ Module: Object Pooling Design Pattern

This module introduces the **Object Pooling** design pattern in C++. It's commonly used in performance-critical software, such as games, to avoid expensive object instantiation at runtime.

## What is Object Pooling?

Object pooling is a technique where a fixed number of objects are created in advance and reused when needed, instead of creating and destroying them repeatedly. This is useful when:

- Creating objects is slow (e.g., loading textures, initializing graphics)
- You create and destroy the same kind of object often (like bullets)
- You want to minimize memory fragmentation or garbage collection overhead

## Why Is It Useful?

Imagine you're making a game where bullets are constantly created and destroyed. Each time you call `new Bullet()` and later `delete`, your game wastes time managing memory. Instead, you can create 200 bullets at the start and just "activate" or "deactivate" them during the game.

---

## Part 1: Object Pooling Without SFML

We'll build a simple benchmarking example showing the time it takes to:

1. Create 200 objects dynamically
2. Use 200 objects from a preallocated object pool

---

### Step 1: Particle Class

```cpp
// particle.hpp
#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle {
public:
    Particle() {
        // Simulate expensive work
        for (volatile int i = 0; i < 100000; ++i);
    }

    void activate() { active = true; }
    void deactivate() { active = false; }
    bool isActive() const { return active; }

private:
    bool active = false;
};

#endif
```

---

### Step 2: Object Pool Class

```cpp
// object_pool.hpp
#ifndef OBJECT_POOL_HPP
#define OBJECT_POOL_HPP

#include "particle.hpp"
#include <vector>

class ObjectPool {
public:
    ObjectPool(size_t size) {
        pool.reserve(size);
        for (size_t i = 0; i < size; ++i)
            pool.push_back(new Particle());
    }

    ~ObjectPool() {
        for (auto p : pool) delete p;
    }

    Particle* acquire() {
        for (auto p : pool) {
            if (!p->isActive()) {
                p->activate();
                return p;
            }
        }
        return nullptr;
    }

    void releaseAll() {
        for (auto p : pool)
            p->deactivate();
    }

private:
    std::vector<Particle*> pool;
};

#endif
```

---

### Step 3: Main Program

```cpp
// main.cpp
#include <iostream>
#include <vector>
#include <chrono>
#include "particle.hpp"
#include "object_pool.hpp"

int main() {
    const int NUM = 200;

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Particle*> regular;
    for (int i = 0; i < NUM; ++i)
        regular.push_back(new Particle());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Regular allocation: "
              << std::chrono::duration<double>(end - start).count()
              << "s\n";

    for (auto p : regular)
        delete p;

    ObjectPool pool(NUM);
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM; ++i)
        pool.acquire();
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Pooled allocation: "
              << std::chrono::duration<double>(end - start).count()
              << "s\n";

    return 0;
}
```

---

### Step 4: Makefile

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS =
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = object_pool_demo

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
```

---

## Part 2: SFML Object Pooling Demo

This SFML example compares dynamic allocation vs object pooling to draw 200 circles:

- Button 1: creates and destroys 200 red circles dynamically
- Button 2: activates/deactivates 200 green circles from a preloaded pool

---

### Full SFML Demo (Single File)

```cpp
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

struct Circle {
    sf::CircleShape shape;
    bool active = false;

    Circle() {
        shape.setRadius(5.f);
        shape.setFillColor(sf::Color::Green);
    }

    void activate(float x, float y) {
        shape.setPosition(x, y);
        active = true;
    }

    void deactivate() {
        active = false;
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Object Pooling Demo");

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text createText("Create", font, 18);
    createText.setPosition(50, 450);

    sf::Text poolText("Pool", font, 18);
    poolText.setPosition(150, 450);

    std::vector<sf::CircleShape> createdCircles;
    std::vector<Circle> pool(200);

    std::default_random_engine rng;
    std::uniform_real_distribution<float> distX(0, 480);
    std::uniform_real_distribution<float> distY(0, 480);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                auto mouse = sf::Mouse::getPosition(window);
                if (createText.getGlobalBounds().contains(mouse.x, mouse.y)) {
                    createdCircles.clear();
                    for (int i = 0; i < 200; ++i) {
                        sf::CircleShape c(5.f);
                        c.setFillColor(sf::Color::Red);
                        c.setPosition(distX(rng), distY(rng));
                        createdCircles.push_back(c);
                    }
                    for (auto& c : pool) c.deactivate();
                }

                if (poolText.getGlobalBounds().contains(mouse.x, mouse.y)) {
                    createdCircles.clear();
                    for (auto& c : pool)
                        c.activate(distX(rng), distY(rng));
                }
            }
        }

        window.clear();

        for (const auto& c : createdCircles)
            window.draw(c);

        for (const auto& c : pool)
            if (c.active)
                window.draw(c.shape);

        window.draw(createText);
        window.draw(poolText);
        window.display();
    }

    return 0;
}
```

Make sure `arial.ttf` is in the same folder.

---

## Notes

- Object pooling improves performance by **reusing** objects instead of frequently allocating and destroying them.
- It's useful in games, simulations, and real-time systems where objects like bullets, particles, or UI elements are reused frequently.
- We’ve demonstrated:
  - A basic object pool with benchmarking
  - A simple visual SFML app using pooled and dynamic objects
