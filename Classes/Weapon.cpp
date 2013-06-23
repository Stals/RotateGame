#include "Weapon.h"
#include "GameLayer.h"
#include "Bullet.h"


	// cooldown - врем€ в секундах через которое можно стрел€ть
Weapon::Weapon(GameLayer *gameLayer, float cooldown){
	this->cooldown = cooldown;
}

	// –аз в какой промежуток может стрел€ть
	float Weapon::getCooldown(){
		return this->cooldown;
	}

	// выстрелит в том направлении
	// это точка на GameLayer
	void Weapon::shoot(cocos2d::CCPoint p){
		// создает пулю и отправл€ет еЄ в том направлении
		// добавл€ет еЄ на gameLayer
	}

