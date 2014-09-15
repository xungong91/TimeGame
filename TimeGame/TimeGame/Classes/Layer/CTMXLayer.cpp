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

Rect CTMXLayer::getTileRectFromTilePoint( const Point &point )
{
	float levelHeightInPixels = mTMXTiledMap->getMapSize().height * mTMXTiledMap->getTileSize().height;
	Point origin = Point(point.x * mTMXTiledMap->getTileSize().width, 
		levelHeightInPixels - ((point.y + 1) * mTMXTiledMap->getTileSize().height));
	return Rect(origin.x, origin.y, mTMXTiledMap->getTileSize().width, mTMXTiledMap->getTileSize().height);
}

vector<SurroundingTilesStruct> CTMXLayer::getSurroundingTilesAtPosition( const Point &point )
{
	Point mainTilePoint = getTileCoordForPosition(point);
	vector<SurroundingTilesStruct> resultV;

	int data[9] = {4, 7, 1, 3, 5, 0, 2, 6, 8};

	for (int i = 0; i < 8; i++)
	{
		int c = data[i] % 3;
		int r = (int)(data[i] / 3);
		Point tilePoint = Point(mainTilePoint.x + c - 1, mainTilePoint.y + r - 1);
		TMXLayer *tmxlayer = mTMXTiledMap->getLayer("land");
		int gid = tmxlayer->getTileGIDAt(tilePoint);
		Rect tileRect = getTileRectFromTilePoint(tilePoint);

		SurroundingTilesStruct surroundingTile = {gid, tileRect, tilePoint};
		resultV.push_back(surroundingTile);
	}
	return resultV;
}

