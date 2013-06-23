#pragma once
#include "AppMacros.h"
#include "Entity.h"

class Player: public Entity
{
public:
	Player();

	// � ���� ���� ����������� �����
	// ���� ���� � ������������ �� ��� ������� 
	// � ����� ���� 1 ��� � ���� �� ���������
private:
	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
};
