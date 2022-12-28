#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

#include "Entity.h"

class Enemy : public Entity
{
	private:
		sf::Sprite graphics;
		sf::RectangleShape shape;
		
	public:
		Enemy(float);
		void SetPos(sf::Vector2f);
		void Move(float);
		void Draw(sf::RenderWindow&);
};

#endif
