#include "GameLayer.h"
#include "Hero.h"
#include "Robot.h"

USING_NS_CC;

namespace PompaDroid
{
	class ActionSprite;

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
		/*	_actor = SpriteBatchNode::create( "pd_sprites.pvr.ccz" );
			_actor->setPosition( 0, 0 );
			this->addChild( _actor );*/

			initTileMap();
			initHero();
			initRobots();

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
		this->addChild( _map, 0 );
	}

	void GameLayer::initRobots()
	{
		int count = 5;
		for( int i = 0; i < count; i++ )
		{
			ActionSprite* robot = Robot::create();
			robot->setPosition( CCRANDOM_0_1()*400, CCRANDOM_0_1()*150 );
			robot->idle();
			//_actor->addChild( robot ); //添加到SpriteBatchNode，没有显示出来，为何？
			this->addChild( robot );
			_robots.pushBack( robot );
		}
	}
}