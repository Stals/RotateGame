#include "Bullet.h"


Bullet::Bullet(int damage){
	this->damage = damage;
}

int Bullet::getDamage(){
	return damage;
}

void Bullet::resolveCollision(GameObject* other){

}

void Bullet::setupBody(){


}