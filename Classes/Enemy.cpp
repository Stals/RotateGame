#include "Enemy.h"


Enemy::Enemy(Player* player, int hp):Entity(EntityType::EnemyType, hp){
	this->player = player;
}


void Enemy::AIShoot(){
	this->shoot(player->getPosition());
}


void Enemy::AIMove(){

}

void Enemy::resolveCollision(GameObject* other){

}

void Enemy::setupBody(){


}