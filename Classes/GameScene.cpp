#include "GameScene.h"
#include "GameLayer.h"
#include "OptionLayer.h"
#include "OptionDelegate.h"

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
			this->addChild( _gameLayer, 0 );

			_optionLayer = OptionLayer::create();
			this->addChild( _optionLayer );

			_optionDelegate = OptionDelegate::create();
			_optionDelegate->setTarget( _gameLayer->getHero());

			_optionLayer->setDelegator( _optionDelegate );

			ret = true;

		}while(0);

		return ret;
	}
}