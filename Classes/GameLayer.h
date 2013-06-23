#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#pragma once
#include "AppMacros.h"
using namespace cocos2d;

#include "../external/Box2D/Box2D.h"
#include "ContactListener.h"

#include "Player.h"

class GameLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	void update(float dt);




    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    

private:
	b2World *m_b2dWorld;
    CContactListener *m_contactListener;
	Player* player;
	
	void setupPlayer();
	void setupBackground();
	void setupWorld();

    // implement the "static node()" method manually
    CREATE_FUNC(GameLayer);

	virtual void ccTouchesBegan(CCSet* touch, CCEvent* event);
	virtual void ccTouchesMoved(CCSet* touch, CCEvent* event);
	virtual void ccTouchesEnded(CCSet* touch, CCEvent* event);
    

};

#endif // __HELLOWORLD_SCENE_H__
