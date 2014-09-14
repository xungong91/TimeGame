#include "CGameLayer.h"
#include "Defines.h"

CGameLayer::CGameLayer()
{

}

CGameLayer::~CGameLayer()
{

}

bool CGameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	mTMXLayer = CTMXLayer::create();
	this->addChild(mTMXLayer);

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("panda.plist");
	mPandaSprite = CPandaSprite::create();
	this->addChild(mPandaSprite);
	mPandaSprite->run();

	this->scheduleUpdate();
	return true;
}

void CGameLayer::onTouchePoints( Vec2 v2 )
{
	if (v2.x > WINSIZE.width/2)
	{
		mPandaSprite->jump();
	}
}

void CGameLayer::update( float dt )
{
	Layer::update(dt);

	Point pandaPoint = mPandaSprite->getPosition();
	Vec2 vec2 = Vec2(WINSIZE.width/2 - pandaPoint.x, WINSIZE.height/2 - pandaPoint.y);
	this->setPosition(vec2);
}
