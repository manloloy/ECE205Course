#include<iostream>
#include <fstream>
#include<SFML/Graphics.hpp>
#include <vector>

int main() {
    //read in data
    std::ifstream infile("data.txt");
    std::vector<sf::Vector2i> points;
    std::vector<sf::CircleShape> pointCircles;

    int x, y;
    while (infile >> x >> y) {
        points.emplace_back(x, y);
    }



    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    
    sf::CircleShape shape1(10.f);
    shape1.setFillColor(sf::Color::Blue);
    shape1.setOrigin(sf::Vector2f(-10, -10));

    //create circles at points
    for (const auto& pt : points) {
        //debug
        //std::cout << "x: " << pt.x << ", y: " << pt.y << '\n';
        sf::CircleShape shape(10.f);
        shape.setFillColor(sf::Color::Green);
        //shape.setOrigin(sf::Vector2f(pt.x, pt.y));
        shape.setPosition(pt);
        pointCircles.push_back(shape);
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        window.draw(shape);
        window.draw(shape1);
        window.display();
    }

    return 0;
}
