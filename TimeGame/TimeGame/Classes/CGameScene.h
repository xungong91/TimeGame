#ifndef _C_GAME_SCENE_H_
#define _C_GAME_SCENE_H_

#include "cocos2d.h"

USING_NS_CC;

class CGameScene : public Scene
{
public:
	CGameScene();
	~CGameScene();
	CREATE_FUNC(CGameScene);
	bool init();
private:

};

#endif