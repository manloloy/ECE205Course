# Lecture Module: SFML Motion and Object-Oriented Simulation

## Overview

In this module, we explore how to animate shapes in SFML using C++. We begin with a simple program to animate a square, then modify it to simulate bouncing motion. Finally, we wrap the logic in an object-oriented class, allowing for reusable and extensible motion behavior.

---

## Part 1: First SFML Test – A Square Moving Left to Right

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
        x += 0.07777777;  // adjust speed as needed
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

## Part 2: Circle Bouncing Horizontally (Left to Right and Back)

```cpp
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Horizontal Bounce");
    float radius = 25.f;
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Green);

    float x = 250;
    float speed = 0.3f;
    int direction = 1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        // Check boundaries
        if (x + radius >= 500 || x - radius <= 0)
            direction *= -1;

        x += speed * direction;
        circle.setPosition(x - radius, 225);

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
```

---

## Part 3: Circle Bouncing Vertically (Up and Down)

```cpp
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Vertical Bounce");
    float radius = 25.f;
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Blue);

    float y = 250;
    float speed = 0.25f;
    int direction = 1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        // Check boundaries
        if (y + radius >= 500 || y - radius <= 0)
            direction *= -1;

        y += speed * direction;
        circle.setPosition(225, y - radius);

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
```

---

## Part 4: Bouncing Ball Class with Randomized Motion and Direction

### Diagram: Ball Movement on Screen
```
+--------------------------------------------------+
|                                                  |
|       o     o         o                          |
|   o         |          \                         |
|      \     /            \      * Ball motion     |
|       \   /              o     changes direction |
|        \ /                     on edge contact   |
+--------------------------------------------------+
```

### Code:

```cpp
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

class Ball {
public:
    sf::CircleShape shape;
    sf::Vector2f direction;
    float speed;

    Ball(sf::Vector2u windowSize) {
        float radius = static_cast<float>(rand() % 20 + 10);
        shape.setRadius(radius);
        shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        shape.setOrigin(radius, radius);

        float x = static_cast<float>(rand() % (windowSize.x - static_cast<int>(2 * radius)) + radius);
        float y = static_cast<float>(rand() % (windowSize.y - static_cast<int>(2 * radius)) + radius);
        shape.setPosition(x, y);

        float angle = static_cast<float>(rand() % 360) * 3.1415926f / 180.0f;
        direction = sf::Vector2f(std::cos(angle), std::sin(angle));
        speed = static_cast<float>((rand() % 100 + 50) / 100.0);  // 0.5 to 1.5
    }

    void move(sf::Vector2u windowSize) {
        sf::Vector2f pos = shape.getPosition();
        float r = shape.getRadius();

        // Wall bounce logic
        if ((pos.x + r >= windowSize.x && direction.x > 0) || (pos.x - r <= 0 && direction.x < 0))
            direction.x *= -1;

        if ((pos.y + r >= windowSize.y && direction.y > 0) || (pos.y - r <= 0 && direction.y < 0))
            direction.y *= -1;

        shape.move(direction * speed);
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    sf::RenderWindow window(sf::VideoMode(500, 500), "Random Bouncing Balls");
    std::vector<Ball> balls;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed && balls.size() < 200)
                balls.emplace_back(window.getSize());
        }

        for (auto& ball : balls)
            ball.move(window.getSize());

        window.clear();
        for (auto& ball : balls)
            window.draw(ball.shape);
        window.display();
    }

    return 0;
}
```

---

## Learning Objectives

- Practice with real-time graphics rendering in SFML
- Animate motion using mathematical operations
- Detect collisions with window boundaries
- Encapsulate behavior using classes and random initialization
- Develop an interactive simulation using events (e.g., mouse input)

---

## Notes

- To compile, link with SFML libraries: `-lsfml-graphics -lsfml-window -lsfml-system`
- This lab builds toward understanding reusable game objects and introduces simulation ideas useful in game development and physics engines.
