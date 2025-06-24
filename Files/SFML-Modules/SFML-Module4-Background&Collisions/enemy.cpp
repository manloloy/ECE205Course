
#include "enemy.hpp"
#include<iostream>
Enemy::Enemy(){
	body.setSize(sf::Vector2f(PSIZE, PSIZE));
	body.setOrigin(PSIZE/2,PSIZE/2);
   	body.setPosition(WSIZE*3/4, WSIZE/2);
    	body.setFillColor(sf::Color::Blue);
}

void Enemy::Move(){
}
void Enemy::Draw(sf::RenderWindow &window){
	window.draw(body);
	return;
}
void Enemy::CheckCollision(Player & p, sf::RenderWindow &w){
	if(body.getGlobalBounds().intersects(p.body.getGlobalBounds())){
		std::cout<<"collison"<<std::endl;
		p.Damage(100, w);
	}	

}

