#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "pool.hpp"
class Bullet{
	private:

	public:
    		bool isActive;
		sf::RectangleShape body;
    		
		Bullet();
		void Move();
		void Draw(sf::RenderWindow &window);
		void CheckCollision(Pool & pool);
};

