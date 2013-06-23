#pragma once
#include "AppMacros.h"
#include "../external/Box2D/Box2D.h"
#include "EntityType.h"
class GameLayer;

// Отвечает за отправление пули в определенную точку с определенной скоростью
// Note: пока будет тупо прозрачным, но в теории у него могут быть анимации при выстреле и тд
class Weapon : public cocos2d::CCSprite
{
public:
	// TODO возможно gamelayer нужно для того чтобы добавить пулю на него.
	// Либо было бы круто если бы можно было для расчетов тупо конвернуть её положение toWorld чтобы указать где она длля box2d
	// Просто тогда я мог бы крутить корабль с оружиями одновременно крутя и лазер
	// а внутри update лазера постоянно менять его положения и засекать пересечения с противником

	// cooldown - время в секундах через которое можно стрелять
	Weapon(b2World *world, GameLayer *gameLayer, float cooldown);

	// Раз в какой промежуток может стрелять
	float getCooldown();

	// выстрелит в том направлении
	// это точка на GameLayer
	void shoot(cocos2d::CCPoint p);

	void setObjectType(EntityType type);

private:
	b2World *world;
	GameLayer *gameLayer;
	float cooldown;
	EntityType type;

	// returns angle in degrees
	float getAngle(cocos2d::CCPoint p1,  cocos2d::CCPoint p2);
};