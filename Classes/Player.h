#pragma once
#include "AppMacros.h"
#include "Entity.h"

class Player: public Entity
{
public:
	Player(b2World *world);
	~Player();

	// в него прям добавляется армор
	// пока тупо в конструкторе он сам одевает 
	// и армор пока 1 тип и тупо он создается
private:
	cocos2d::CCSprite *playerSprite;

	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
};
