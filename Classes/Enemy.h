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
	Enemy(Player* player, int hp);


	// TODO ������ update ������ ������ ��� ��� ����� ���������� � �������� � ������������ ���������
	// ������ ����� �� ������� sheduler �� �� ��� ������

	// Note: � ������ ����� ������������ rotate ���� �� ��� ����� ��� ��� ���� ����� �������������� ����� - ��� ���� ������ ���� ��� - �� ������ ����� ����� � ��� ��� ����� ���� � ��������� ������...

	virtual void setWeapon(Weapon *weapon);
private:
	Player* player;

	// ���������� ��������� ������ � �������� ���� ���� ����� ���������� ����� ���� ���������
	void AIShoot(float dt);
	void AIMove(float dt);

	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
};
