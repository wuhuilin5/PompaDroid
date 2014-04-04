#ifndef _OPTION_DELEGATE_H_
#define _OPTION_DELEGATE_H_

#include "cocos2d.h"

namespace PompaDroid
{
	class ActionSprite;

	class OptionDelegate
	{
	public:
		OptionDelegate();
		~OptionDelegate();
		
		static OptionDelegate* create();

		//�ƶ���directoionΪ����distance��������ֱ�߾���
		void onWalk( cocos2d::Point direction, float distance );

		//����
		void onAttack();
		
		//ֹͣ�ƶ�
		void onStop();
	
		CC_SYNTHESIZE( ActionSprite*, _target, Target );
	};
}

#endif