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
	mHudLayer = CHudLayer::create();
	mHudLayer->OnTouchBeganCB = bind(&CGameLayer::onTouchePoints, this, std::placeholders::_1);
	this->addChild(mHudLayer);

	mTMXLayer = CTMXLayer::create();
	this->addChild(mTMXLayer);

	return true;
}

void CGameLayer::onTouchePoints( Vec2 v2 )
{
	Vec2 gameVec2 = this->getPosition();
	gameVec2.x += WINSIZE.width/2;
	gameVec2.y += WINSIZE.height/2;
	Vec2 vec2 = Vec2(gameVec2.x - v2.x, gameVec2.y - v2.y);

	Vec2 t1 = mTMXLayer->convertToNodeSpace(v2);
	Vec2 t2 = mTMXLayer->convertToWorldSpace(v2);


	Vec2 t3 = mHudLayer->convertToNodeSpace(v2);
	Vec2 t4 = mHudLayer->convertToWorldSpace(v2);

	this->runAction(CCSequence::create(MoveTo::create(0.1f, vec2), NULL));
}
