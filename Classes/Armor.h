#pragma once
#include "AppMacros.h"
#include "Entity.h"

// ���� ��� � Entity ������ ������������ ���� �� � �� ��������� ���� � ���� ���! 
// TODO � ������ ����� �� ������ ������������� �� ����-�� � ���� ���� ������
// TODO ��������� �� collide ������ ���� �� != 0
class Armor : public Entity{
public:
	Armor(b2World *world);

	// ��� 3 ������� ��������� � entity! #importend
	// get �������� �����  ������
	virtual float getWidth();
	virtual float getHeight();

	void rotate(float degrees);

private:
	cocos2d::CCSprite *sprite;

	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
	
	void Regen(float dt);
};
