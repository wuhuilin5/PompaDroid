#ifndef __OPTION_LAYER_H__
#define __OPTION_LAYER_H__

#include "cocos2d.h"
USING_NS_CC;

namespace PompaDroid{
	class OptionDelegate;

	class OptionLayer:public cocos2d::Layer
	{
	public:
		OptionLayer(void);
		~OptionLayer(void);

		virtual bool init();

		CREATE_FUNC(OptionLayer);
		
		//触控的三个事件重载
		void onTouchesBegan( cocos2d::Vector<cocos2d::Touch*>& touch, cocos2d::Event* e );
		void onTouchesMoved( cocos2d::Vector<cocos2d::Touch*>& touch, cocos2d::Event* e );
		void onTouchesEnded( cocos2d::Vector<cocos2d::Touch*>& touch, cocos2d::Event* e );

		CC_SYNTHESIZE( OptionDelegate*, _delegator, Delegator );

	private:
		cocos2d::Sprite* _joystick;
		cocos2d::Sprite* _joystick_bg;

		//激活摇杆精灵，并更新坐标
		void activityJoystick( cocos2d::Point position );
		//隐藏摇杆精灵，并将摇杆置于置座中心
		void inActivityJoystick();
		//刷新摇杆相对于基座的位置
		void updateJoystick( cocos2d::Point direction, float distance );
	};
}

#endif
