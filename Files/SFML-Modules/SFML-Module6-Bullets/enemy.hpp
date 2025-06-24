#include <SFML/Graphics.hpp>
#include "config.hpp"
class Enemy{
	private:
		int health = 100;
	public:
    		bool isActive;
		sf::RectangleShape body;
    		
		Enemy();
		void Move();
		void Draw(sf::RenderWindow &window);
		void CheckCollision(sf::RenderWindow &w);
};

