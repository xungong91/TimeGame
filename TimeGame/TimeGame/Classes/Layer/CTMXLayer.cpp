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

Point CTMXLayer::getTileCoordForPosition( const Point &point )
{
	float x = floor(point.x / mTMXTiledMap->getTileSize().width);
	float levelHeightInPixels = mTMXTiledMap->getMapSize().height * mTMXTiledMap->getTileSize().height;
	float y = floor((levelHeightInPixels - point.y) / mTMXTiledMap->getTileSize().height);
	return Point(x, y);
}

Rect CTMXLayer::getTileRectFromTileCoords( const Point &point )
{
	float levelHeightInPixels = mTMXTiledMap->getMapSize().height * mTMXTiledMap->getTileSize().height;
	Point origin = Point(point.x * mTMXTiledMap->getTileSize().width, 
		levelHeightInPixels - ((point.y + 1) * mTMXTiledMap->getTileSize().height));
	return Rect(origin.x, origin.y, mTMXTiledMap->getTileSize().width, mTMXTiledMap->getTileSize().height);
}

