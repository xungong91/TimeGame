#ifndef _C_GAME_LAYER_H_
#define _C_GAME_LAYER_H_

#include "cocos2d.h"
#include "CTMXLayer.h"
#include "CSpriteLayer.h"

USING_NS_CC;

class CGameLayer : public Layer
{
public:
	CGameLayer();
	~CGameLayer();
	CREATE_FUNC(CGameLayer);
	bool init();

	void onTouchePoints(Vec2 v2);
private:
	CTMXLayer *mTMXLayer;
	CSpriteLayer *mSpriteLayer;
};
#endif