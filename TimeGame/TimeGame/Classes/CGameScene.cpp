#include "CGameScene.h"
#include "Layer/CGameLayer.h"

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

	return true;
}

