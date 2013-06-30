#pragma once
#include "AppMacros.h"
#include "Entity.h"

// Тоже что и Entity только регенерирует свои ХП и не колизится если у него нет! 
// TODO в теории армор не должен наследоваться от чего-то у чего есть оружие
// TODO реагирует на collide только если хп != 0
class Armor : public Entity{
public:
	Armor(b2World *world);

	// эти 3 функции перенести в entity! #importend
	// get наверное вообе  объект
	virtual float getWidth();
	virtual float getHeight();

	void rotate(float degrees);

private:
	cocos2d::CCSprite *sprite;

	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
	
	void Regen(float dt);
};
