# SFML Module 4: Backgrounds and Collision Detection

- Display a scrolling background using `sf::Sprite`
- Move a `Player` sprite across the screen
- Add an `Enemy` sprite that moves in the opposite direction
- Detect collisions between the `Player` and the `Enemy`
- Organize your code using classes in `.cpp` and `.hpp` files
  
**Code Files:** [SFML-Module 4 - Backrounds & Collision Detection](../Files/SFML-Modules/SFML-Module4-Background&Collisions)

---

## Why Learn These Topics?

This module introduces sprite-based animation and collision logic—both of which are essential for building games. By modularizing your code into separate files, you learn to manage larger projects.

---

## Project Structure

Your folder should look like this:

```
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

Each `.cpp` file implements the behavior of a class, and each `.hpp` file defines its structure.

---

## 1. Constants: `config.hpp`

We define basic constants like screen width and height in a separate file:

```cpp
#ifndef CONFIG_HPP
#define CONFIG_HPP

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;

#endif
```

---

## 2. Background: `bg.hpp` and `bg.cpp`

### What does the background do?

The background scrolls to the left continuously. When one copy scrolls off-screen, it's moved to the end of the other, creating a loop.

### `bg.hpp`

```cpp
#ifndef BG_HPP
#define BG_HPP

#include <SFML/Graphics.hpp>

class Background {
public:
    Background(const std::string& imagePath);
    void update();
    void draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite1;
    sf::Sprite sprite2;
    float scrollSpeed;
};

#endif
```

### `bg.cpp`

```cpp
#include "bg.hpp"

Background::Background(const std::string& imagePath) {
    texture.loadFromFile(imagePath);
    sprite1.setTexture(texture);
    sprite2.setTexture(texture);
    sprite2.setPosition(sprite1.getGlobalBounds().width, 0);
    scrollSpeed = 0.5f;
}

void Background::update() {
    sprite1.move(-scrollSpeed, 0);
    sprite2.move(-scrollSpeed, 0);

    if (sprite1.getPosition().x + sprite1.getGlobalBounds().width < 0)
        sprite1.setPosition(sprite2.getPosition().x + sprite2.getGlobalBounds().width, 0);

    if (sprite2.getPosition().x + sprite2.getGlobalBounds().width < 0)
        sprite2.setPosition(sprite1.getPosition().x + sprite1.getGlobalBounds().width, 0);
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(sprite1);
    window.draw(sprite2);
}
```

---

## 3. Player: `player.hpp` and `player.cpp`

### What does the player do?

The player sprite slowly moves across the screen. If it collides with the enemy, it resets to the left side.

### `player.hpp`

```cpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const std::string& imagePath);
    void update();
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

### `player.cpp`

```cpp
#include "player.hpp"

Player::Player(const std::string& imagePath) {
    texture.loadFromFile(imagePath);
    sprite.setTexture(texture);
    sprite.setPosition(0, 225);
    speed = 0.5f;
}

void Player::update() {
    if (sprite.getPosition().x < 450)
        sprite.move(speed, 0);
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

## 4. Enemy: `enemy.hpp` and `enemy.cpp`

### What does the enemy do?

The enemy sprite moves from the right toward the player. If they collide, the player resets.

### `enemy.hpp`

```cpp
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(const std::string& imagePath, float startX);
    void update();
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::Texture texture;
    sf::Sprite sprite;
    float speed;
};

#endif
```

### `enemy.cpp`

```cpp
#include "enemy.hpp"

Enemy::Enemy(const std::string& imagePath, float startX) {
    texture.loadFromFile(imagePath);
    sprite.setTexture(texture);
    sprite.setPosition(startX, 225);
    speed = 0.2f;
}

void Enemy::update() {
    sprite.move(-speed, 0);
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Enemy::getBounds() const {
    return sprite.getGlobalBounds();
}
```

---

## 5. Main Program

This is the game loop where you bring everything together: background, player, enemy, and collision logic.

### `main.cpp`

```cpp
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "bg.hpp"
#include "player.hpp"
#include "enemy.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Collision Example");

    Background bg("images/background.png");
    Player player("images/player.png");
    Enemy enemy("images/enemy.png", 450);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        bg.update();
        player.update();
        enemy.update();

        if (player.getBounds().intersects(enemy.getBounds())) {
            player.reset();
        }

        window.clear();
        bg.draw(window);
        player.draw(window);
        enemy.draw(window);
        window.display();
    }

    return 0;
}
```

---

## 6. Makefile

A `Makefile` helps compile all source files efficiently.

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

To build:

```bash
make
./game
```

---

## Additional Learning Notes

- `getGlobalBounds()` returns the rectangular area of the sprite. You can use `intersects()` to check for collisions.
- The background scrolls because the `update()` method moves both sprites continuously. When one scrolls off-screen, it wraps around.
- All images must be placed inside the `images/` folder. Check that file names exactly match your code.
- To extend this, you can add arrays of enemies or buttons to restart the game.
