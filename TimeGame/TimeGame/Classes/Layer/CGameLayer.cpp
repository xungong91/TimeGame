#include "CGameLayer.h"
#include "Defines.h"
#include "Tools/CGameHelper.h"

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

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("dude.plist");
	mHero = CHeroSprite::create();
	mHero->setPosition(Vec2(200, 180));
	mHero->setDesiredPosition(Vec2(200, 180));
	this->addChild(mHero);
	mHero->run();

	this->scheduleUpdate();
	return true;
}

void CGameLayer::onToucheBeganPoints( Vec2 v2 )
{
	if (v2.x > WINSIZE.width/2)
	{
		mHero->forwardMarch = true;
	}
	else
	{
		mHero->mightAsWellJump = true;
	}

}

void CGameLayer::onToucheMovePoints( Vec2 v2 )
{
	if (v2.x > WINSIZE.width/2)
	{
		mHero->forwardMarch = true;
	}
}

void CGameLayer::onToucheEndPoints( Vec2 v2 )
{
	mHero->forwardMarch = false;
	mHero->mightAsWellJump = false;
}

void CGameLayer::update( float dt )
{
	Layer::update(dt);
	checkForAndResolveCollisions(dt);

	Point pandaPoint = mHero->getPosition();
	Vec2 vec2 = Vec2(WINSIZE.width/2 - pandaPoint.x, WINSIZE.height/2 - pandaPoint.y);
	this->setPosition(vec2);

}

void CGameLayer::checkForAndResolveCollisions( float dt )
{
	vector<SurroundingTilesStruct> surroundingTiles = mTMXLayer->getSurroundingTilesAtPosition(mHero->getPosition());

	mHero->onGround = false;

	for (int i = 0; i < surroundingTiles.size(); i++)
	{
		Rect pRect = mHero->getCollisionBoundingBox();
		int gid = surroundingTiles[i].gid;
		if (gid != 0)
		{
			Rect tileRect = surroundingTiles[i].rect;
			if (pRect.intersectsRect(tileRect))
			{
				Rect intersection = CGameHelper::getRectIntersection(pRect, tileRect);
				if (i == 0) 
				{
					//tile is directly below panda
					mHero->setDesiredPosition(Point(mHero->getDesiredPosition().x, 
						mHero->getDesiredPosition().y + intersection.size.height));
					mHero->onGround = true;
				}
			}
		}
	}
	mHero->setPosition(mHero->getDesiredPosition());
}
