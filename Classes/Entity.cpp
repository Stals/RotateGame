#include "Entity.h"

#include <sstream>

Entity::Entity(b2World *world, EntityType type, int hp):GameObject(world, type){
	GameObject::init();
	this->hp = hp;
	this->type = type;
	this->currentWeapon = NULL;

	this->setupHPLabel();
}


int Entity::getHP(){
	return hp;
}

// speed какую скорость придали для вращение - смысл в том что она постоянно уменьшается пока не будет = 0
// также то что сюда задают может варироваться только в диапазоне до MAX_SPEED
// left определяет в какую сторону должно вращаться
//
void Entity::rotate(bool left, float speed){
	CCLOG("Rotating");
}

// Нужно для того чтобы определить насколько сейчас нужно повернуть луч
float Entity::getAngle(){
	return 0.0f;
}


void Entity::setWeapon(Weapon *weapon){ // TODO if not null - destroy previous
	if(currentWeapon != NULL){
		currentWeapon->removeFromParentAndCleanup(true);
		currentWeapon = NULL;
	}

	currentWeapon = weapon;
	currentWeapon->setObjectType(type);
	this->addChild(currentWeapon);
}

void Entity::shoot(cocos2d::CCPoint p){ // стреялет текущим оружием в указанную точку
	if(currentWeapon != NULL){
		currentWeapon->shoot(p);
	}
}

void Entity::setupHPLabel(){
	hpLabel = cocos2d::CCLabelTTF::create("100", "Thonburi", 24);
	this->addChild(hpLabel, 100);
	updateHPLabel();
}

void Entity::updateHPLabel(){
	std::stringstream sstream;
	sstream << this->hp;
	hpLabel->setString(sstream.str().c_str());
}

void Entity::update( float dt){
	GameObject::update(dt);
	if(hp <= 0){
		this->removeFromParentAndCleanup(true);
	}
}