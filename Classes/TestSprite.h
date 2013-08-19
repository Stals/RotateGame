#pragma once
#include "cocos2d.h"
USING_NS_CC;

class TestSprite: public CCSprite{
public:
	TestSprite(){
		CCSprite::init();

		CCSprite* sprite = CCSprite::create("player.png");
		//this->setContentSize(sprite->getContentSize());
		this->addChild(sprite);	
		
	}
};

