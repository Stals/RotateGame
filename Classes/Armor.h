#pragma once
#include "AppMacros.h"
#include "Entity.h"

// Тоже что и Entity только регенерирует свои ХП и не колизится если у него нет! 
// TODO в теории армор не должен наследоваться от чего-то у чего есть оружие
// TODO реагирует на collide только если хп != 0
class Armor : public Entity{
public:
	Armor(b2World *world);
private:
	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
};
