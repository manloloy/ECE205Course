# SFML Module 3: Buttons and Interaction

This module introduces interactive buttons using SFML. Buttons allow users to control your application using mouse input. In our example, clicking a button will reset the player to the starting position.

You’ll also learn how to:

- Organize code into multiple `.cpp` and `.hpp` files
- Use mouse input to detect clicks
- Display text on screen

**Code Files:** [SFML-Module3-Buttons.md](../Files/SFML-Modules/SFML-Module3-Buttons)

---

## Concepts Covered

- Drawing shapes and text to the screen
- Detecting if the mouse is hovering over a shape
- Handling mouse clicks (`sf::Mouse::isButtonPressed`)
- Structuring code using `.hpp` and `.cpp` files for modularity

---

## Step-by-Step: The `Button` Class

We’ll make a reusable `Button` class that handles:

- Drawing a colored rectangle and text
- Detecting when the mouse is over the button
- Detecting when the user clicks it

### `button.hpp`

This header file declares the structure of the `Button` class. Other files can include this to use the button interface.

```cpp
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(float x, float y, float width, float height, const std::string& label);

    void draw(sf::RenderWindow& window);
    bool isMouseOver(sf::RenderWindow& window) const;
    bool isClicked(sf::RenderWindow& window, sf::Event event) const;

private:
    sf::RectangleShape shape;
    sf::Font font;
    sf::Text text;
};

#endif
```

---

### `button.cpp`

This file defines how the `Button` works.

```cpp
#include "button.hpp"

Button::Button(float x, float y, float width, float height, const std::string& label) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(x, y);

    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 10, y + 10);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow& window) const {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

bool Button::isClicked(sf::RenderWindow& window, sf::Event event) const {
    return isMouseOver(window) &&
           event.type == sf::Event::MouseButtonPressed &&
           event.mouseButton.button == sf::Mouse::Left;
}
```

---

## Player Class Recap

The player is a green square that moves to the right until it reaches the end of the screen.

### `player.hpp`

```cpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void update();
    void draw(sf::RenderWindow& window);
    void reset();

private:
    sf::RectangleShape shape;
    float velocityX;
};

#endif
```

---

### `player.cpp`

```cpp
#include "player.hpp"

Player::Player() {
    shape.setSize(sf::Vector2f(50.f, 50.f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(0.f, 225.f);
    velocityX = 0.5f;
}

void Player::update() {
    if (shape.getPosition().x < 450) {
        shape.move(velocityX, 0.f);
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Player::reset() {
    shape.setPosition(0.f, 225.f);
}
```

---

## Config Header

The `config.hpp` header centralizes window constants.

```cpp
#ifndef CONFIG_HPP
#define CONFIG_HPP

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;

#endif
```

---

## Main Program

This file combines all components and handles the game loop.

### `main.cpp`

```cpp
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "button.hpp"
#include "config.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Button Example");

    Player player;
    Button resetBtn(180, 400, 140, 40, "Reset Player");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (resetBtn.isClicked(window, event)) {
                player.reset();
            }
        }

        player.update();

        window.clear();
        player.draw(window);
        resetBtn.draw(window);
        window.display();
    }

    return 0;
}
```

---

## Makefile

A Makefile simplifies compilation. Run `make` to compile.

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp player.cpp button.cpp
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

To build and run:

```bash
make
./game
```

---

## Additional Notes

- Ensure `arial.ttf` is in the project directory. If not, SFML won't be able to display button labels.
- The `Button` class can be reused anywhere you need clickable UI in SFML.
- You can easily extend this by creating more buttons or adding hover effects and different states.
