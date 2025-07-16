#include<iostream>
#include <fstream>
#include<SFML/Graphics.hpp>
#include <vector>

int main() {
    //read in data
    std::ifstream infile("data.txt");
    std::vector<sf::Vector2i> points;
    std::vector<sf::CircleShape> pointCircles;
    
    
    // read x and y data
    int x, y;
    
    while (infile >> x >> y) {
        points.emplace_back(x, y);
    }


    sf::VertexArray lines(sf::LineStrip, points.size());


    // draw window
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    //create circles at points
    for (const auto& pt : points) {
        //debug
        //std::cout << "x: " << pt.x << ", y: " << pt.y << '\n';
        sf::CircleShape shape(3.f);
        shape.setFillColor(sf::Color::Green);
        shape.setOrigin(sf::Vector2f(3.f, 3.f));
        shape.setPosition(sf::Vector2f(pt));
    }

    for (std::size_t i = 0; i < points.size(); ++i) {
        lines[i].position = sf::Vector2f(points[i]);
        lines[i].color = sf::Color::Green;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        window.draw(lines);
        for (const auto& pc : pointCircles) {
            window.draw(pc);
        }

        window.display();
    }

    return 0;
}
