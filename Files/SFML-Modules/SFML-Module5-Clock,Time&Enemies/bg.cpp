
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "bg.hpp"
BG::BG(){
    	texture1.loadFromFile("images/bg.jpg");
    	sprite1.setTexture(texture1);
	sprite2.setTexture(texture1);
	sprite1.scale(2,2);
	sprite2.scale(2,2);
	sprite2.setPosition(WSIZE,0);
}

void BG::draw(sf::RenderWindow & window){
	window.draw(sprite1);
	window.draw(sprite2);
}
void BG::move(){
	sprite1.move(-3,0);
	sprite2.move(-3,0);

	if(sprite1.getPosition().x<=-WSIZE)
		sprite1.setPosition(WSIZE,0);
	if(sprite2.getPosition().x<=-WSIZE)
		sprite2.setPosition(WSIZE,0);

}
