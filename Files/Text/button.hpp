#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class Button {
public:
    Button(float x, float y, float width, float height, const std::string& label, std::size_t maxChars = 8);

    void draw(sf::RenderWindow& window);
    bool isMouseOver(sf::RenderWindow& window) const;
    bool isClicked(sf::RenderWindow& window, const sf::Event& event) const;
    void handleTextEvent(const sf::Event& event);
    void handleKeyEvent(const sf::Event& event);
    void setActive(bool state);
    bool isActive() const;

private:
    sf::RectangleShape shape;
    sf::Font font;
    sf::Text text;
    sf::String fullText;
    std::size_t maxVisibleChars;
    bool active;

    void updateViewableText();
};


#endif
