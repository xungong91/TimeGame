#include "CTMXLayer.h"

CTMXLayer::CTMXLayer() : mTMXTiledMap(NULL)
{

}

CTMXLayer::~CTMXLayer()
{

}

bool CTMXLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	mTMXTiledMap = CCTMXTiledMap::create("1_1.tmx");  
	addChild(mTMXTiledMap);  

	return true;
}

