#ifndef _C_HUD_LAYER_H_
#define _C_HUD_LAYER_H_

#include "cocos2d.h"
#include <functional>

using namespace std;
USING_NS_CC;

class CHudLayer : public cocos2d::Layer
{
public:
	CHudLayer();
	~CHudLayer();
	CREATE_FUNC(CHudLayer);
	bool init();

	virtual bool onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *unused_event );
	virtual void onEnter();
	virtual void onExit();

	function<void (Vec2 v2)> OnTouchBeganCB;
private:
};

#endif