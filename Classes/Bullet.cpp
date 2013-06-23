#include "Bullet.h"


Bullet::Bullet(int damage):GameObject(/*b2World*/){
	this->damage = damage;

	cocos2d::CCSprite *playerSprite = CCSprite::create("bullet.png");
	this->addChild(playerSprite);
}

int Bullet::getDamage(){
	return damage;
}

void Bullet::resolveCollision(GameObject* other){

}

void Bullet::setupBody(){


}