#include "HelloWorldScene.h"
#include "AppMacros.h"
//#include "SimpleAudioEngine.h"
USING_NS_CC;


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
   /* CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);*/

    /////////////////////////////
    // 3. add your codes below...


	// add a label shows "Hello World"
	// create and initialize a label
	/*CCLabelTTF* pLabel = CCLabelTTF::create("Kitty Splatter", "Thonburi", 34);

	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// position the label on the center of the screen
	pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

	// add the label as a child to this layer
	this->addChild(pLabel, 1);

	// add "HelloWorld" splash screen"
	CCSprite* pSprite = CCSprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );

	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);
	*/
    
    ////////////////////////////////////////////////////
    // Load the sprite sheet and make a "batch node" for that sprite sheet. See http://www.cocos2d-iphone.org/api-ref/0.99.5/interface_c_c_sprite_batch_node.html
    // We have "HD" graphics and "SD" graphics.
   /* CCSize realScreenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    if (realScreenSize.height != 768 && realScreenSize.height != 320 )
    {
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("sprites-hd.plist");
        m_spriteSheet = CCSpriteBatchNode::create("sprites-hd.png");
    }
    else
    {
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("sprites.plist");
        m_spriteSheet = CCSpriteBatchNode::create("sprites.png");
    }
    
    addChild(m_spriteSheet, 0, 0);*/
    
    // Preload effect
    //CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect( "cat_ouch.wav" );

    ////////////////////////////////////////////////////
    // Create b2 world
    b2Vec2 gravity = b2Vec2(0.0f, 0.0f);            // Gravity is zero as we aren't using it, zero turns it off so no processor time wasted.
    m_b2dWorld = new b2World(gravity);

    // Debug Draw
//    m_b2dDebugDraw = NULL;
//    // Enable debug draw by un-commenting the next line. NOTE: **** this debug stuff currently isn't displaying correctly, should get fixed soon
//    //m_b2dDebugDraw = new GLESDebugDraw( PTM_RATIO );
//    if( m_b2dDebugDraw )
//    {
//        m_b2dWorld->SetDebugDraw(m_b2dDebugDraw);
//
//        uint32 flags = 0;
//        flags += b2Draw::e_shapeBit;               // Shows the collision shape
//        // Only need above bit really, add the below flag bits for more detail
//        //flags += b2Draw::e_jointBit;             // Shows joints - where two box2D objects are joined (not using any joints here).
//        flags += b2Draw::e_aabbBit;
//        flags += b2Draw::e_pairBit;                // draws a line when two sprites rect bounds are overlapping
//        //flags += b2Draw::e_centerOfMassBit;
//        m_b2dDebugDraw->SetFlags(flags);
//    }
    
    // Create contact listener
    m_contactListener = new CContactListener();
    m_b2dWorld->SetContactListener(m_contactListener);
    ////////////////////////////////////////////////////
    
    spawnCar();
    schedule(schedule_selector(HelloWorld::secondUpdate), 1);     //interval:1.0];
    schedule(schedule_selector(HelloWorld::tick));
    
    // Touch dispatcher
    CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void HelloWorld::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
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

void HelloWorld::ccTouchesMoved(CCSet* touches, CCEvent* event)
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

void HelloWorld::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HelloWorld::draw(void)
{
    CCLayer::draw();

// The debug draw isn't working, there is a discussion on the cocos2d-x forum on how to do this
    if( true )
    {
      /*  glDisable(GL_TEXTURE_2D);                               
        glDisableClientState(GL_COLOR_ARRAY);               // so polys draw properly and plain colour
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);       // doesnt seem to matter
        glEnableClientState(GL_VERTEX_ARRAY);             // vertices are drawn with this flag set
        
        m_b2dWorld->DrawDebugData();

        *glDisableClientState(GL_VERTEX_ARRAY);   
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glEnable(GL_TEXTURE_2D);*/
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HelloWorld::secondUpdate( float delta )
{
    spawnCat();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Called every frame. Tells Box2D to update (detect collisions as we aren't using gravity). And then we check for 
// collision data in the "m_contactListener->_contacts".
//
// How this all works:
//   - Box2D is called and it checks for collisions.
//   - As Box2D finds collisions it calls our "CContactListener::BeginContact(b2Contact* contact)" which records them
//     in an array "_contacts".
//   - Box2D returns.
//   - We check the "m_contactListener->_contacts" array for any collisions. 

void HelloWorld::tick( float delta )
{
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
    /*for(pos = m_contactListener->_contacts.begin(); pos != m_contactListener->_contacts.end(); ++pos) 
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
    }*/

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
            m_spriteSheet->removeChild( sprite, true );
        }
        
        // Destroy the Box2D body as well
        m_b2dWorld->DestroyBody(body);
    }
    
    // If we've destroyed anything, play an amusing and malicious sound effect!  ;]
    if (toDestroy.size() > 0) 
    {
      //  CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect( "cat_ouch.wav", false );
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This function send the vertice data to Box2D. Also, if you pass iNumVerts==0 and verts==NULL it simply creates a 
// box round your sprite.

void HelloWorld::CreateBox2DBodyForSprite( CCSprite *sprite, int iNumVerts, b2Vec2 verts[] )
{ 
    if( m_b2dWorld==NULL )
        return;
        
    CCPoint pos = sprite->getPosition();
	CCSize size = sprite->getContentSize();
        
    b2BodyDef spriteBodyDef;
    spriteBodyDef.type = b2_dynamicBody;
    spriteBodyDef.position.Set(pos.x/PTM_RATIO, pos.y/PTM_RATIO);
    spriteBodyDef.userData = sprite;
    b2Body *spriteBody = m_b2dWorld->CreateBody(&spriteBodyDef);

    b2PolygonShape spriteShape;

    if( iNumVerts!=0 )
    {
        spriteShape.Set(verts, iNumVerts);
        b2FixtureDef spriteShapeDef;
        spriteShapeDef.shape = &spriteShape;
        spriteShapeDef.density = 10.0;
        spriteShapeDef.isSensor = true;
        
        spriteBody->CreateFixture(&spriteShapeDef);
    }
    else
    {
        // No Vertice supplied so just make a box round the sprite
        b2BodyDef spriteBodyDef;
        spriteBodyDef.type = b2_dynamicBody;
        spriteBodyDef.position.Set( pos.x/PTM_RATIO, pos.y/PTM_RATIO );
        spriteBodyDef.userData = sprite;
        b2Body *spriteBody = m_b2dWorld->CreateBody( &spriteBodyDef );

        b2PolygonShape spriteShape;
        spriteShape.SetAsBox( size.width/PTM_RATIO/2, size.height/PTM_RATIO/2 );
        b2FixtureDef spriteShapeDef;
        spriteShapeDef.shape = &spriteShape;
        spriteShapeDef.density = 10.0;
        spriteShapeDef.isSensor = true;                     // isSensor true when you want to know when objects will collide without triggering a box2d collision response
        spriteBody->CreateFixture( &spriteShapeDef );
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HelloWorld::spriteDone(CCNode* sender)
{
    // This selector is called from CCCallFuncN, and it passes the object the action is
    // run on as a parameter.  We know it's a sprite, so cast it as that!
    CCSprite *sprite = (CCSprite *)sender;
    
    // Loop through all of the Box2D bodies in our Box2D world...
    // We're looking for the Box2D body corresponding to the sprite.
    b2Body *spriteBody = NULL;
    for(b2Body *b = m_b2dWorld->GetBodyList(); b; b=b->GetNext()) 
    {
        // See if there's any user data attached to the Box2D body
        // There should be, since we set it in addBoxBodyForSprite
        if (b->GetUserData() != NULL) {
            
            // We know that the user data is a sprite since we set
            // it that way, so cast it...
            CCSprite *curSprite = (CCSprite *)b->GetUserData();
            
            // If the sprite for this body is the same as our current
            // sprite, we've found the Box2D body we're looking for!
            if (sprite == curSprite) {
                spriteBody = b;
                break;
            }
        }
    }
    
    // If we found the body, we want to destroy it since the cat is offscreen now.
    if (spriteBody != NULL) {
        m_b2dWorld->DestroyBody(spriteBody);
    }
    
    // And of course we need to remove the Cocos2D sprite too.
    m_spriteSheet->removeChild(sprite, true);
    //m_spriteSheet->
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HelloWorld::spawnCar() 
{
    CCSprite *car = CCSprite::createWithSpriteFrameName("car.png");
    
    car->setPosition(ccp(100, 100));
    car->setTag(2);
               
    CCActionInterval*  action1 = CCMoveTo::create(1.0, CCPointMake(300,100));
    CCActionInterval*  action2 = CCMoveTo::create(1.0, CCPointMake(200,200));
    CCActionInterval*  action3 = CCMoveTo::create(1.0, CCPointMake(100,100));
    CCActionInterval*  seq = (CCActionInterval*)( CCSequence::create(action1, action2, action3, NULL ));
    CCAction*  rep1 = CCRepeatForever::create(seq);
    car->runAction( rep1 ); 

    // Set the Box2D vertices for the sprite (the collision area)
    int num = 8;
    b2Vec2 verts[] = {
        b2Vec2(6.0f / PTM_RATIO, 20.2f / PTM_RATIO),
        b2Vec2(-14.0f / PTM_RATIO, 20.8f / PTM_RATIO),
        b2Vec2(-30.2f / PTM_RATIO, 4.7f / PTM_RATIO),
        b2Vec2(-30.7f / PTM_RATIO, -4.2f / PTM_RATIO),
        b2Vec2(-19.5f / PTM_RATIO, -13.8f / PTM_RATIO),
        b2Vec2(19.8f / PTM_RATIO, -13.5f / PTM_RATIO),
        b2Vec2(30.0f / PTM_RATIO, -6.0f / PTM_RATIO),
        b2Vec2(29.8f / PTM_RATIO, 2.0f / PTM_RATIO)
    };
    CreateBox2DBodyForSprite( car, num, verts );       
    
    m_spriteSheet->addChild(car, 0, 2);        // Tag == 2 for a car
}

void HelloWorld::spawnCat()
{    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *cat = CCSprite::createWithSpriteFrameName("cat.png");
    
    int minY = cat->getContentSize().height/2;
    int maxY = winSize.height - (cat->getContentSize().height/2);
    int rangeY = maxY - minY;
    int actualY = rand() % rangeY;
    
    int startX = winSize.width + (cat->getContentSize().width/2);
    int endX = -(cat->getContentSize().width/2);
    
    CCPoint startPos = ccp(startX, actualY);
    CCPoint endPos = ccp(endX, actualY);
    
    cat->setPosition(startPos);
    
    CCFiniteTimeAction*  KittyAction = CCSequence::create(
        CCMoveTo::create(4, endPos),
        CCCallFuncN::create(this, callfuncN_selector(HelloWorld::spriteDone)),
        NULL);
    
    cat->runAction( KittyAction ); 

    // Set the Box2D vertices for the sprite (the collision area)
    int num = 8;
    b2Vec2 verts[] = {
        b2Vec2(25.7f / PTM_RATIO, 30.5f / PTM_RATIO),
        b2Vec2(-23.8f / PTM_RATIO, 31.0f / PTM_RATIO),
        b2Vec2(-29.8f / PTM_RATIO, 2.2f / PTM_RATIO),
        b2Vec2(-27.0f / PTM_RATIO, -12.5f / PTM_RATIO),
        b2Vec2(-9.3f / PTM_RATIO, -25.0f / PTM_RATIO),
        b2Vec2(9.7f / PTM_RATIO, -24.8f / PTM_RATIO),
        b2Vec2(26.2f / PTM_RATIO, -12.8f / PTM_RATIO),
        b2Vec2(29.7f / PTM_RATIO, 3.0f / PTM_RATIO)
    };
    CreateBox2DBodyForSprite( cat, num, verts );       
    
    m_spriteSheet->addChild(cat, 0, 1);            // Tag == 1 for a cat
}


