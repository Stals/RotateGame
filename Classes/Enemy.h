#pragma once
#include "AppMacros.h"
#include "Entity.h"
#include "Player.h"

// тоже что и Entity только + AI для того чтобы стрелять по игроку и летать
class Enemy : public Entity
{
public:
	// TODO player скорее всего не будет нужен так как он будет static - и к нему можно будет и так обратиться
	// А нужен он для того чтобы знать куда стрелять
	Enemy(Player* player, int hp);


	// TODO внутри update иногда решает что ему нужно выстрелить и стреляет с определенной задержкой
	// Скорее всего он создает sheduler по кд его оружия

	// Note: в теории может использовать rotate если на них будет щит для того чтобы компенсировать дамаг - это прям полных хард кор - он должен будет знать о том где летят пули и постоянно чекать...

	virtual void setWeapon(Weapon *weapon);
private:
	Player* player;

	// определяет положение игрока и стреляет туда чуть меняя координату чтобы чуть промазать
	void AIShoot(float dt);
	void AIMove(float dt);

	virtual void resolveCollision(GameObject* other);
	virtual void setupBody();
};
