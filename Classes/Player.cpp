#include "Player.h"


#define PLAYER_HP 10

Player::Player():Entity(EntityType::PlayerType, PLAYER_HP){
	  
	cocos2d::CCSprite *playerSprite = CCSprite::create("player.png");
	this->addChild(playerSprite);
}

void Player::resolveCollision(GameObject* other){

}

void Player::setupBody(){


}