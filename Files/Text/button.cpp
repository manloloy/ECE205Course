#include "button.hpp"

Button::Button(float x, float y, float width, float height, const std::string& label, std::size_t maxChars)
    : maxVisibleChars(maxChars), active(false)
{
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(x, y);

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font\n";
        std::exit(1);
    }

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 10, y + 10);

    fullText = label;
    updateViewableText();
}


void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow& window) const {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

bool Button::isClicked(sf::RenderWindow& window, const sf::Event& event) const {
    return isMouseOver(window) &&
           event.type == sf::Event::MouseButtonPressed &&
           event.mouseButton.button == sf::Mouse::Left;
}

void Button::setActive(bool state) {
    active = state;
    shape.setFillColor(active ? sf::Color::Red : sf::Color::Blue);  // Visual cue
}

bool Button::isActive() const {
    return active;
}

void Button::handleTextEvent(const sf::Event& event) {
    if (!active) return;
    char typed = static_cast<char>(event.text.unicode);
    if (std::isalnum(typed)) {
        fullText += typed;
        updateViewableText();
    }
}

void Button::handleKeyEvent(const sf::Event& event) {
    if (!active) return;
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace) {
        if (!fullText.isEmpty()) {
            fullText.erase(fullText.getSize() - 1, 1);
            updateViewableText();
        }
    }
}
void Button::updateViewableText() {
    sf::String viewable;

    if (fullText.getSize() <= maxVisibleChars) {
        viewable = fullText;
    } else {
        viewable = fullText.substring(fullText.getSize() - maxVisibleChars, maxVisibleChars);
    }

    text.setString(viewable);
}
