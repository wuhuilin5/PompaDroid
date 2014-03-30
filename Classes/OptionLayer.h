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
		
		//���ص������¼�����
		bool onTouchBegan(Touch *touch, Event *unused_event); 
		void onTouchMoved(Touch *touch, Event *unused_event); 
		void onTouchEnded(Touch *touch, Event *unused_event); 
  
		CC_SYNTHESIZE( OptionDelegate*, _delegator, Delegator );

	private:
		cocos2d::Sprite* _joystick;
		cocos2d::Sprite* _joystick_bg;

		//����ҡ�˾��飬����������
		void activityJoystick( cocos2d::Point position );
		//����ҡ�˾��飬����ҡ��������������
		void inActivityJoystick();
		//ˢ��ҡ������ڻ�����λ��
		void updateJoystick( cocos2d::Point direction, float distance );
	};
}

#endif
