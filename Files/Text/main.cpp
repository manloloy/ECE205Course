#include <SFML/Graphics.hpp>
#include "button.hpp"
#include "config.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Button Example");

    Button resetBtn(180, 400, 140, 40, "Reset Player");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered) {
                char typed = static_cast<char>(event.text.unicode);
                if (std::isalnum(typed)){
                    resetBtn.ChangeText(typed);
                }
            }
            // if key pressed update text
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Backspace)){
                resetBtn.BackspaceText();
            }
        }



        window.clear();
        resetBtn.draw(window);
        window.display();
    }

    return 0;
}