#pragma once
#include "AppMacros.h"
#include "Entity.h"

// ���� ��� � Entity ������ ������������ ���� �� � �� ��������� ���� � ���� ���! 
// TODO � ������ ����� �� ������ ������������� �� ����-�� � ���� ���� ������
// TODO ��������� �� collide ������ ���� �� != 0
class Armor : public Entity{
public:
	Armor();
private:
	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
};
