#ifndef _OPTION_DELEGATE_H_
#define _OPTION_DELEGATE_H_

#include "cocos2d.h"
#include "ActionSprite.h"

namespace PompaDroid
{
	class OptionDelegate:public cocos2d::Object
	{
	public:
		OptionDelegate();
		~OptionDelegate();
		
		virtual bool init();

		CREATE_FUNC( OptionDelegate );

		//移动，directoion为方向，distance是与起点的直线距离
		void onWalk( cocos2d::Point direction, float distance );

		//攻击
		void onAttack();
		
		//停止移动
		void onStop();

		CC_SYNTHESIZE_RETAIN( ActionSprite*, _target, Target );
	};
}

#endif