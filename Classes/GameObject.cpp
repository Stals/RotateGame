#include "GameObject.h"


USING_NS_CC;

GameObject::GameObject(b2World *world, EntityType type):world(world), type(type)
{
	CCSprite::init();
	this->scheduleUpdate();

}

GameObject::~GameObject(){
	if(body){
		world->DestroyBody(body);
	}
}

EntityType GameObject::getType(){
	return type;
}

/*
bool GameObject::init(){
	
	this->setupBody();
	return true;
}*/

// TODO ������ � ���������� ���������� ������ ������ ��� �������� �� ���� � ������ ����������� ����� ��� resolveCollision
// �� � � ������������� �������������� ���� ���������� ������ ���������

// ��������� ��������� ����� ������� ������ box2d ����
// Note: ���� ����������� �� ������ �������� update ������������� ������
void GameObject::update( float dt){
	CCPoint Pos =  this->convertToWorldSpace(CCPointZero);  //this->getPosition(); //CCDirector::sharedDirector()->convertToUI(this->getPosition());

    b2Vec2 b2Position = b2Vec2(Pos.x/PTM_RATIO,
                                Pos.y/PTM_RATIO);
    float32 b2Angle = -1 * CC_DEGREES_TO_RADIANS(this->getRotation());
            
    // Update the Box2D position/rotation to match the Cocos2D position/rotation
   body->SetTransform(b2Position, b2Angle);
}
