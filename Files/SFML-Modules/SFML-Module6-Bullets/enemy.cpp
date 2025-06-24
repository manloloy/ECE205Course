#include "player.hpp"
#include<iostream>

Enemy::Enemy(){
	body.setSize(sf::Vector2f(PSIZE, PSIZE));
	body.setOrigin(PSIZE/2,PSIZE/2);
   	body.setPosition(-100,-100 );
    	body.setFillColor(sf::Color::Blue);
	isActive = false;
}

void Enemy::Move(){
	if(isActive){
		body.move(-4,0);
		if(body.getPosition().x<=-50)
			isActive = false;
	}	

}
void Enemy::Draw(sf::RenderWindow &window){
	if(isActive)
		window.draw(body);
	return;
}
void Enemy::CheckCollision(sf::RenderWindow &w){
	if(isActive)
		if(body.getGlobalBounds().intersects(Player::getInstance()->body.getGlobalBounds()))
		{
			std::cout<<"collison"<<std::endl;
			Player::getInstance()->Damage(100, w);
		}	

}

