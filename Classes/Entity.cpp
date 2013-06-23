#include "Entity.h"

Entity::Entity(EntityType type, int hp):GameObject(/*b2world*/){
	this->hp = hp;
	this->type = type;
	this->currentWeapon = NULL;
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
}

void Entity::shoot(cocos2d::CCPoint p){ // стреялет текущим оружием в указанную точку
	currentWeapon->shoot(p);
}


