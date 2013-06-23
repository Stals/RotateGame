#include "Enemy.h"
#include "Bullet.h"

USING_NS_CC;

#define RANDOM_DELAY (float)(rand() % 100)/100.0f

Enemy::Enemy(b2World *world, Player* player, int hp):Entity(world, EntityType::EnemyType, hp){
	this->player = player;
	sprite = CCSprite::create("enemy.png");
	this->setContentSize(sprite->getContentSize());

	this->addChild(sprite);
	schedule(schedule_selector(Enemy::AIMove), 2.0f + RANDOM_DELAY*2);

	this->setupBody();
}


void Enemy::AIShoot(float dt){
	if(player){
		this->shoot(player->getPosition());
	}
}


void Enemy::AIMove(float dt){
	if(this){
		CCPoint delta;
		delta.x = (rand() % 64) - 32;
		delta.y = (rand() % 64) - 32;

		this->runAction(cocos2d::CCMoveBy::create(1.0f, delta)); 
	}
}

void Enemy::resolveCollision(GameObject* other){
	if(dynamic_cast<Bullet*>(other) != 0){
		if(dynamic_cast<Bullet*>(other)->getType() != this->getType()){
			this->hp -= dynamic_cast<Bullet*>(other)->getDamage();
			this->updateHPLabel();
		}
	}	
}

void Enemy::setWeapon(Weapon *weapon){
	Entity::setWeapon(weapon);
	// сделаем чтобы он постоянно стрелял
	schedule(schedule_selector(Enemy::AIShoot), weapon->getCooldown() + RANDOM_DELAY);
}

void Enemy::setupBody(){
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