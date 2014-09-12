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

	mTMXTiledMap = CCTMXTiledMap::create("test.tmx");  
	addChild(mTMXTiledMap);  


	return true;
}

