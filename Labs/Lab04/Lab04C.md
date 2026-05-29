# Lab 04C: Design Pattern – SFML Enemy Factory

## Objective
Implement the **Factory Method** design pattern to dynamically generate different types of visual enemies in SFML.

## Background
A Factory encapsulates the complexity of object creation. Instead of the `main()` function needing to know how to set the colors, points, and sizes of "Ghosts" vs. "Goblins," it simply asks the `EnemyFactory` for a specific type. This makes adding new enemy types (like "Bosses" or "Minions") trivial.

## Task
1.  **Abstract Base**: Define `Enemy` with a virtual `draw` and `update` method.
2.  **Concrete Types**: 
    *   `Ghost`: Represented by a white `sf::CircleShape`.
    *   `Goblin`: Represented by a green `sf::RectangleShape`.
3.  **EnemyFactory**: Implement `static std::unique_ptr<Enemy> createEnemy(std::string type, sf::Vector2f pos)`.
4.  **Interaction**: Pressing '1' spawns a Ghost at the mouse position; '2' spawns a Goblin.

## C++ Template

```cpp
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Enemy {
public:
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual ~Enemy() {}
};

// TODO: Implement Ghost Class (CircleShape)
// TODO: Implement Goblin Class (RectangleShape)

class EnemyFactory {
public:
    static std::unique_ptr<Enemy> createEnemy(std::string type, sf::Vector2f pos) {
        // TODO: Factory Logic
        return nullptr;
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Enemy Factory");
    std::vector<std::unique_ptr<Enemy>> enemies;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            
            sf::Vector2f mPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) 
                    enemies.push_back(EnemyFactory::createEnemy("ghost", mPos));
                if (event.key.code == sf::Keyboard::Num2) 
                    enemies.push_back(EnemyFactory::createEnemy("goblin", mPos));
            }
        }

        window.clear();
        for (auto& e : enemies) {
            e->update(0.01f);
            e->draw(window);
        }
        window.display();
    }
    return 0;
}
