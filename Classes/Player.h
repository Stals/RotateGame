#pragma once
#include "AppMacros.h"
#include "Entity.h"

class Player: public Entity
{
public:
	Player();

	// в него прям добавляется армор
	// пока тупо в конструкторе он сам одевает 
	// и армор пока 1 тип и тупо он создается
private:
	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
};
