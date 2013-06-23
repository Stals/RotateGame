#include "Enemy.h"

USING_NS_CC;

#define RANDOM_DELAY (float)(rand() % 100)/100.0f

Enemy::Enemy(Player* player, int hp):Entity(EntityType::EnemyType, hp){
	this->player = player;
	cocos2d::CCSprite *playerSprite = CCSprite::create("enemy.png");
	this->addChild(playerSprite);
	schedule(schedule_selector(Enemy::AIMove), 2.0f + RANDOM_DELAY*2);
}


void Enemy::AIShoot(float dt){
	this->shoot(player->getPosition());
}


void Enemy::AIMove(float dt){
	CCPoint delta;
	delta.x = (rand() % 64) - 32;
	delta.y = (rand() % 64) - 32;

	this->runAction(cocos2d::CCMoveBy::create(1.0f, delta)); 
}

void Enemy::resolveCollision(GameObject* other){

}

void Enemy::setWeapon(Weapon *weapon){
	Entity::setWeapon(weapon);
	// сделаем чтобы он постоянно стрелял
	schedule(schedule_selector(Enemy::AIShoot), weapon->getCooldown() + RANDOM_DELAY);
}

void Enemy::setupBody(){


}