#include "GameLayer.h"
#include "AppMacros.h"

//#include "SimpleAudioEngine.h"
USING_NS_CC;


CCScene* GameLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameLayer *layer = GameLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	setupBackground();
	setupPlayer();
	setupWorld();
   
	setTouchEnabled(true);
    scheduleUpdate();

    // Touch dispatcher
    //CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
    return true;
}

void GameLayer::setupBackground(){
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *bg = CCSprite::create("bg.png");
	bg->setPosition(ccp(winSize.width/2, winSize.height/2));
	addChild(bg);
}

void GameLayer::setupPlayer(){
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    

	player = new Player;   
	player->setPosition(ccp(winSize.width/2, winSize.height/2));
	addChild(player);
}

void GameLayer::setupWorld(){
	// Create b2 world
    b2Vec2 gravity = b2Vec2(0.0f, 0.0f); // Gravity is zero as we aren't using it, zero turns it off so no processor time wasted.
    m_b2dWorld = new b2World(gravity);
    
    // Create contact listener
    m_contactListener = new CContactListener();
    m_b2dWorld->SetContactListener(m_contactListener);
}


void GameLayer::ccTouchesBegan(CCSet* touches, CCEvent* event)
{


	// как отличить тач для выстрела от тача для поворота?
		// пока можно если тачнули и отпутили - без moved то выстрел
		// а иначе - понимаем насколько повернули и делаем player->rotate()
		// причем если начали двигать - то сделать 100% что попорот и нужно начинать, а когда закончили закончить
		// понятно что ему дали скорость - и он теряет её с определенной скоростью

    CCSetIterator it = touches->begin();
    CCTouch* touch;

    CCPoint pt;
    for( int iTouchCount = 0; iTouchCount < touches->count(); iTouchCount++ )
    {
        touch = (CCTouch*)(*it);
        pt = touch->getLocationInView();
        printf( "ccTouchesBegan id:%i %i,%i\n", touch->getID(), (int)pt.x, (int)pt.y );
        it++;
    }
}

void GameLayer::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
    CCSetIterator it = touches->begin();
    CCTouch* touch;

    CCPoint pt;
    for( int iTouchCount = 0; iTouchCount < touches->count(); iTouchCount++ )
    {
        touch = (CCTouch*)(*it);
        pt = touch->getLocationInView();
        printf( "ccTouchesMoved id:%i %i,%i\n", touch->getID(), (int)pt.x, (int)pt.y );
        it++;
    }
}

void GameLayer::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	// TODO Определяет координату в которую нужно выстрелить

    CCSetIterator it = touches->begin();
    CCTouch* touch;

    CCPoint pt;
    for( int iTouchCount = 0; iTouchCount < touches->count(); iTouchCount++ )
    {
        touch = (CCTouch*)(*it);
        pt = touch->getLocationInView();
        printf( "ccTouchesEnded id:%i %i,%i\n", touch->getID(), (int)pt.x, (int)pt.y );
        it++;
    }
}


void GameLayer::update(float delta )
{/*
   // Updates the physics simulation for 10 iterations for velocity/position
    m_b2dWorld->Step(delta, 10, 10);

    // Loop through all of the Box2D bodies in our Box2D world..
    for(b2Body *b = m_b2dWorld->GetBodyList(); b; b=b->GetNext()) 
    {
        // See if there's any user data attached to the Box2D body
        // There should be, since we set it in addBoxBodyForSprite
        if (b->GetUserData() != NULL) 
        {   
            // We know that the user data is a sprite since we set
            // it that way, so cast it...
            CCSprite *sprite = (CCSprite *)b->GetUserData();
            
            // Convert the Cocos2D position/rotation of the sprite to the Box2D position/rotation
            CCPoint Pos = sprite->getPosition();
            b2Vec2 b2Position = b2Vec2(Pos.x/PTM_RATIO,
                                       Pos.y/PTM_RATIO);
            float32 b2Angle = -1 * CC_DEGREES_TO_RADIANS(sprite->getRotation());
            
            // Update the Box2D position/rotation to match the Cocos2D position/rotation
            b->SetTransform(b2Position, b2Angle);
        }
    }
    
    // Loop through all of the box2d bodies that are currently colliding, that we have
    // gathered with our custom contact listener...
    std::vector<b2Body *>toDestroy; 
    std::vector<ContactData>::iterator pos;
    for(pos = m_contactListener->_contacts.begin(); pos != m_contactListener->_contacts.end(); ++pos) 
    {
        ContactData contact = *pos;
        
        // Get the box2d bodies for each object
        b2Body *bodyA = contact.fixtureA->GetBody();
        b2Body *bodyB = contact.fixtureB->GetBody();
        if (bodyA->GetUserData() != NULL && bodyB->GetUserData() != NULL) 
        {
            CCSprite *spriteA = (CCSprite *) bodyA->GetUserData();
            CCSprite *spriteB = (CCSprite *) bodyB->GetUserData();
            int iTagA = spriteA->getTag();
            int iTagB = spriteB->getTag();
            
            // Is sprite A a cat and sprite B a car?  If so, push the cat on a list to be destroyed...
            if (iTagA == 1 && iTagB == 2)
                toDestroy.push_back(bodyA);
            // Is sprite A a car and sprite B a cat?  If so, push the cat on a list to be destroyed...
            else if (iTagA == 2 && iTagB == 1) 
                toDestroy.push_back(bodyB);
             
        }        
    }

    // Loop through all of the box2d bodies we wnat to destroy...
    std::vector<b2Body *>::iterator pos2;
    for(pos2 = toDestroy.begin(); pos2 != toDestroy.end(); ++pos2) 
    {
        b2Body *body = *pos2;     
        
        // See if there's any user data attached to the Box2D body
        // There should be, since we set it in addBoxBodyForSprite
        if (body->GetUserData() != NULL) 
        {
            
            // We know that the user data is a sprite since we set
            // it that way, so cast it...
            CCSprite *sprite = (CCSprite *) body->GetUserData();
            
            // Remove the sprite from the scene
            //[_spriteSheet removeChild:sprite cleanup:YES];
            //m_spriteSheet->removeChild( sprite, true );
        }
        
        // Destroy the Box2D body as well
        m_b2dWorld->DestroyBody(body);
    }
    
    // If we've destroyed anything, play an amusing and malicious sound effect!  ;]
    if (toDestroy.size() > 0) 
    {
      //  CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect( "cat_ouch.wav", false );
    }
	*/
}
