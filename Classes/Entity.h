#pragma once
#include "AppMacros.h"
#include "GameObject.h"
#include "Weapon.h"

enum EntityType{
	PlayerType,
	EnemyType
	// NeutralType - их ничего не будет трогать?
};

// те объекты у которых есть HP
class Entity : public GameObject
{
public:
	Entity(EntityType type, int hp);
	int getHP();

	// speed какую скорость придали для вращение - смысл в том что она постоянно уменьшается пока не будет = 0
	// также то что сюда задают может варироваться только в диапазоне до MAX_SPEED
	// left определяет в какую сторону должно вращаться
	//
	void rotate(bool left, float speed);
	// Нужно для того чтобы определить насколько сейчас нужно повернуть луч
	float getAngle();


	// этот метод позволяет менять оружия на лету.
	// а за счет Weapon.shoot можно сразу будет иметь несколько оружий
	virtual void setWeapon(Weapon *weapon); // TODO if not null - destroy previous
	void shoot(cocos2d::CCPoint p); // стреялет текущим оружием в указанную точку
protected:
	virtual void resolveCollision(GameObject* other) = 0;
	virtual void setupBody() = 0;

private:
	int hp;
	Weapon* currentWeapon;

	EntityType type;
};


