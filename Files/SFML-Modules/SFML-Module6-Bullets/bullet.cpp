
#include "bullet.hpp"
#include<iostream>
Bullet::Bullet(){
	body.setSize(sf::Vector2f(PSIZE/2, PSIZE/3));
	body.setOrigin(PSIZE/4,PSIZE/6);
   	body.setPosition(-100,-100 );
    	body.setFillColor(sf::Color::White);
	isActive = false;
}

void Bullet::Move(){
	if(isActive){
		body.move(9,0);
		if(body.getPosition().x>=WSIZE+50)
			isActive = false;
	}	

}
void Bullet::Draw(sf::RenderWindow &window){
	if(isActive)
		window.draw(body);
	return;
}
void Bullet::CheckCollision(Pool &pool){
	if(isActive){
		//loop throught the enemy pool
		for(int i = 0; i<20; i++){
			if((pool.GetPool())[i].isActive){
				if(body.getGlobalBounds().intersects((pool.GetPool())[i].body.getGlobalBounds()))
				{
				(pool.GetPool())[i].isActive=false;
				isActive = false;	
				}
			}	
		}
	}	

}

