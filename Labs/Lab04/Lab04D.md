# Lab 04D: Design Pattern – SFML Strategy Movement

## Objective
Implement the **Strategy Pattern** to swap the movement logic of an SFML player object at runtime.

## Background
The Strategy pattern allows you to switch algorithms dynamically. In this lab, the "algorithms" are different movement patterns. Instead of using a giant `switch` statement inside the `Player` class, the `Player` delegates its movement to a `MovementStrategy` object.

## Task
1.  **Strategy Interface**: Create `IMovementStrategy` with a virtual `move` method.
2.  **Concrete Strategies**:
    *   **Horizontal**: Moves the shape back and forth on the X-axis.
    *   **Vertical**: Moves the shape back and forth on the Y-axis.
    *   **Circular**: Uses `sin` and `cos` to move the shape in a circle.
3.  **Player Class**: Holds a `std::unique_ptr<IMovementStrategy>`.
4.  **Interaction**: Pressing '1', '2', or '3' swaps the player's movement strategy.

## C++ Template

```cpp
#include <SFML/Graphics.hpp>
#include <memory>
#include <cmath>

class IMovementStrategy {
public:
    virtual void move(sf::Shape& shape, float time, float dt) = 0;
    virtual ~IMovementStrategy() {}
};

// TODO: Implement HorizontalStrategy
// TODO: Implement VerticalStrategy
// TODO: Implement CircularStrategy (Hint: x = cos(time), y = sin(time))

class Player {
    sf::CircleShape shape;
    std::unique_ptr<IMovementStrategy> strategy;
    float totalTime = 0;
public:
    Player() {
        shape.setRadius(20.f);
        shape.setFillColor(sf::Color::Blue);
        shape.setOrigin(20.f, 20.f);
    }
    void setStrategy(std::unique_ptr<IMovementStrategy> s) { strategy = std::move(s); }
    void update(float dt) {
        totalTime += dt;
        if (strategy) strategy->move(shape, totalTime, dt);
    }
    void draw(sf::RenderWindow& window) { window.draw(shape); }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Strategy Pattern");
    Player p;
    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) /* Set Horizontal */;
                if (event.key.code == sf::Keyboard::Num2) /* Set Vertical */;
                if (event.key.code == sf::Keyboard::Num3) /* Set Circular */;
            }
        }
        p.update(dt);
        window.clear();
        p.draw(window);
        window.display();
    }
    return 0;
}
