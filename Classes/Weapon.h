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

	// TODO - ��� ����� ���� ������������ ����!

private:
	GameLayer *gameLayer;
	float cooldown;
	// returns angle in degrees
	float getAngle(cocos2d::CCPoint p1,  cocos2d::CCPoint p2);
	void bulletDone(CCNode* sender);
};