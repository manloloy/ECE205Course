# Lab 04B: Design Pattern – SFML Object Pooling

## Objective
Implement the **Object Pooling** design pattern in a graphical environment using SFML. This lab demonstrates how to manage a high volume of game entities (bullets) without the performance hit of constant allocation.

## Background
In many games, objects like projectiles are created and destroyed frequently. In SFML, creating a new `sf::CircleShape` and its associated logic every time the user clicks can lead to frame drops. An **Object Pool** initializes a fixed number of bullets at the start. When the player "shoots," we simply activate an existing bullet from the pool. When the bullet leaves the screen, we deactivate it so it can be reused.

## Task
1.  **Bullet Class**: Create a class containing an `sf::CircleShape`, an `active` boolean, and a `velocity`.
2.  **BulletPool Class**: Maintain a `std::vector<Bullet>` of size 50.
3.  **Fire Logic**: Implement `fire(sf::Vector2f startPos)` which finds the first `active == false` bullet and sets its position and state.
4.  **Recycling**: In the update loop, if a bullet's `x > 800`, set `active = false`.

## C++ Template

```cpp
#include <SFML/Graphics.hpp>
#include <vector>

class Bullet {
public:
    sf::CircleShape shape;
    bool active = false;
    float speed = 500.0f;

    Bullet() {
        shape.setRadius(5.f);
        shape.setFillColor(sf::Color::Yellow);
    }

    void update(float dt) {
        if (active) {
            shape.move(speed * dt, 0);
            if (shape.getPosition().x > 800) active = false;
        }
    }
};

class BulletPool {
private:
    std::vector<Bullet> pool;
public:
    BulletPool(int size) { pool.resize(size); }

    void spawn(sf::Vector2f pos) {
        // TODO: Find an inactive bullet and "fire" it
    }

    void update(float dt) {
        for (auto& b : pool) b.update(dt);
    }

    void draw(sf::RenderWindow& window) {
        for (const auto& b : pool) {
            if (b.active) window.draw(b.shape);
        }
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Object Pool Lab");
    BulletPool pool(50);
    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                pool.spawn(mousePos);
            }
        }

        pool.update(dt);
        window.clear();
        pool.draw(window);
        window.display();
    }
    return 0;
}
