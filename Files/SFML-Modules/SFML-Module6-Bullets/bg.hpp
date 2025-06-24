
#include <SFML/Graphics.hpp>
#include "config.hpp"

class BG{
	private:
		sf::Texture texture1;
		sf::Sprite sprite1, sprite2;
		
	
	public:
		BG();
		void move();
                void draw(sf::RenderWindow & window);
};

