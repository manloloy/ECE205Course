
#include <SFML/Graphics.hpp>

class Button{
	private:
	
	public:
		sf::RectangleShape button;		
		Button(int, int, int, int, sf::Color);
		void CheckEvent(sf::RenderWindow &window);
		void WasClicked(sf::RenderWindow &window);	

};
