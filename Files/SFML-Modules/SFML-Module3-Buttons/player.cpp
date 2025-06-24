#include "player.hpp"
Player::Player(){
	body.setSize(sf::Vector2f(PSIZE, PSIZE));
	body.setOrigin(PSIZE/2,PSIZE/2);
   	body.setPosition(WSIZE/2, WSIZE/2);
    	body.setFillColor(sf::Color::Green);
    	moveDir = Stop;	
}
void Player::HandleEvent(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	    // move left...
	    moveDir = Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
    	    // move right...
	    moveDir = Right;
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
    	    // move right...
	    moveDir = Up;
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
    	    // move right...
	    moveDir = Down;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
    	   	// left click...
		moveDir = Stop;					
	}

}
void Player::Move(){
	body.rotate(10);		
	switch(moveDir){
		case Left:
			if(body.getPosition().x < 0 + PSIZE/2){
				moveDir = Stop;
				break;
			}				

			body.move(-movespeed,0);
			break;
		case Right:
			if(body.getPosition().x > WSIZE - PSIZE/2){
				moveDir = Stop;
				break;
			}	 
			body.move(movespeed,0);
			break;
		case Up:
			if(body.getPosition().y < 0+PSIZE/2){
				moveDir = Stop;
				break;
			}	
			body.move(0,-movespeed);
			break;
		case Down:
			if(body.getPosition().y > WSIZE - PSIZE/2){
				moveDir = Stop;
				break;
			}	
			body.move(0,movespeed);
			break;
	}
	return;	
}
void Player::Draw(sf::RenderWindow &window){
	window.draw(body);
	return;
}
 

