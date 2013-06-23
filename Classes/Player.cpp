#include "Player.h"
#include "Bullet.h"

#define PLAYER_HP 50

Player::Player(b2World *world):Entity(world, EntityType::PlayerType, PLAYER_HP){
	  
	playerSprite = CCSprite::create("player.png");
	this->addChild(playerSprite);

	this->setupBody();
}

Player::~Player(){
	
}

void Player::resolveCollision(GameObject* other){
	if(dynamic_cast<Bullet*>(other) != 0){
		//if(dynamic_cast<Bullet*>(other)->getT

		this->hp -= dynamic_cast<Bullet*>(other)->getDamage();
		this->updateHPLabel();
	}

	
}

void Player::setupBody(){
	b2BodyDef spriteBodyDef;
    spriteBodyDef.type = b2_dynamicBody;
    spriteBodyDef.position.Set(this->getPositionX()/PTM_RATIO, 
		this->getPositionY()/PTM_RATIO);
    spriteBodyDef.userData = this;
    body = world->CreateBody(&spriteBodyDef);
 
    b2PolygonShape spriteShape;
	spriteShape.SetAsBox(playerSprite->getContentSize().width/PTM_RATIO/2,
                         playerSprite->getContentSize().height/PTM_RATIO/2);
    b2FixtureDef spriteShapeDef;
    spriteShapeDef.shape = &spriteShape;
    spriteShapeDef.density = 10.0;
    spriteShapeDef.isSensor = true;
    body->CreateFixture(&spriteShapeDef);

}