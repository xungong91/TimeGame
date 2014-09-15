#ifndef _C_TMX_LAYER_H_
#define _C_TMX_LAYER_H_

#include "cocos2d.h"
#include <vector>
#include <list>

USING_NS_CC;
using namespace std;

struct SurroundingTilesStruct
{
	int gid;
	Rect rect;
	Point tilePoint;
};

class CTMXLayer : public Layer
{
public:
	CTMXLayer();
	~CTMXLayer();
	CREATE_FUNC(CTMXLayer);
	bool init();
	Point getTileCoordForPosition(const Point &point);
	Rect getTileRectFromTilePoint(const Point &point);
	vector<SurroundingTilesStruct> getSurroundingTilesAtPosition(const Point &point);
private:
	TMXTiledMap *mTMXTiledMap;
};

#endif