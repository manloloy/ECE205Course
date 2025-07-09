#include<SFML/Graphics.hpp>

int main() {
    
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::CircleShape shape(1.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(sf::Vector2f(-100.25, -100.25));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}