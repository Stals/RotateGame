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
	Entity(b2World *world, EntityType type, int hp);
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
	virtual void setupHPLabel();
	void updateHPLabel();

	virtual void update( float dt);

	int hp;
private:

	Weapon* currentWeapon;

	EntityType type;

	cocos2d::CCLabelTTF* hpLabel;
};


