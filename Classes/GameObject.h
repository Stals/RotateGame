#pragma once
#include "AppMacros.h"

#include "../external/Box2D/Box2D.h"

#include "EntityType.h"

// ����� ������ � �������� ���� box2d body � ���-�� ��������� �� �������
class GameObject : public cocos2d::CCSprite{
public:
	GameObject(b2World *world, EntityType type);
	~GameObject();

	EntityType getType();

	//virtual bool init();

	// ���� ����� �������� contactListener ��� ���� �������� � ������� � ����� ���� userData - ������� �������� �������� GameObject ��� ��� �����������
	virtual void resolveCollision(GameObject* other) = 0;

protected:
	b2Body *body;
	b2World *world;

	// TODO ������ � ���� body 2d � ��������� ��� ��������� �� ���� ������� (������ ������ ����� ����� ��������� ��� �� worlCoords ���������)
	// ������ ��� ������ ����� convertToWorldSpace � ����� �� 32 ��� ������� �� ���.
	virtual void setupBody() = 0;

	// TODO ������ � ���������� ���������� ������ ������ ��� �������� �� ���� � ������ ����������� ����� ��� resolveCollision
	// �� � � ������������� �������������� ���� ���������� ������ ���������

	// ��������� ��������� ����� ������� ������ box2d ����
	// Note: ���� ����������� �� ������ �������� update ������������� ������
	virtual void update( float dt);

	EntityType type;
};