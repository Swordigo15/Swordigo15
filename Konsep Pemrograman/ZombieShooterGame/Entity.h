#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
	private:
		float curHp;
		float maxHp;
		
	public:
		Entity(float);
		void TakeDamage(float);
};

#endif

