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

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("panda.plist");
	mPandaSprite = CPandaSprite::create();
	mPandaSprite->setPosition(Vec2(200, 180));
	mPandaSprite->setDesiredPosition(Vec2(200, 180));
	this->addChild(mPandaSprite);
	mPandaSprite->run();

	this->scheduleUpdate();
	return true;
}

void CGameLayer::onToucheBeganPoints( Vec2 v2 )
{
	if (v2.x > WINSIZE.width/2)
	{
		mPandaSprite->forwardMarch = true;
	}
	else
	{
		mPandaSprite->mightAsWellJump = true;
	}
}

void CGameLayer::onToucheMovePoints( Vec2 v2 )
{
	if (v2.x > WINSIZE.width/2)
	{
		mPandaSprite->forwardMarch = true;
	}
}

void CGameLayer::onToucheEndPoints( Vec2 v2 )
{
	mPandaSprite->forwardMarch = false;
	mPandaSprite->mightAsWellJump = false;
}

void CGameLayer::update( float dt )
{
	Layer::update(dt);
	checkForAndResolveCollisions(dt);

	Point pandaPoint = mPandaSprite->getPosition();
	Vec2 vec2 = Vec2(WINSIZE.width/2 - pandaPoint.x, WINSIZE.height/2 - pandaPoint.y);
	this->setPosition(vec2);

}

void CGameLayer::checkForAndResolveCollisions( float dt )
{
	vector<SurroundingTilesStruct> surroundingTiles = mTMXLayer->getSurroundingTilesAtPosition(mPandaSprite->getPosition());

	mPandaSprite->onGround = false;

	for (int i = 0; i < surroundingTiles.size(); i++)
	{
		Rect pRect = mPandaSprite->getCollisionBoundingBox();
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
					mPandaSprite->setDesiredPosition(Point(mPandaSprite->getDesiredPosition().x, 
						mPandaSprite->getDesiredPosition().y + intersection.size.height));
					mPandaSprite->onGround = true;
				}
			}
		}
	}
	mPandaSprite->setPosition(mPandaSprite->getDesiredPosition());
}
