# SFML Module: Simulating Scriptable Objects in C++

## Introduction

In game development, **Scriptable Objects** are often used in engines like Unity and Unreal to define data containers that are easy to modify and reuse without writing new code. For example, you might define an object type like "Enemy" or "Shape" that includes adjustable properties like speed, size, color, or behavior.

In this module, we simulate this concept using C++, SFML, and JSON files. The goal is to:

- Let students define "Shape Objects" in a `.json` file
- Load that data to construct and instantiate shapes (like circles or squares)
- See how these shapes behave based on their defined parameters
- Allow students to edit the data and reinstantiate objects with new values

We will use the [nlohmann/json](https://raw.githubusercontent.com/manloloy/ECE205Course/refs/heads/main/Files/json.hpp) header-only library for JSON parsing.

---

## File Structure

```
ScriptableObjectsSFML/
├── main.cpp
├── shape_factory.hpp
├── shape_factory.cpp
├── data/
│   └── shapes.json
├── include/
│   └── json.hpp
├── makefile
```

---

## Step 1: Sample `shapes.json` File

This file defines two shape templates: a circle and a square.

```json
[
  {
    "type": "circle",
    "radius": 40,
    "position": [100, 100],
    "velocity": [0.5, 0.3],
    "color": [255, 100, 100]
  },
  {
    "type": "square",
    "side": 60,
    "position": [200, 150],
    "velocity": [-0.4, 0.6],
    "color": [100, 255, 100]
  }
]
```

---

## Step 2: `shape_factory.hpp`

```cpp
#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

struct ScriptableShape {
    sf::Shape* shape;
    sf::Vector2f velocity;
};

std::vector<ScriptableShape> loadShapesFromFile(const std::string& filename);

#endif
```

---

## Step 3: `shape_factory.cpp`

```cpp
#include "shape_factory.hpp"
#include "include/json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

std::vector<ScriptableShape> loadShapesFromFile(const std::string& filename) {
    std::vector<ScriptableShape> shapes;

    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Could not open file: " << filename << "\n";
        return shapes;
    }

    json j;
    inFile >> j;

    for (const auto& entry : j) {
        std::string type = entry["type"];
        sf::Vector2f position(entry["position"][0], entry["position"][1]);
        sf::Vector2f velocity(entry["velocity"][0], entry["velocity"][1]);
        sf::Color color(entry["color"][0], entry["color"][1], entry["color"][2]);

        if (type == "circle") {
            float radius = entry["radius"];
            sf::CircleShape* circle = new sf::CircleShape(radius);
            circle->setFillColor(color);
            circle->setPosition(position);
            shapes.push_back({circle, velocity});
        }
        else if (type == "square") {
            float side = entry["side"];
            sf::RectangleShape* square = new sf::RectangleShape({side, side});
            square->setFillColor(color);
            square->setPosition(position);
            shapes.push_back({square, velocity});
        }
    }

    return shapes;
}
```

---

## Step 4: `main.cpp`

```cpp
#include <SFML/Graphics.hpp>
#include "shape_factory.hpp"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 400), "Scriptable Shapes");

    std::vector<ScriptableShape> shapes = loadShapesFromFile("data/shapes.json");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update shape positions and bounce
        for (auto& s : shapes) {
            sf::Vector2f pos = s.shape->getPosition();
            sf::Vector2f size;

            if (auto* circle = dynamic_cast<sf::CircleShape*>(s.shape)) {
                size = {circle->getRadius() * 2, circle->getRadius() * 2};
            } else if (auto* square = dynamic_cast<sf::RectangleShape*>(s.shape)) {
                size = square->getSize();
            }

            if (pos.x < 0 || pos.x + size.x > 600) s.velocity.x *= -1;
            if (pos.y < 0 || pos.y + size.y > 400) s.velocity.y *= -1;

            s.shape->move(s.velocity);
        }

        window.clear(sf::Color::Black);
        for (auto& s : shapes)
            window.draw(*s.shape);
        window.display();
    }

    for (auto& s : shapes)
        delete s.shape;

    return 0;
}
```

---

## Step 5: Makefile

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp shape_factory.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = scriptable_shapes

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
```

---

## How to Run the Program

1. Make sure SFML is installed.
2. Place `json.hpp` from [nlohmann/json](https://raw.githubusercontent.com/manloloy/ECE205Course/refs/heads/main/Files/json.hpp) into the `include/` directory.
3. Run `make` in the terminal.
4. Run the program: `./scriptable_shapes`
5. Modify `shapes.json` and rerun to test different shape configurations.

---

## Notes

This module demonstrated a C++-based simulation of **Scriptable Objects**, showing how a data file (JSON) can be used to define objects' behavior and parameters outside of the codebase. This promotes **reusability**, **data-driven design**, and **modifiability** — all important goals in modern game architecture.

You can extend this example by adding sliders or text input to modify the values in real-time or to spawn objects during the game.
