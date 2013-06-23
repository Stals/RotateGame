#include "Entity.h"

Entity::Entity(EntityType type, int hp):GameObject(/*b2world*/){
	this->hp = hp;
	this->type = type;
	this->currentWeapon = NULL;
}

int Entity::getHP(){
	return hp;
}

// speed ����� �������� ������� ��� �������� - ����� � ��� ��� ��� ��������� ����������� ���� �� ����� = 0
// ����� �� ��� ���� ������ ����� ������������ ������ � ��������� �� MAX_SPEED
// left ���������� � ����� ������� ������ ���������
//
void Entity::rotate(bool left, float speed){
	CCLOG("Rotating");
}

// ����� ��� ���� ����� ���������� ��������� ������ ����� ��������� ���
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

void Entity::shoot(cocos2d::CCPoint p){ // �������� ������� ������� � ��������� �����
	currentWeapon->shoot(p);
}


