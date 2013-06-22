#pragma once
#include "AppMacros.h"
class GameLayer;

// �������� �� ����������� ���� � ������������ ����� � ������������ ���������
// Note: ���� ����� ���� ����������, �� � ������ � ���� ����� ���� �������� ��� �������� � ��
class Weapon : public cocos2d::CCSprite
{
public:
	// TODO �������� gamelayer ����� ��� ���� ����� �������� ���� �� ����.
	// ���� ���� �� ����� ���� �� ����� ���� ��� �������� ���� ���������� � ��������� toWorld ����� ������� ��� ��� ���� box2d
	// ������ ����� � ��� �� ������� ������� � �������� ������������ ����� � �����
	// � ������ update ������ ��������� ������ ��� ��������� � �������� ����������� � �����������

	// cooldown - ����� � �������� ����� ������� ����� ��������
	Weapon(GameLayer *gameLayer, float cooldown);

	// ��� � ����� ���������� ����� ��������
	float getCooldown();

	// ��������� � ��� �����������
	// ��� ����� �� GameLayer
	void shoot(cocos2d::CCPoint p);

private:
	float cooldown;
};