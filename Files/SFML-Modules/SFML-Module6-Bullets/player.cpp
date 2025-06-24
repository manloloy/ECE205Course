#include "player.hpp"
Player* Player::instance = NULL;

Player::Player(){
	body.setSize(sf::Vector2f(PSIZE, PSIZE));
	body.setOrigin(PSIZE/2,PSIZE/2);
   	body.setPosition(WSIZE/2, WSIZE/2);
    	body.setFillColor(sf::Color::Green);
    	moveDir = Stop;
	pclock.restart();
}
Player* Player::getInstance(){
	if(!instance)
		instance = new Player();
	return instance;
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

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		Attack();
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

	//Also move player bullets if there are any active
	for(int i = 0; i<20; i++)
		bullet[i].Move();

	return;	
}
void Player::Draw(sf::RenderWindow &window){
	window.draw(body);
	
	//also draw bullets if there are any active
	for(int i = 0; i<20; i++)
	bullet[i].Draw(window);


	return;
}
 
void Player::Damage(int x, sf::RenderWindow &window){
	health -=x;
	if(health<=0)
		window.close();
}
void Player::Attack(){
	//The user can only attack a certain amount of times per second
	//use pclock to time when the attack is available
	if(pclock.getElapsedTime().asSeconds()<0.25)
		return;

	
	//find inactive bullet
	Bullet *b;
	for(int i=0; i<20; i++){
		if(!bullet[i].isActive){
			b = &bullet[i];
			break;
		}
	}
	//position bullet to player
	b->body.setPosition(body.getPosition().x, body.getPosition().y);
	//release bullet
	b->isActive=true;
	pclock.restart();
}
void Player::CheckCollision(Pool &pool){
	//Check if any attacks hit the enemies
	for(int i = 0; i<20;i++){
		bullet[i].CheckCollision(pool);
	}	
}
