#include "Entity.h"

Entity::Entity(float hp){
	this->maxHp = hp;
	this->curHp = this->maxHp;
}

void Entity::TakeDamage(float dmg){
	this->curHp -= dmg;
}

