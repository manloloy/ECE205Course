#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "player.hpp"
#include "button.hpp"
#include "bg.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WSIZE, WSIZE), "APP");
    window.setFramerateLimit(60);
	
    BG bg;    
    Button b(48, 24, WSIZE-40, 20, sf::Color::Red);
    Pool enemypool;
    Player* p1 = Player::getInstance();
	
 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
		
		b.CheckEvent(window);		
		p1->HandleEvent();	
		
		if (event.type == sf::Event::Closed)
                	window.close();
        }
	//All moveables
	p1->Move();
	enemypool.SpawnEnemy();
        enemypool.Move();
	//check enemy collisons with player
	enemypool.CheckCollision(window);
	
	//check bullet collisions with enemy
	p1->CheckCollision(enemypool);

	//move background
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
	p1->Draw(window);
	enemypool.Draw(window);
	//Every frame, display render changes
        window.display();
    }

    return 0;
}
