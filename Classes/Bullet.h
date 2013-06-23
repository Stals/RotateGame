#pragma once
#include "AppMacros.h"
#include "GameObject.h"

// � ������ ��� ��� ������ ���� ������ � ������ - �������� ��� ����� ���� ������ ������������
class Bullet: public GameObject{
public:
	Bullet(int damage);
	int getDamage();

	// ��� ����� �����?
	// ��� ����� � ������?
	// ����� � ���� �������
	// ������ ���� ��� ���� ��� ������ � �� ����� ���� ������ �������� ��� ������� ���� ���� ��.

	//TODO - ��������� �� ������ ������ ���� � ���� ���� ��.
	// ���������� �� ����� ����� �������. ������ � ��� ���������� �� ��� ��� ��� ��������� ����
	//!!! �� ������� - ���� ������� ������ - � �� Entity, ��� ���� type != ������ ���� � � ���� �� 0 �� - ����� �������� � ����������.
private:
	int damage;

	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
};

// TODO ��� � ����� �������� bullet MoveTo ���� �� ����� ��������� ������ �������? ���� � ���� ��� ����� world coords �� �� ������, �� ����� ������������ ��� ��������� ��. ����.