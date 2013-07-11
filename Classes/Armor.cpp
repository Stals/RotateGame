#include "Armor.h"
#include "Bullet.h"

USING_NS_CC;

#define ARMOR_HP 10
#define HEAL_CD 2.0f
#define OFF_OPACITY 100.0f

Armor::Armor(b2World *world):Entity(world, EntityType::PlayerType, ARMOR_HP){

	sprite = CCSprite::create("player_armor.png");

	this->addChild(sprite);
	schedule(schedule_selector(Armor::Regen), HEAL_CD);

	this->setupBody();
	this->hpLabel->setPosition(ccp(25,25));
}

void Armor::resolveCollision(GameObject* other){
	if(dynamic_cast<Bullet*>(other) != 0){
		if(dynamic_cast<Bullet*>(other)->getType() != this->getType()){
			this->hp -= dynamic_cast<Bullet*>(other)->getDamage();
			if(hp < 0) hp = 0;
			this->updateHPLabel();
		}
	}	
}

void Armor::setupBody(){
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

void Armor::Regen(float dt){
	if(hp < ARMOR_HP){
		++hp;
		this->updateHPLabel();
	}
}


float Armor::getWidth(){
	return sprite->getContentSize().width;
}

float Armor::getHeight(){
	return sprite->getContentSize().height;
}



void Armor::rotate(float degrees){
	// TODO тут в теории нужно всеравно себ€ будет делать rotate но label - нет
	this->setRotation(degrees);
	this->hpLabel->setRotation(-degrees);
}


void Armor::update( float dt){
	// —пециально не вызываем Entity потому что там он удал€ет
	GameObject::update(dt);
	if(hp <= 0){
		sprite->setOpacity(OFF_OPACITY);
	}else{
		sprite->setOpacity(255.0f);
	}
}