#ifndef _C_SPRITE_LAYER_H_
#define _C_SPRITE_LAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class CSpriteLayer : public Layer
{
public:
	CSpriteLayer();
	~CSpriteLayer();
	CREATE_FUNC(CSpriteLayer);
	bool init();
private:

};
#endif