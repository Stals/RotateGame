#pragma once
#include "AppMacros.h"
#include "Entity.h"
#include "Player.h"

// ���� ��� � Entity ������ + AI ��� ���� ����� �������� �� ������ � ������
class Enemy : public Entity
{
public:
	// TODO player ������ ����� �� ����� ����� ��� ��� �� ����� static - � � ���� ����� ����� � ��� ����������
	// � ����� �� ��� ���� ����� ����� ���� ��������
	Enemy(b2World *world, Player* player, int hp);


	// TODO ������ update ������ ������ ��� ��� ����� ���������� � �������� � ������������ ���������
	// ������ ����� �� ������� sheduler �� �� ��� ������

	// Note: � ������ ����� ������������ rotate ���� �� ��� ����� ��� ��� ���� ����� �������������� ����� - ��� ���� ������ ���� ��� - �� ������ ����� ����� � ��� ��� ����� ���� � ��������� ������...

	virtual void setWeapon(Weapon *weapon);

protected:
	virtual void setupBody();

private:
	Player* player;
	cocos2d::CCSprite *sprite;

	// ���������� ��������� ������ � �������� ���� ���� ����� ���������� ����� ���� ���������
	void AIShoot(float dt);
	void AIMove(float dt);

	virtual void resolveCollision(GameObject* other);
	
};
