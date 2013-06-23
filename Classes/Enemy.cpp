#include "Enemy.h"

USING_NS_CC;

#define RANDOM_DELAY 100

Enemy::Enemy(Player* player, int hp):Entity(EntityType::EnemyType, hp){
	this->player = player;
	cocos2d::CCSprite *playerSprite = CCSprite::create("enemy.png");
	this->addChild(playerSprite);
}


void Enemy::AIShoot(float dt){
	this->shoot(player->getPosition());
}


void Enemy::AIMove(){

}

void Enemy::resolveCollision(GameObject* other){

}

void Enemy::setWeapon(Weapon *weapon){
	Entity::setWeapon(weapon);
	// сделаем чтобы он постоянно стрелял
	schedule(schedule_selector(Enemy::AIShoot), weapon->getCooldown() + (float)(rand() % RANDOM_DELAY)/100.0f);
}

void Enemy::setupBody(){


}