#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "player.hpp"
#include "button.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WSIZE, WSIZE), "APP");
    window.setFramerateLimit(60);

    
    Button b(48, 24, WSIZE-40, 20, sf::Color::Red), 
	b1(48, 24, 20, 20, sf::Color::Blue),
	b2(48, 24, 20, WSIZE-20, sf::Color::Green);






    Player p1;
 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
		
		b.CheckEvent(window);		
		b1.CheckEvent(window);
		b2.CheckEvent(window);
		p1.HandleEvent();	
		
		if (event.type == sf::Event::Closed)
                	window.close();
        }
	p1.Move();	

	// Every frame clear the screen
        window.clear();
	
	//Every frame Redraw what's rendered    
	//All drawables must be redrawn here	
	p1.Draw(window);
	window.draw(b.button);
	window.draw(b1.button);
	window.draw(b2.button);
	//Every frame, display render changes
        window.display();
    }

    return 0;
}
