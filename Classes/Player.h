#pragma once
#include "AppMacros.h"
#include "Entity.h"

class Player: public Entity
{
public:
	Player(b2World *world);
	~Player();

	// � ���� ���� ����������� �����
	// ���� ���� � ������������ �� ��� ������� 
	// � ����� ���� 1 ��� � ���� �� ���������
private:
	cocos2d::CCSprite *playerSprite;

	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
};
