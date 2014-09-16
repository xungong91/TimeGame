#include "CHudLayer.h"

USING_NS_CC;

CHudLayer::CHudLayer()
{

}

CHudLayer::~CHudLayer()
{

}

bool CHudLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(CHudLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(CHudLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(CHudLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void CHudLayer::onEnter()
{
	Layer::onEnter();
}

void CHudLayer::onExit()
{
	Layer::onExit();
}

bool CHudLayer::onTouchBegan( Touch *touch, Event *unused_event )
{
	Vec2 point = touch->getLocation();

	OnTouchBeganCB(point);
	return true;
}

void CHudLayer::onTouchMoved( Touch *touch, Event *unused_event )
{
	Vec2 point = touch->getLocation();

	OnTouchMoveCB(point);
}

void CHudLayer::onTouchEnded( Touch *touch, Event *unused_event )
{
	Vec2 point = touch->getLocation();

	OnTouchEndCB(point);
}
