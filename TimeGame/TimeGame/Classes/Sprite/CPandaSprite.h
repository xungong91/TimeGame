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
	CC_SYNTHESIZE(cocos2d::Vec2, _desiredPosition, DesiredPosition);

	virtual void update(float dt);
private:
	//×´Ì¬
	_ActionState mActionState;
	//ËÙ¶È
	Point mVelocity;
	//¿ò
	Rect mCollisionBoundingBox;
};

#endif