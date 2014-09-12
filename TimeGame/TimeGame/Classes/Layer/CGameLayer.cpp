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

	mSpriteLayer = CSpriteLayer::create();
	this->addChild(mSpriteLayer);

	return true;
}

void CGameLayer::onTouchePoints( Vec2 v2 )
{
	Vec2 gameVec2 = this->getPosition();
	gameVec2.x += WINSIZE.width/2;
	gameVec2.y += WINSIZE.height/2;
	Vec2 vec2 = Vec2(gameVec2.x - v2.x, gameVec2.y - v2.y);

	this->runAction(CCSequence::create(MoveTo::create(0.1f, vec2), NULL));
}
