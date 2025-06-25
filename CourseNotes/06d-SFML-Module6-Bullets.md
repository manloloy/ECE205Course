# SFML Module 6: Bullets and Object Pooling

In this module, you will add **shooting functionality** to your player using **bullets**. You will also learn about an important performance technique known as **object pooling**, which allows you to efficiently reuse bullets rather than creating and destroying them during gameplay.

**Code Files:** [SFML Module 6 - Bullets and Object Pooling](../Files/SFML-Modules/SFML-Module6-Bullets)

---

## Learning Objectives

By the end of this module, you should be able to:

- Create and fire bullet objects from the player
- Detect when bullets collide with enemies
- Use object pooling to reuse bullet objects
- Understand why memory management and performance are important in games

---

## Project Folder Structure

Ensure your files are organized as follows. Place all images in the `images/` folder.

```
SFML_Project/
├── images/
│   ├── background.png
│   ├── player.png
│   └── enemy.png
├── main.cpp
├── config.hpp
├── player.cpp / player.hpp
├── enemy.cpp / enemy.hpp
├── bullet.cpp / bullet.hpp
├── pool.cpp / pool.hpp
├── bg.cpp / bg.hpp
├── makefile
```

---

## Configuration File

`config.hpp`:

```cpp
#ifndef CONFIG_HPP
#define CONFIG_HPP

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;

#endif
```

---

## Bullet Class

Each bullet is a red circle that moves from left to right. When it goes off-screen or hits an enemy, it is deactivated (hidden).

`bullet.hpp`:

```cpp
#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet();
    void fire(sf::Vector2f position);
    void update();
    void draw(sf::RenderWindow& window);
    bool isActive() const;
    void deactivate();
    sf::FloatRect getBounds() const;

private:
    sf::CircleShape shape;
    float speed;
    bool active;
};

#endif
```

`bullet.cpp`:

```cpp
#include "bullet.hpp"
#include "config.hpp"

Bullet::Bullet() {
    shape.setRadius(5.f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(-100.f, -100.f);
    speed = 2.0f;
    active = false;
}

void Bullet::fire(sf::Vector2f position) {
    shape.setPosition(position);
    active = true;
}

void Bullet::update() {
    if (active) {
        shape.move(speed, 0);
        if (shape.getPosition().x > WINDOW_WIDTH)
            deactivate();
    }
}

void Bullet::draw(sf::RenderWindow& window) {
    if (active)
        window.draw(shape);
}

bool Bullet::isActive() const {
    return active;
}

void Bullet::deactivate() {
    active = false;
    shape.setPosition(-100.f, -100.f);
}

sf::FloatRect Bullet::getBounds() const {
    return shape.getGlobalBounds();
}
```

---

## Bullet Pool Class

Instead of constantly creating new bullet objects, we create a pool of bullets at the beginning of the program. We reuse bullets from the pool whenever the player shoots.

`pool.hpp`:

```cpp
#ifndef POOL_HPP
#define POOL_HPP

#include "bullet.hpp"
#include <vector>

class BulletPool {
public:
    BulletPool(size_t size = 20);
    void fire(sf::Vector2f position);
    void update();
    void draw(sf::RenderWindow& window);
    std::vector<Bullet>& getBullets();

private:
    std::vector<Bullet> bullets;
};

#endif
```

`pool.cpp`:

```cpp
#include "pool.hpp"

BulletPool::BulletPool(size_t size) {
    bullets.resize(size);
}

void BulletPool::fire(sf::Vector2f position) {
    for (auto& b : bullets) {
        if (!b.isActive()) {
            b.fire(position);
            break;
        }
    }
}

void BulletPool::update() {
    for (auto& b : bullets)
        b.update();
}

void BulletPool::draw(sf::RenderWindow& window) {
    for (auto& b : bullets)
        b.draw(window);
}

std::vector<Bullet>& BulletPool::getBullets() {
    return bullets;
}
```

---

## Main Application

The `main.cpp` file integrates everything: player, enemy, background, bullet pool, and collision detection.

`main.cpp`:

```cpp
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "enemy.hpp"
#include "bg.hpp"
#include "pool.hpp"
#include "config.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bullets and Pooling");

    Background bg("images/background.png");
    Player player("images/player.png");
    Enemy enemy("images/enemy.png", 400);
    BulletPool pool(30);
    sf::Clock fireClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireClock.getElapsedTime().asMilliseconds() > 250) {
            sf::Vector2f bulletOrigin = player.getPosition();
            bulletOrigin.x += 50;
            bulletOrigin.y += 25;
            pool.fire(bulletOrigin);
            fireClock.restart();
        }

        bg.update();
        player.update();
        enemy.update();
        pool.update();

        for (auto& bullet : pool.getBullets()) {
            if (bullet.isActive() && bullet.getBounds().intersects(enemy.getBounds())) {
                bullet.deactivate();
                enemy.reset();
            }
        }

        window.clear();
        bg.draw(window);
        player.draw(window);
        enemy.draw(window);
        pool.draw(window);
        window.display();
    }

    return 0;
}
```

---

## Makefile

`makefile`:

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp player.cpp enemy.cpp bg.cpp bullet.cpp pool.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
```

---

## What Is Object Pooling?

In many games, bullets or particles are created and destroyed very frequently. This constant memory allocation can slow down the game or cause crashes. Instead of creating new bullets every time, we create a fixed pool of bullets at the start and reuse them.

This technique is known as **object pooling**.

- Bullets start inactive and hidden
- When you press SPACE, a bullet is activated and repositioned
- When the bullet moves off-screen or hits something, it's deactivated and returned to the pool

---

## Notes

- This module introduced shooting with bullets.
- You learned how to use object pooling to manage bullets efficiently.
- Collision detection resets the enemy and reuses bullets from the pool.
- A clock ensures bullets cannot be fired too quickly.
- The system is modular and scalable.

This lays a strong foundation for more advanced features like particle effects or power-ups.
