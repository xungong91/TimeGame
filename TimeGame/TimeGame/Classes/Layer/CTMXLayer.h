#ifndef _C_TMX_LAYER_H_
#define _C_TMX_LAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class CTMXLayer : public Layer
{
public:
	CTMXLayer();
	~CTMXLayer();
	CREATE_FUNC(CTMXLayer);
	bool init();
private:
	TMXTiledMap *mTMXTiledMap;
};

#endif