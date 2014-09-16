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
	//λ��
	CC_SYNTHESIZE(cocos2d::Vec2, mDesiredPosition, DesiredPosition);
	Rect getCollisionBoundingBox();

	virtual void update(float dt);

	bool onGround;	//�Ƿ�����
	bool forwardMarch; //�Ƿ�ǰ��
	bool mightAsWellJump;
private:
	//״̬
	_ActionState mActionState;
	//�ٶ�
	Point mVelocity;
};

#endif