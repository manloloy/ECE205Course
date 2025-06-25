# C++ Module: Object Pooling Design Pattern

This module introduces the **Object Pooling** design pattern in C++. It is commonly used in games and performance-critical applications to avoid the overhead of creating and destroying many objects at runtime.

---

## What Is Object Pooling?

Object pooling is a technique where we **create many objects ahead of time** and **reuse them** instead of creating new ones during the program.

### Why Do This?
- Creating objects with `new` and deleting with `delete` is slow.
- If you create the same type of object over and over (like bullets or particles), object pooling is faster and more efficient.
- Memory is reused, so the program can avoid performance hiccups.

---

## Example: Pooling vs Regular Allocation

We will:
1. Create 200 objects the regular way (using `new` each time).
2. Create 200 objects once using an object pool and reuse them repeatedly.

Then we’ll repeat both of them many times to simulate a real workload.

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
        return nullptr; // all are active
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

### Step 3: Main Program with Fair Benchmark
```cpp
// main.cpp
#include <iostream>
#include <vector>
#include <chrono>
#include "particle.hpp"
#include "object_pool.hpp"

int main() {
    const int NUM = 200;
    const int REPEAT = 100;

    // Benchmark regular allocation
    auto start = std::chrono::high_resolution_clock::now();
    for (int t = 0; t < REPEAT; ++t) {
        std::vector<Particle*> regular;
        for (int i = 0; i < NUM; ++i)
            regular.push_back(new Particle());
        for (auto p : regular)
            delete p;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Regular allocation (" << REPEAT << "x" << NUM << "): "
              << std::chrono::duration<double>(end - start).count() << "s\n";

    // Benchmark object pool reuse
    ObjectPool pool(NUM);
    start = std::chrono::high_resolution_clock::now();
    for (int t = 0; t < REPEAT; ++t) {
        for (int i = 0; i < NUM; ++i)
            pool.acquire();
        pool.releaseAll();
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Pooled reuse (" << REPEAT << "x" << NUM << "): "
              << std::chrono::duration<double>(end - start).count() << "s\n";

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

## SFML Visual Example

The following SFML demo lets you compare visually what happens when you dynamically create objects versus when you use a pool of objects that you simply activate/deactivate.

main.cpp
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

Make sure `arial.ttf` is in the same folder. You can download a font file online for free.

```bash
g++ main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
```


---
