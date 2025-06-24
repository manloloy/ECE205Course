#include <SFML/Graphics.hpp>
#include "config.hpp"

enum Dir{Left, Right, Up, Down, Stop};

class Player{
	private:
		int health = 100;
		enum Dir moveDir;
	public:
    		sf::RectangleShape body;
    		
		Player();
		void HandleEvent();
		void Move();
		void Draw(sf::RenderWindow &window);
		void Damage(int x,sf::RenderWindow &window);
};

