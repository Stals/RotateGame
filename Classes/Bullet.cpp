#include "Bullet.h"


Bullet::Bullet(b2World *world, int damage):GameObject(world){
	GameObject::init();
	this->damage = damage;

	cocos2d::CCSprite *playerSprite = CCSprite::create("bullet2.png");
	this->setContentSize(playerSprite->getContentSize());
	this->addChild(playerSprite);
	this->autorelease();

	this->setupBody();
}

Bullet::~Bullet(){
	world->DestroyBody(body);
}

int Bullet::getDamage(){
	return damage;
}

void Bullet::resolveCollision(GameObject* other){

}

void Bullet::setupBody(){
	b2BodyDef spriteBodyDef;
    spriteBodyDef.type = b2_dynamicBody;
    spriteBodyDef.position.Set(this->getPositionX()/PTM_RATIO, 
		this->getPositionY()/PTM_RATIO);
    spriteBodyDef.userData = this;
    body = world->CreateBody(&spriteBodyDef);
 
    b2PolygonShape spriteShape;
	spriteShape.SetAsBox(this->getContentSize().width/PTM_RATIO/2,
                         this->getContentSize().height/PTM_RATIO/2);
    b2FixtureDef spriteShapeDef;
    spriteShapeDef.shape = &spriteShape;
    spriteShapeDef.density = 10.0;
    spriteShapeDef.isSensor = true;
    body->CreateFixture(&spriteShapeDef);
}

