#include "Armor.h"

#define ARMOR_HP 10

Armor::Armor(b2World *world):Entity(world, EntityType::PlayerType, ARMOR_HP){
	//	this->setContentSize(playerSprite->getContentSize());
	this->setupBody();
}

void Armor::resolveCollision(GameObject* other){

}

void Armor::setupBody(){
	/*
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
	*/

}