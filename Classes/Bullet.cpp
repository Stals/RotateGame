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
}

int Bullet::getDamage(){
	return damage;
}

void Bullet::resolveCollision(GameObject* other){
	//по другому - если встртил когото - и он Entity, при этом type != своему типу и у него не 0 хп - тогда дамажить и взрываться.
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

void Bullet::update( float dt){
	GameObject::update(dt);

	cocos2d::CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

	cocos2d::CCRect* rect = new cocos2d::CCRect;
	rect->setRect(0, 0, winSize.width, winSize.height);

	if(!rect->containsPoint(this->getPosition())){
		this->removeFromParentAndCleanup(true);
	}
	
}
