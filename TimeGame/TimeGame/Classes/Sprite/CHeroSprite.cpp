#include "CheroSprite.h"
#include "Tools/CGameHelper.h"

USING_NS_CC;
using namespace std;

CHeroSprite::CHeroSprite() : 
	_runAction(NULL),
	_jumpAction(NULL),
	mVelocity(0.0f, 0.0f),
	mActionState(_ActionState::empty),
	mightAsWellJump(false),
	forwardMarch(false)
{

}

CHeroSprite::~CHeroSprite()
{
	CC_SAFE_RELEASE(_runAction);
	CC_SAFE_RELEASE(_jumpAction);
}

bool CHeroSprite::init()
{
	if (!Sprite::initWithSpriteFrameName("idle0.png"))
	{
		return false;
	}
	this->setAnchorPoint(Vec2(0.5f, 0));

	int i;
	//run animation
	{
		Vector<SpriteFrame*> runFrames;
		for (i = 0; i < 22; i++)
		{
			SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(
				CCString::createWithFormat("idle%d.png", i)->getCString());
			runFrames.pushBack(frame);
		}
		Animation *runAnimation = Animation::createWithSpriteFrames(runFrames, 0.06f);
		this->setRunAction(RepeatForever::create(Animate::create(runAnimation)));
	}
	//jump animation
	{
		Vector<SpriteFrame*> jumpFrames;
		for (i = 0; i < 5; i++)
		{
			SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(
				CCString::createWithFormat("jump_prep_straight%d.png", i)->getCString());
			jumpFrames.pushBack(frame);
		}
		Animation *jumpAnimation = Animation::createWithSpriteFrames(jumpFrames, 0.06f);
		this->setJumpAction(Sequence::create(Animate::create(jumpAnimation), NULL));
	}

	return true;
}

void CHeroSprite::onEnter()
{
	Sprite::onEnter();
	this->scheduleUpdate();
}

void CHeroSprite::onExit()
{
	Sprite::onExit();
}

void CHeroSprite::run()
{
	if (mActionState == _ActionState::jump || mActionState == _ActionState::empty)
	{
		this->stopAllActions();
		this->runAction(_runAction);
		mActionState = _ActionState::run;
	}
}

bool CHeroSprite::jump()
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

void CHeroSprite::update( float dt )
{
	Sprite::update(dt);
	Point gravity = Point(0.0, -450.0);
	Point gravityStep = gravity * dt;

	Point forwardMove = Point(800.0, 0.0);
	Point forwardStep = forwardMove * dt; //1

	mVelocity = ccpAdd(mVelocity, gravityStep);
	mVelocity = Point(mVelocity.x * 0.90, mVelocity.y); //2

	Point jumpForce = Point(0.0,
		310.0);

	if (mightAsWellJump && onGround) {
		mVelocity = mVelocity + jumpForce;
	}

	if (forwardMarch) {
		mVelocity = mVelocity + forwardStep;
	} //3

	Point minMovement = Point(0.0, -450.0);
	Point maxMovement = Point(120.0, 250.0);
	mVelocity = ccpClamp(mVelocity, minMovement, maxMovement); //4

	Point stepVelocity = mVelocity * dt;

	//this->setPosition(this->getPosition() + stepVelocity);
	mDesiredPosition = this->getPosition() + stepVelocity;
}

Rect CHeroSprite::getCollisionBoundingBox()
{
	Rect collisionBox = CGameHelper::getRectInset(this->boundingBox(), 5, 1);
	Point diff =  this->mDesiredPosition - this->getPosition();
	Rect returnBoundingBox = Rect(collisionBox.origin.x - diff.x, collisionBox.origin.y - diff.y, 
		collisionBox.size.width, collisionBox.size.height);
	return returnBoundingBox;
}
