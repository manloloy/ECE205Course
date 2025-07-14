#include <SFML/Graphics.hpp>
#include "button.hpp"
#include "config.hpp"
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Button Example");

    Button nameBtn(180, 300, 140, 40, "Name", 8);
    Button resetBtn(180, 400, 140, 40, "Reset Player", 10);


    std::vector<Button*> buttons = { &resetBtn, &nameBtn };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle mouse click: activate only the clicked button
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (auto* btn : buttons) {
                    btn->setActive(btn->isClicked(window, event));
                }
            }

            // Delegate text and key events to the active button
            for (auto* btn : buttons) {
                if (event.type == sf::Event::TextEntered)
                    btn->handleTextEvent(event);
                if (event.type == sf::Event::KeyPressed)
                    btn->handleKeyEvent(event);
            }
        }

        window.clear();
        for (auto* btn : buttons) {
            btn->draw(window);
        }
        window.display();
    }

    return 0;
}
