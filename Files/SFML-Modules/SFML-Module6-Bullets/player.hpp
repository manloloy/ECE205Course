#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "bullet.hpp"
enum Dir{Left, Right, Up, Down, Stop};

class Player{
	private:
		static Player* instance;
		int health = 100;
		enum Dir moveDir;
		Bullet bullet[20];
		sf::Clock pclock;				
	public:
    		sf::RectangleShape body;
 		Player();
		~Player();	
		void HandleEvent();
		void Move();
		void Draw(sf::RenderWindow &window);
		void Damage(int x,sf::RenderWindow &window);
		void Attack();
		void CheckCollision(Pool &p);
		static Player* getInstance();

};

