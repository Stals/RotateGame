#pragma once
#include "AppMacros.h"
#include "Entity.h"

// ���� ��� � Entity ������ ������������ ���� �� � �� ��������� ���� � ���� ���! 
// TODO � ������ ����� �� ������ ������������� �� ����-�� � ���� ���� ������
// TODO ��������� �� collide ������ ���� �� != 0
class Armor : public Entity{
public:
	// rotation degrees
	Armor(b2World *world, float degrees);

	// ��� 3 ������� ��������� � entity! #importend
	// get �������� �����  ������
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
