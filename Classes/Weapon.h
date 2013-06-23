#pragma once
#include "AppMacros.h"
#include "../external/Box2D/Box2D.h"
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
	Weapon(b2World *world, GameLayer *gameLayer, float cooldown);

	// ��� � ����� ���������� ����� ��������
	float getCooldown();

	// ��������� � ��� �����������
	// ��� ����� �� GameLayer
	void shoot(cocos2d::CCPoint p);

	// TODO - ��� ����� ���� ������������ ����!

private:
	b2World *world;
	GameLayer *gameLayer;
	float cooldown;
	// returns angle in degrees
	float getAngle(cocos2d::CCPoint p1,  cocos2d::CCPoint p2);
};