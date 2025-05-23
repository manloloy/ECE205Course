# SFML Module 2: Movement and File Separation

In this module, you’ll:

- Animate an object with **keyboard movement**
- Create a `Player` class
- Use **header and source files** to separate logic
- Compile with a cleaner `Makefile`

---

## File Structure

We'll be working with the following files:

```
.
├── main.cpp
├── Player.cpp
├── Player.h
├── Makefile
```

---

## Step 1: Player Class (Header)

Create `Player.h`:

```cpp
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player();

    void handleInput();
    void update();
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape shape;
    float velocityX;
};

#endif
```

---

## Step 2: Player Implementation

Create `Player.cpp`:

```cpp
#include "Player.h"

Player::Player() {
    shape.setSize(sf::Vector2f(50.f, 50.f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(0.f, 225.f);
    velocityX = 0.5f;
}

void Player::handleInput() {
    // Optional: add key input if you want manual control
}

void Player::update() {
    sf::Vector2f pos = shape.getPosition();
    if (pos.x < 450) {
        shape.move(velocityX, 0.f);
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
```

---

## Step 3: Main Application

Create `main.cpp`:

```cpp
#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Movement Example");

    Player player;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.handleInput();
        player.update();

        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}
```

---

## Step 4: Makefile

Create a `Makefile`:

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp Player.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
```

---

## Step 5: Compile and Run

In your terminal:

```bash
make
./game
```

You should see a green square smoothly moving across the screen from left to right.

---

## Key Concepts

- Movement is updated in the `update()` method every frame
- Files are separated into headers (`.h`) and implementation (`.cpp`)
- A `Makefile` helps compile all parts cleanly with a single command
- You can later extend the `Player` class with input, collision, animation, etc.

---
