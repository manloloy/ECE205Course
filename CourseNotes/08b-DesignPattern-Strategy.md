# C++ Module: Strategy Design Pattern

This module introduces the **Strategy Design Pattern** in C++. It is SFML-independent at first, with an optional visual example using SFML included at the end.

---

## What Is the Strategy Pattern?

The **Strategy Pattern** is a **behavioral design pattern** that allows you to define a family of algorithms, put each of them in a separate class, and make them interchangeable at runtime.

Instead of hardcoding a specific behavior, you design your class to **delegate the behavior** to a separate object (the strategy). This allows for flexible design and easy swapping of logic.

---

## Why Use the Strategy Pattern?

- To avoid long chains of `if/else` or `switch` statements.
- To allow selecting behavior dynamically at runtime.
- To follow the **Open/Closed Principle**: open to extension, closed to modification.
- To make testing and code organization easier.

---

## Example Use Case: Sorting Algorithms

You want to sort numbers using different strategies:
- Ascending
- Descending

Rather than embedding the logic into one class, you define them as strategies and plug them into a context.

---

## Step-by-Step Implementation

### Step 1: Define the Strategy Interface

Create `sort_strategy.hpp`:

```cpp
#ifndef SORT_STRATEGY_HPP
#define SORT_STRATEGY_HPP

#include <vector>

class SortStrategy {
public:
    virtual void sort(std::vector<int>& data) const = 0;
    virtual ~SortStrategy() = default;
};

#endif
```

---

### Step 2: Implement Concrete Strategies

Create `ascending_sort.hpp`:

```cpp
#ifndef ASCENDING_SORT_HPP
#define ASCENDING_SORT_HPP

#include "sort_strategy.hpp"
#include <algorithm>

class AscendingSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) const override {
        std::sort(data.begin(), data.end());
    }
};

#endif
```

Create `descending_sort.hpp`:

```cpp
#ifndef DESCENDING_SORT_HPP
#define DESCENDING_SORT_HPP

#include "sort_strategy.hpp"
#include <algorithm>

class DescendingSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) const override {
        std::sort(data.rbegin(), data.rend());
    }
};

#endif
```

---

### Step 3: Create a Context Class

Create `data_context.hpp`:

```cpp
#ifndef DATA_CONTEXT_HPP
#define DATA_CONTEXT_HPP

#include "sort_strategy.hpp"
#include <vector>
#include <memory>

class DataContext {
public:
    void setData(const std::vector<int>& d) {
        data = d;
    }

    void setStrategy(std::unique_ptr<SortStrategy> s) {
        strategy = std::move(s);
    }

    void sortData() {
        if (strategy)
            strategy->sort(data);
    }

    const std::vector<int>& getData() const {
        return data;
    }

private:
    std::vector<int> data;
    std::unique_ptr<SortStrategy> strategy;
};

#endif
```

---

### Step 4: Main Program

Create `main.cpp`:

```cpp
#include <iostream>
#include "data_context.hpp"
#include "ascending_sort.hpp"
#include "descending_sort.hpp"

int main() {
    DataContext context;
    context.setData({4, 1, 9, 3, 7});

    std::cout << "Sorting Ascending:\n";
    context.setStrategy(std::make_unique<AscendingSort>());
    context.sortData();
    for (int n : context.getData()) std::cout << n << ' ';
    std::cout << "\n";

    std::cout << "Sorting Descending:\n";
    context.setStrategy(std::make_unique<DescendingSort>());
    context.sortData();
    for (int n : context.getData()) std::cout << n << ' ';
    std::cout << "\n";

    return 0;
}
```

---

## Makefile

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = main.cpp
HDR = sort_strategy.hpp ascending_sort.hpp descending_sort.hpp data_context.hpp
OBJ = $(SRC:.cpp=.o)
TARGET = strategy_example

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
```

---

## SFML Example: Strategy Pattern for Movement

Let’s simulate movement strategies: walk, jump, and teleport. We'll define movement strategies and use a key press to switch between them.

Create `main.cpp` as a single file SFML example:

```cpp
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

// Strategy interface
class MoveStrategy {
public:
    virtual void move(sf::CircleShape& shape) const = 0;
    virtual ~MoveStrategy() = default;
};

// Concrete strategies
class WalkStrategy : public MoveStrategy {
public:
    void move(sf::CircleShape& shape) const override {
        shape.move(1.0f, 0.0f);
    }
};

class JumpStrategy : public MoveStrategy {
public:
    void move(sf::CircleShape& shape) const override {
        shape.move(0.0f, -30.0f);
    }
};

class TeleportStrategy : public MoveStrategy {
public:
    void move(sf::CircleShape& shape) const override {
        shape.setPosition(rand() % 400, rand() % 400);
    }
};

// Context
class Player {
public:
    Player() {
        shape.setRadius(20.f);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(100.f, 300.f);
        strategy = std::make_unique<WalkStrategy>();
    }

    void setStrategy(std::unique_ptr<MoveStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    void update() {
        if (strategy) strategy->move(shape);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

private:
    sf::CircleShape shape;
    std::unique_ptr<MoveStrategy> strategy;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Strategy Pattern");

    Player player;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Change strategy with key press
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W)
                    player.setStrategy(std::make_unique<WalkStrategy>());
                else if (event.key.code == sf::Keyboard::J)
                    player.setStrategy(std::make_unique<JumpStrategy>());
                else if (event.key.code == sf::Keyboard::T)
                    player.setStrategy(std::make_unique<TeleportStrategy>());
            }
        }

        player.update();

        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}
```

---

## Notes
- Strategy Pattern lets you swap behavior (algorithms) without changing the class that uses them.
- You learned how to:
  - Define a strategy interface
  - Implement multiple strategies
  - Inject them at runtime using a context
- It's useful for encapsulating changing behavior like movement, sorting, combat logic, etc.
