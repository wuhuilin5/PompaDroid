#include "GameLayer.h"
#include "Hero.h"
#include "ActionSprite.h"

USING_NS_CC;

namespace PompaDroid
{
	GameLayer::GameLayer():
	_actor(nullptr)
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

			SpriteFrameCache::getInstance()->addSpriteFramesWithFile( "pd_sprites.plist" );
			_actor = SpriteBatchNode::create( "pd_sprites.pvr.ccz" );
			this->addChild( _actor );

			initTileMap();
			initHero();

			ret = true;
		}while(0);
	
		return ret;
	}

	void GameLayer::initHero()
	{
		_hero = Hero::create();
		_hero->setPosition(80,80);
		_hero->idle();

		this->addChild(_hero);
	}

	void GameLayer::initTileMap()
	{
		_map = TMXTiledMap::create("pd_tilemap.tmx");
		this->addChild( _map );
	}
}