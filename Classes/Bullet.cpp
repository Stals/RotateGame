#include "Bullet.h"
#include "Entity.h"

Bullet::Bullet(b2World *world, EntityType type, int damage):GameObject(world, type){
	GameObject::init();
	this->damage = damage;

	sprite = CCSprite::create("bullet2.png");
	this->addChild(sprite);
	this->autorelease();

	this->setupBody();
}

Bullet::~Bullet(){
	int i = 0;
}

int Bullet::getDamage(){
	return damage;
}

void Bullet::resolveCollision(GameObject* other){
	//по другому - если встртил когото - и он Entity, при этом type != своему типу и у него не 0 хп - тогда дамажить и взрываться.
	if(dynamic_cast<Entity*>(other) != 0){
		if(dynamic_cast<Entity*>(other)->getType() != this->getType()){
			this->removeFromParentAndCleanup(true);
		}
	}	
}

void Bullet::setupBody(){
	b2BodyDef spriteBodyDef;
    spriteBodyDef.type = b2_dynamicBody;
    spriteBodyDef.position.Set(this->getPositionX()/PTM_RATIO, 
		this->getPositionY()/PTM_RATIO);
    spriteBodyDef.userData = this;
    body = world->CreateBody(&spriteBodyDef);
 
    b2PolygonShape spriteShape;
	spriteShape.SetAsBox(sprite->getContentSize().width/PTM_RATIO/2,
                         sprite->getContentSize().height/PTM_RATIO/2);
    b2FixtureDef spriteShapeDef;
    spriteShapeDef.shape = &spriteShape;
    spriteShapeDef.density = 10.0;
    spriteShapeDef.isSensor = true;
    body->CreateFixture(&spriteShapeDef);
}

void Bullet::update( float dt){
	GameObject::update(dt);

	// TODO возможно это не самая лучшая идея на каждом кадре проверять не стоит ли её удалить...

	// TODO убирать пулю в Pool вместо удаления
	cocos2d::CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

	cocos2d::CCRect* rect = new cocos2d::CCRect;
	rect->setRect(0, 0, winSize.width, winSize.height);

	if(!rect->containsPoint(this->getPosition())){
		this->removeFromParentAndCleanup(true);
	}
	
}
