#include "Weapon.h"
#include "GameLayer.h"
#include "Bullet.h"


	// cooldown - ����� � �������� ����� ������� ����� ��������
Weapon::Weapon(GameLayer *gameLayer, float cooldown){
	this->cooldown = cooldown;
}

	// ��� � ����� ���������� ����� ��������
	float Weapon::getCooldown(){
		return this->cooldown;
	}

	// ��������� � ��� �����������
	// ��� ����� �� GameLayer
	void Weapon::shoot(cocos2d::CCPoint p){
		// ������� ���� � ���������� � � ��� �����������
		// ��������� � �� gameLayer
	}

