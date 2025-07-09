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
void Button::ChangeText(char s){
    //shape.setFillColor(sf::Color::Green);
    std::string newstring = text.getString();
    newstring+=s;
    text.setString(newstring);
}
void Button::BackspaceText(){
    std::string newstring = text.getString();
    if(!newstring.empty()) newstring.pop_back();
    text.setString(newstring);
}