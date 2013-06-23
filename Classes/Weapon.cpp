#include "Weapon.h"
#include "GameLayer.h"
#include "Bullet.h"
#include <cmath>

	// cooldown - ����� � �������� ����� ������� ����� ��������
Weapon::Weapon(b2World *world, GameLayer *gameLayer, float cooldown):world(world){
	CCSprite::init();
	this->gameLayer = gameLayer;
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

		Bullet* bullet = new Bullet(world, 1);
		//cocos2d::CCSprite *bullet = CCSprite::create("bullet.png");
		
		gameLayer->addChild(bullet, BulletZOrder);


		CCPoint startPosition = this->convertToWorldSpace(this->getPosition());
		CCPoint endPosition = p;
		const float angle = this->getAngle(endPosition, startPosition);


		bullet->setRotation(-angle);

		bullet->setPosition(startPosition);

		// TODO - ����� ������ �������� ���� ���� ����� ������������ ������� �����

		//bullet->runAction(cocos2d::CCMoveTo::create(1, p));
		
		bullet->runAction(CCSequence::create(
			CCMoveBy::create(2, ccp(1024*cos(CC_DEGREES_TO_RADIANS(angle - 180)), 1024*sin(CC_DEGREES_TO_RADIANS(angle - 180)))),
			NULL));

			// ��� �� ���� ����� ����� �������� ����� �� ���� ����� ��� ������ ��� ����
			// ����� ������ ����� ����� � ����� � ����������� � ������ ������ - ����� �������� ������ ������ � �������.
		
	}

	// returns angle in degrees
	float Weapon::getAngle(cocos2d::CCPoint p1,  cocos2d::CCPoint p2){
		float deltaY = p2.y - p1.y;
		float deltaX = p2.x - p1.x;
		return atan2(deltaY, deltaX) * 180 / PI;
	}
