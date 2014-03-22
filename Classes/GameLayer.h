#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"

namespace PompaDroid{
	class GameLayer : public cocos2d::Layer
	{
	public:
		GameLayer();
		~GameLayer();

		// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
		virtual bool init();  
    
		// implement the "static create()" method manually
		CREATE_FUNC(GameLayer);

	private:
		// init hero charactor
		void initHero();
		//init tile map
		void initTileMap();
	
		cocos2d::TMXTiledMap *_map;
	};
}

#endif // __HELLOWORLD_SCENE_H__
