#include "CPandaSprite.h"
#include "Tools/CGameHelper.h"

USING_NS_CC;
using namespace std;

CPandaSprite::CPandaSprite() : 
	_runAction(NULL),
	_jumpAction(NULL),
	mVelocity(0.0f, 0.0f),
	mActionState(_ActionState::empty)
{

}

CPandaSprite::~CPandaSprite()
{
	CC_SAFE_RELEASE(_runAction);
	CC_SAFE_RELEASE(_jumpAction);
}

bool CPandaSprite::init()
{
	if (!Sprite::initWithSpriteFrameName("runPanda0.png"))
	{
		return false;
	}
	this->setAnchorPoint(Vec2(0.5f, 0));

	int i;
	//run animation
	{
		Vector<SpriteFrame*> runFrames;
		for (i = 0; i < 8; i++)
		{
			SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(
				CCString::createWithFormat("runPanda%d.png", i)->getCString());
			runFrames.pushBack(frame);
		}
		Animation *runAnimation = Animation::createWithSpriteFrames(runFrames, 0.06f);
		this->setRunAction(RepeatForever::create(Animate::create(runAnimation)));
	}
	//jump animation
	{
		Vector<SpriteFrame*> jumpFrames;
		for (i = 0; i < 8; i++)
		{
			SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(
				CCString::createWithFormat("jumpPanda%d.png", i)->getCString());
			jumpFrames.pushBack(frame);
		}
		Animation *jumpAnimation = Animation::createWithSpriteFrames(jumpFrames, 0.06f);
		this->setJumpAction(Sequence::create(Animate::create(jumpAnimation), NULL));
	}

	return true;
}

void CPandaSprite::onEnter()
{
	Sprite::onEnter();
	this->scheduleUpdate();
}

void CPandaSprite::onExit()
{
	Sprite::onExit();
}

void CPandaSprite::run()
{
	if (mActionState == _ActionState::jump || mActionState == _ActionState::empty)
	{
		this->stopAllActions();
		this->runAction(_runAction);
		mActionState = _ActionState::run;
	}
}

bool CPandaSprite::jump()
{
	if (mActionState == _ActionState::run)
	{
		this->stopAllActions();
		this->runAction(_jumpAction);
		mActionState = _ActionState::jump;
		return true;
	}
	return false;
}

void CPandaSprite::update( float dt )
{
	Sprite::update(dt);
	Point gravity = Point(0, -450);

	Point gravityStep = gravity * dt;

	mVelocity = mVelocity + gravityStep;
	Point stepVelocity = mVelocity * dt;

	if (onGround)
	{
		mVelocity = CCPoint(mVelocity.x, 0);
		stepVelocity = mVelocity * dt;
	}
	//this->setPosition(this->getPosition() + stepVelocity);
	mDesiredPosition = this->getPosition() + stepVelocity;
}

Rect CPandaSprite::getCollisionBoundingBox()
{
	Rect collisionBox = CGameHelper::getRectInset(this->boundingBox(), 5, 1);
	Point diff =  this->mDesiredPosition - this->getPosition();
	Rect returnBoundingBox = Rect(collisionBox.origin.x - diff.x, collisionBox.origin.y - diff.y, 
		collisionBox.size.width, collisionBox.size.height);
	return returnBoundingBox;
}
