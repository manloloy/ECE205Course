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
    void ChangeText(char s);
    void BackspaceText();
    //string getText();

private:
    sf::RectangleShape shape;
    sf::Font font;
    sf::Text text;
};

#endif