#include "Enemy.h"

Enemy::Enemy(float hp) :
	Entity(hp)
{
	this->shape.setSize(sf::Vector2f(40, 100));
	this->shape.setOrigin(20, 50);
	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setOutlineThickness(-1.f);
}

void Enemy::SetPos(sf::Vector2f position){
	this->shape.setPosition(position.x, position.y);
}

void Enemy::Move(float speed){
	this->shape.scale(1 + speed, 1 + speed);
}

void Enemy::Draw(sf::RenderWindow& window){
	window.draw(shape);
}
