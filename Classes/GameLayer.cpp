#include "GameLayer.h"

USING_NS_CC;

namespace PompaDroid
{
	GameLayer::GameLayer()
	{
	}

	GameLayer::~GameLayer()
	{
	}

	bool GameLayer::init()
	{
		bool ret = false;

		do{
			CC_BREAK_IF(!Layer::init());

			initTileMap();
			initHero();

			ret = true;
		}while(0);
	
		return ret;
	}

	void GameLayer::initHero()
	{
	}

	void GameLayer::initTileMap()
	{
		_map = CCTMXTiledMap::create("pd_tilemap.tmx");
		this->addChild( _map );
	}
}