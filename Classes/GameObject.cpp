#include "GameObject.h"



GameObject::GameObject(/*b2World *world*/){
	CCSprite::init();
	this->setupBody();
	this->scheduleUpdate();
}


// TODO тоесть в результате наследники только задают как выглядит их тело и делают специальные штуки при resolveCollision
// ну и в конуструкторе соответственно свой правильный спрайт загружает

// обновляет положение этого спрайта внутри box2d мира
// Note: если наследуется то должен вызывать update родительского класса
void GameObject::update( float dt){
	int i = 0;
	
}
