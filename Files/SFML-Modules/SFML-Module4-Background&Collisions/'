#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "button.hpp"
#include "bg.hpp"
#include "enemy.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WSIZE, WSIZE), "APP");
    window.setFramerateLimit(60);
	
    BG bg;    
    Button b(48, 24, WSIZE-40, 20, sf::Color::Red);
    Enemy e1;
    Player p1;

 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
		
		b.CheckEvent(window);		
		p1.HandleEvent();	
		
		if (event.type == sf::Event::Closed)
                	window.close();
        }
	//All moveables
	p1.Move();
	e1.Move();
	e1.CheckCollision(p1,window);
	bg.move();	

	// Every frame clear the screen
        window.clear();
	
	//Every frame Redraw what's rendered    
	//All drawables must be redrawn here
	//Background should be drawn first
	bg.draw(window);        
	//Draw everything else in the middle
	
	window.draw(b.button);
	
        //Player should be the last to be drawn
	p1.Draw(window);
	e1.Draw(window);
	//Every frame, display render changes
        window.display();
    }

    return 0;
}
