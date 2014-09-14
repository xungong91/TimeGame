#include "CSpriteLayer.h"

CSpriteLayer::CSpriteLayer()
{

}

CSpriteLayer::~CSpriteLayer()
{

}

bool CSpriteLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	mPandaSprite = CPandaSprite::create();
	this->addChild(mPandaSprite);

	return true;
}

