#ifndef _C_GAME_LAYER_H_
#define _C_GAME_LAYER_H_

#include "cocos2d.h"
#include "CTMXLayer.h"
#include "Sprite/CPandaSprite.h"

USING_NS_CC;

class CGameLayer : public Layer
{
public:
	CGameLayer();
	~CGameLayer();
	CREATE_FUNC(CGameLayer);
	bool init();

	void onTouchePoints(Vec2 v2);

	void update(float dt);
	void checkForAndResolveCollisions(float dt);
private:
	CTMXLayer *mTMXLayer;
	CPandaSprite *mPandaSprite;
};
#endif