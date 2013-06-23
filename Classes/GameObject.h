#pragma once
#include "AppMacros.h"

// ����� ������ � �������� ���� box2d body � ���-�� ��������� �� �������
class GameObject : public cocos2d::CCSprite{
public:
	GameObject(/*b2World *world*/);

	// ���� ����� �������� contactListener ��� ���� �������� � ������� � ����� ���� userData - ������� �������� �������� GameObject ��� ��� �����������
	virtual void resolveCollision(GameObject* other) = 0;

protected:
	// TODO ������ � ���� body 2d � ��������� ��� ��������� �� ���� ������� (������ ������ ����� ����� ��������� ��� �� worlCoords ���������)
	// ������ ��� ������ ����� convertToWorldSpace � ����� �� 32 ��� ������� �� ���.
	virtual void setupBody(){}

	// TODO ������ � ���������� ���������� ������ ������ ��� �������� �� ���� � ������ ����������� ����� ��� resolveCollision
	// �� � � ������������� �������������� ���� ���������� ������ ���������

	// ��������� ��������� ����� ������� ������ box2d ����
	// Note: ���� ����������� �� ������ �������� update ������������� ������
	virtual void update( float dt);
};