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

		//�ƶ���directoionΪ����distance��������ֱ�߾���
		void onWalk( cocos2d::Point direction, float distance );

		//����
		void onAttack();
		
		//ֹͣ�ƶ�
		void onStop();

		CC_SYNTHESIZE_RETAIN( ActionSprite*, _target, Target );
	};
}

#endif