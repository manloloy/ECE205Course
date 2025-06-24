#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "player.hpp"
class Enemy{
	private:
		int health = 100;
	public:
    		sf::RectangleShape body;
    		
		Enemy();
		void Move();
		void Draw(sf::RenderWindow &window);
		void CheckCollision(Player & p, sf::RenderWindow &w);
};

