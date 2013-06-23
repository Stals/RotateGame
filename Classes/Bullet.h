#pragma once
#include "AppMacros.h"
#include "GameObject.h"

// � ������ ��� ��� ������ ���� ������ � ������ - �������� ��� ����� ���� ������ ������������
class Bullet: public GameObject{
public:
	Bullet(b2World *world,EntityType type, int damage);
	~Bullet();
	int getDamage();

	// ��� ����� �����?
	// ��� ����� � ������?
	// ����� � ���� �������
	// ������ ���� ��� ���� ��� ������ � �� ����� ���� ������ �������� ��� ������� ���� ���� ��.

	//TODO - ��������� �� ������ ������ ���� � ���� ���� ��.
	// ���������� �� ����� ����� �������. ������ � ��� ���������� �� ��� ��� ��� ��������� ����
	//!!! �� ������� - ���� ������� ������ - � �� Entity, ��� ���� type != ������ ���� � � ���� �� 0 �� - ����� �������� � ����������.

protected:
	virtual void update( float dt);
	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
private:
	int damage;


};

// TODO ��� � ����� �������� bullet MoveTo ���� �� ����� ��������� ������ �������? ���� � ���� ��� ����� world coords �� �� ������, �� ����� ������������ ��� ��������� ��. ����.