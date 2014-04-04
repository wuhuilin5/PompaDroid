#ifndef __GAME_SCENE__
#define __GAME_SCENE__

#include "cocos2d.h"

namespace PompaDroid{
	class GameLayer;
	class OptionLayer;
	class OptionDelegate;

	class GameScene:public cocos2d::Scene
	{
	public:
		GameScene(void);
		~GameScene(void);

		virtual bool init();

		CREATE_FUNC(GameScene);
	
		//定义set/get方法
		CC_SYNTHESIZE( GameLayer*, _gameLayer, GameLayer );  
		CC_SYNTHESIZE( OptionLayer*, _optionLayer, OptionLayer );
		CC_SYNTHESIZE( OptionDelegate*, _optionDelegate, OptionDelegate );
	};
}

#endif

