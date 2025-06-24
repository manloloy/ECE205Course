#include <SFML/Graphics.hpp>
#include"button.hpp"
#include<iostream>
Button::Button(int w, int h, int x, int y, sf::Color c){
   	button.setSize(sf::Vector2f(w, h)); 
    	button.setOrigin(w/2,y/2); 
    	button.setPosition(x, y); 
    	button.setFillColor(c); 
}
	
void Button::CheckEvent(sf::RenderWindow & window){
	sf::Vector2i mpos;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
    	   	// left click...i
		//check the position of the mouse
		mpos = sf::Mouse::getPosition(window);
		// if over button,  do something
		if(button.getGlobalBounds().contains(mpos.x, mpos.y)){
			WasClicked(window);
		}	
	}
		
}
	
	
void Button::WasClicked(sf::RenderWindow & window){
	std::cout<<"A button was clicked"<<std::endl;
	window.close();
}	



