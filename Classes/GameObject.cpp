#include "GameObject.h"



GameObject::GameObject(/*b2World *world*/){
	CCSprite::init();
	this->setupBody();
	this->scheduleUpdate();
}


// TODO ������ � ���������� ���������� ������ ������ ��� �������� �� ���� � ������ ����������� ����� ��� resolveCollision
// �� � � ������������� �������������� ���� ���������� ������ ���������

// ��������� ��������� ����� ������� ������ box2d ����
// Note: ���� ����������� �� ������ �������� update ������������� ������
void GameObject::update( float dt){
	int i = 0;
	
}
