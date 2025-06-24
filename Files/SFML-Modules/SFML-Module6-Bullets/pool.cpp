
#include <SFML/Graphics.hpp>
#include "pool.hpp"	
#include <stdlib.h>
#include <time.h>

Pool::Pool(){
	srand(time(0));		
	clock.restart();
				
}
void Pool::SpawnEnemy(){
	Enemy *e;
	if(clock.getElapsedTime().asSeconds() >= 1){
		//get an inactive enemy
		for(int i = 0; i<20; i++){
			if(!ePool[i].isActive){
				e = &ePool[i];
				break;
			}
		}
		//place it in the correct correct position
		e->body.setPosition(WSIZE + 10, rand()%701 + 100);
		//activate it
		e->isActive = true;

		//reset time
		clock.restart();
	}
	
}
void Pool::Move(){
	for(int i = 0; i<20; i++){
		ePool[i].Move();	
	}
}
void Pool::Draw(sf::RenderWindow & window){
	for(int i = 0; i<20; i++){
		ePool[i].Draw(window);

	}
}

void Pool::CheckCollision(sf::RenderWindow & window){
	for(int i = 0; i<20; i++){
		ePool[i].CheckCollision(window);
	}

}


Enemy* Pool::GetPool(){
	return ePool; 
}
