#pragma once
#include "AppMacros.h"
#include "Entity.h"

// Тоже что и Entity только регенерирует свои ХП и не колизится если у него нет! 
// TODO в теории армор не должен наследоваться от чего-то у чего есть оружие
// TODO реагирует на collide только если хп != 0
class Armor : public Entity{
public:
	// rotation degrees
	Armor(b2World *world, float degrees);

	// эти 3 функции перенести в entity! #importend
	// get наверное вообе  объект
	virtual float getWidth();
	virtual float getHeight();

	virtual void setRotation(float fRotation);
	virtual void setRotationX(float fRotationX);
    virtual void setRotationY(float fRotationY);

	virtual const cocos2d::CCSize& getContentSize();

protected:
	virtual void update( float dt);

private:
	cocos2d::CCSprite *sprite;

	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
	
	void Regen(float dt);
};
