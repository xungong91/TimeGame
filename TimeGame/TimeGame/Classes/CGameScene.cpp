#include "CGameScene.h"
#include "Layer/CGameLayer.h"
#include "Layer/CHudLayer.h"

CGameScene::CGameScene()
{

}

CGameScene::~CGameScene()
{

}

bool CGameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	CGameLayer *gameLayer = CGameLayer::create();
	this->addChild(gameLayer);

	CHudLayer *hudLayer = CHudLayer::create();
	hudLayer->OnTouchBeganCB = bind(&CGameLayer::onToucheBeganPoints, gameLayer, std::placeholders::_1);
	hudLayer->OnTouchMoveCB = bind(&CGameLayer::onToucheMovePoints, gameLayer, std::placeholders::_1);
	hudLayer->OnTouchEndCB = bind(&CGameLayer::onToucheEndPoints, gameLayer, std::placeholders::_1);
	this->addChild(hudLayer);

	return true;
}

