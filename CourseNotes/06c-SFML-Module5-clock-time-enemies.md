# SFML Module 5: Managing Multiple Enemies and Time-Based Movement

In this module, we expand our game by:

- Managing multiple enemies
- Resetting enemies when they leave the screen
- Detecting collision between player and enemies
- Using `sf::Clock` and delta time to make the game run consistently across different computers

**Code Files:** [SFML-Module 5 - Managing Multiple Enemies & Time-Based Movement](../Files/SFML-Module5-Clock%2CTime%26Enemies)


---

## Why Time-Based Movement?

So far, our movement looked like this:

```cpp
sprite.move(0.5f, 0);  // move 0.5 pixels each frame
```

That means: the faster your computer draws frames, the faster the player/enemy moves. On a slower computer, movement appears slower.

This is not good! Games should feel the same no matter what computer you use.

To fix this, we use **time-based movement**: move an object based on how much *time* has passed since the last frame — not how many frames.

---

## Folder Structure

```bash
SFML_Project/
│
├── images/
│   ├── background.png
│   ├── player.png
│   └── enemy.png
│
├── main.cpp
├── config.hpp
├── bg.cpp / bg.hpp
├── player.cpp / player.hpp
├── enemy.cpp / enemy.hpp
├── button.cpp / button.hpp
├── makefile
```

---

## Updated Main Game Loop with sf::Clock

The `sf::Clock` tracks real time. Here's how it’s used:

```cpp
sf::Clock clock;

while (window.isOpen()) {
    float dt = clock.restart().asSeconds();

    player.update(dt);
    enemy.update(dt);
    ...
}
```

- `clock.restart()` gives the time since the last frame and resets the clock.
- `.asSeconds()` converts the result to a float in seconds.
- We multiply all movement by `dt`.

Now, if 0.016 seconds pass (roughly 60 frames per second), `speed * dt` = proper smooth movement. If your computer draws fewer frames, `dt` is larger — so movement still feels normal.

---

## Config Header

`config.hpp`

```cpp
#ifndef CONFIG_HPP
#define CONFIG_HPP

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;

#endif
```

---

## Background Class

(unchanged from previous module — scrolls slowly at a constant rate)

---

## Player Class

`player.hpp`

```cpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const std::string& imagePath);
    void update(float dt);  // now accepts delta time
    void draw(sf::RenderWindow& window);
    void reset();
    sf::FloatRect getBounds() const;

private:
    sf::Texture texture;
    sf::Sprite sprite;
    float speed;
};

#endif
```

`player.cpp`

```cpp
#include "player.hpp"

Player::Player(const std::string& imagePath) {
    texture.loadFromFile(imagePath);
    sprite.setTexture(texture);
    sprite.setPosition(0, 225);
    speed = 150.0f;  // pixels per second
}

void Player::update(float dt) {
    if (sprite.getPosition().x < 450)
        sprite.move(speed * dt, 0);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::reset() {
    sprite.setPosition(0, 225);
}

sf::FloatRect Player::getBounds() const {
    return sprite.getGlobalBounds();
}
```

---

## Enemy Class

`enemy.hpp`

```cpp
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(const std::string& imagePath);
    void reset(float x);
    void update(float dt);  // now accepts delta time
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::Texture texture;
    sf::Sprite sprite;
    float speed;
};

#endif
```

`enemy.cpp`

```cpp
#include "enemy.hpp"

Enemy::Enemy(const std::string& imagePath) {
    texture.loadFromFile(imagePath);
    sprite.setTexture(texture);
    reset(500);  // initial off-screen position
    speed = 100.0f;  // pixels per second
}

void Enemy::reset(float x) {
    sprite.setPosition(x, 225);
}

void Enemy::update(float dt) {
    sprite.move(-speed * dt, 0);
    if (sprite.getPosition().x < -50)
        reset(500);
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Enemy::getBounds() const {
    return sprite.getGlobalBounds();
}
```

---

## Main Program

`main.cpp`

```cpp
#include <SFML/Graphics.hpp>
#include <vector>
#include "config.hpp"
#include "bg.hpp"
#include "player.hpp"
#include "enemy.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Multiple Enemies");
    Background bg("images/background.png");
    Player player("images/player.png");

    std::vector<Enemy> enemies;
    for (int i = 0; i < 3; ++i) {
        Enemy enemy("images/enemy.png");
        enemy.reset(500 + i * 150);
        enemies.push_back(enemy);
    }

    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();  // delta time in seconds

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        bg.update();  // background scroll is constant — no dt needed here
        player.update(dt);
        for (auto& enemy : enemies)
            enemy.update(dt);

        for (const auto& enemy : enemies) {
            if (player.getBounds().intersects(enemy.getBounds())) {
                player.reset();
                break;
            }
        }

        window.clear();
        bg.draw(window);
        player.draw(window);
        for (auto& enemy : enemies)
            enemy.draw(window);
        window.display();
    }

    return 0;
}
```

---

## Makefile

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp player.cpp enemy.cpp bg.cpp button.cpp
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

## What You Should Try Next

- Add more enemies or spawn them randomly
- Vary their speed
- Add scoring: keep track of how many seconds you've survived
- Add a game-over screen or lives counter
