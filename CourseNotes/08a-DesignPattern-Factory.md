# C++ Module: Factory Method Design Pattern

This module introduces the **Factory Method** design pattern in C++. It is SFML-independent, but an optional SFML example is included at the end for demonstration.

---

## What Is the Factory Method Pattern?

The **Factory Method** pattern is a **creational design pattern** that provides an interface for creating objects in a superclass but allows subclasses to alter the type of objects that will be created.

Instead of calling `new` directly in your code, you define a method that returns a new instance of a class. Subclasses can override this method to change the type of objects returned.

---

## Why Use the Factory Method?

This pattern is helpful when:

- You want to encapsulate object creation.
- You want to return objects of different types based on some input.
- You want to follow **Open/Closed Principle** — your code is open to extension but closed to modification.

---

## Step-by-Step Example: Without and With Factory

We'll build a simple example using shapes: `Circle` and `Square`.

### Step 1: Shape Interface

Create `shape.hpp`:

```cpp
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>

class Shape {
public:
    virtual std::string getType() const = 0;
    virtual ~Shape() = default;
};

#endif
```

---

### Step 2: Concrete Shape Implementations

Create `circle.hpp`:

```cpp
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape {
public:
    std::string getType() const override {
        return "Circle";
    }
};

#endif
```

Create `square.hpp`:

```cpp
#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

class Square : public Shape {
public:
    std::string getType() const override {
        return "Square";
    }
};

#endif
```

---

### Step 3: Factory Class

Create `shape_factory.hpp`:

```cpp
#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP

#include "circle.hpp"
#include "square.hpp"
#include <memory>
#include <string>

class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type) {
        if (type == "circle") {
            return std::make_unique<Circle>();
        } else if (type == "square") {
            return std::make_unique<Square>();
        } else {
            return nullptr;
        }
    }
};

#endif
```

---

### Step 4: Main Program

Create `main.cpp`:

```cpp
#include <iostream>
#include "shape_factory.hpp"

int main() {
    auto shape1 = ShapeFactory::createShape("circle");
    auto shape2 = ShapeFactory::createShape("square");

    if (shape1) std::cout << "Created a " << shape1->getType() << std::endl;
    if (shape2) std::cout << "Created a " << shape2->getType() << std::endl;

    return 0;
}
```

---

## Makefile

```makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = main.cpp
HDR = shape.hpp circle.hpp square.hpp shape_factory.hpp
OBJ = $(SRC:.cpp=.o)
TARGET = factory_example

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
```

---

## SFML Example (Optional Demonstration)

This example uses the Factory Method pattern to create different colored `CircleShape` objects.

Single-file SFML example: `main.cpp`

```cpp
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>

// Factory method with enum instead of strings
enum class CircleType { Red, Green, Blue };

std::unique_ptr<sf::CircleShape> createCircle(CircleType type) {
    auto shape = std::make_unique<sf::CircleShape>(25.f);
    switch (type) {
        case CircleType::Red: shape->setFillColor(sf::Color::Red); break;
        case CircleType::Green: shape->setFillColor(sf::Color::Green); break;
        case CircleType::Blue: shape->setFillColor(sf::Color::Blue); break;
    }
    return shape;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 100), "Factory Method");

    std::vector<std::unique_ptr<sf::CircleShape>> circles;
    circles.push_back(createCircle(CircleType::Red));
    circles.push_back(createCircle(CircleType::Green));
    circles.push_back(createCircle(CircleType::Blue));

    // Position circles
    for (size_t i = 0; i < circles.size(); ++i)
        circles[i]->setPosition(50 + i * 80, 25);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        for (auto& c : circles)
            window.draw(*c);
        window.display();
    }

    return 0;
}
```

---

## NOTES


- The Factory Method lets you abstract away how objects are created.
- It is ideal when you have multiple subclasses and want to create them based on runtime input.
- You reduce direct coupling between classes.
- Useful for config loaders, object creators in games, asset factories, etc.
