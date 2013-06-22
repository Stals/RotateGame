#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

#include "../external/Box2D/Box2D.h"
//#include "GLES-Render.h"
#include "ContactListener.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	virtual void draw(void);

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

	virtual void ccTouchesBegan(CCSet* touch, CCEvent* event);
	virtual void ccTouchesMoved(CCSet* touch, CCEvent* event);
	virtual void ccTouchesEnded(CCSet* touch, CCEvent* event);
    
    void secondUpdate( float delta );
    void tick( float delta );
    void CreateBox2DBodyForSprite( CCSprite *sprite, int iNumVerts, b2Vec2 verts[] );
    void spriteDone(CCNode* sender);
    void spawnCat();
    void spawnCar() ;

    b2World *m_b2dWorld;
    //GLESDebugDraw *m_b2dDebugDraw;
    CContactListener *m_contactListener;
    CCNode *m_spriteSheet;    
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
