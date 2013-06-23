#pragma once
#include "AppMacros.h"
#include "GameObject.h"
#include "Weapon.h"

enum EntityType{
	PlayerType,
	EnemyType
	// NeutralType - �� ������ �� ����� �������?
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
	virtual void setWeapon(Weapon *weapon); // TODO if not null - destroy previous
	void shoot(cocos2d::CCPoint p); // �������� ������� ������� � ��������� �����
protected:
	virtual void resolveCollision(GameObject* other) = 0;
	virtual void setupBody() = 0;

private:
	int hp;
	Weapon* currentWeapon;

	EntityType type;
};


