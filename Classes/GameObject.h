#pragma once
#include "AppMacros.h"

#include "../external/Box2D/Box2D.h"

// Любой объект у которого есть box2d body и как-то реагирует на колизии
class GameObject : public cocos2d::CCSprite{
public:
	GameObject(b2World *world);
	~GameObject();

	//virtual bool init();

	// этот метод вызывает contactListener для всех объектов у которых у обоих есть userData - которая полюбому является GameObject или его наследником
	virtual void resolveCollision(GameObject* other) = 0;

protected:
	b2Body *body;
	b2World *world;

	// TODO хранит в себе body 2d и обновляет его положение на свое текущее (причем скорее всего нужно обновлять его на worlCoords положение)
	// тоесть все делает через convertToWorldSpace и делит на 32 или сколько то там.
	virtual void setupBody() = 0;

	// TODO тоесть в результате наследники только задают как выглядит их тело и делают специальные штуки при resolveCollision
	// ну и в конуструкторе соответственно свой правильный спрайт загружает

	// обновляет положение этого спрайта внутри box2d мира
	// Note: если наследуется то должен вызывать update родительского класса
	virtual void update( float dt);

	
};