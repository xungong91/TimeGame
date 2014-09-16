#ifndef _C_PANDA_SPRITE_H_
#define _C_PANDA_SPRITE_H_

#include "cocos2d.h"
#include "Defines.h"

USING_NS_CC;

class CPandaSprite : public cocos2d::Sprite
{
public:
	CPandaSprite();
	~CPandaSprite();
	CREATE_FUNC(CPandaSprite);
	bool init();
	virtual void onEnter();
	virtual void onExit();

	void run();
	bool jump();

	CC_SYNTHESIZE_RETAIN(cocos2d::Action*, _runAction, RunAction);
	CC_SYNTHESIZE_RETAIN(cocos2d::Action*, _jumpAction, JumpAction);
	//位置
	CC_SYNTHESIZE(cocos2d::Vec2, mDesiredPosition, DesiredPosition);
	Rect getCollisionBoundingBox();

	virtual void update(float dt);

	bool onGround;	//是否下落
	bool forwardMarch; //是否前进
	bool mightAsWellJump;
private:
	//状态
	_ActionState mActionState;
	//速度
	Point mVelocity;
};

#endif