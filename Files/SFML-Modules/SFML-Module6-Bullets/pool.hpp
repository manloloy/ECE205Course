
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "enemy.hpp"

class Pool{
	private:
		Enemy ePool[20];
		sf::Clock clock;
	public:
		Pool();
		Enemy * GetPool();
		void SpawnEnemy();
		void Move();
		void Draw(sf::RenderWindow & window);
		void CheckCollision(sf::RenderWindow & window);
};


