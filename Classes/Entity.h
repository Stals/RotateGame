#pragma once

#pragma once
#include "AppMacros.h"
#include "GameObject.h"
#include "Weapon.h"

enum EntityType{
	Player,
	Enemy
	// Neutral - �� ������ �� ����� �������?
};

// �� ������� � ������� ���� HP
class Entity : public GameObject
{
public:
	Entity(EntityType type, int hp);
	int getHP();

	// speed ����� �������� ������� ��� �������� - ����� � ��� ��� ��� ��������� ����������� ���� �� ����� = 0
	// ����� �� ��� ���� ������ ����� ������������ ������ � ��������� �� MAX_SPEED
	// left ���������� � ����� ������� ������ ���������
	//
	void rotate(bool left, float speed);
	// ����� ��� ���� ����� ���������� ��������� ������ ����� ��������� ���
	float getAngle();


	// ���� ����� ��������� ������ ������ �� ����.
	// � �� ���� Weapon.shoot ����� ����� ����� ����� ��������� ������
	void setWeapon(Weapon *weapon); // TODO if not null - destroy previous
	void shoot(cocos2d::CCPoint p); // �������� ������� ������� � ��������� �����

private:
	int hp;
	Weapon* currentWeapon;
};


