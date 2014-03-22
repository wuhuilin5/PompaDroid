
#include "GameScene.h"
#include "GameLayer.h";

namespace PompaDroid{

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

bool GameScene::init()
{
	bool ret = false;

	do{
		CC_BREAK_IF(!Scene::init());

		_gameLayer = GameLayer::create();
		this->addChild( _gameLayer );

		ret = true;

	}while(0);

	return ret;
}

}