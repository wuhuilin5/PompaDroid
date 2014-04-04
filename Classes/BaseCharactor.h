#ifndef __BASE_CHARACTOR__
#define __BASE_CHARACTOR__

#include "ActionSprite.h"

namespace PompaDroid
{
	class BaseCharactor: public ActionSprite
	{
	public:
		BaseCharactor();
		~BaseCharactor();

		virtual void idle();
		virtual void attack();
		virtual void knockout();
		virtual void walk( cocos2d::Point direction, float distance );
		virtual void hurt(int demage );

		void update();

		CC_SYNTHESIZE( cocos2d::Point, _velocity, Velocity );		//�ƶ��ٶ�
		CC_SYNTHESIZE( cocos2d::Point, _direction, Direction );	//�ƶ�����
		CC_SYNTHESIZE( unsigned int, _hp, HP );			//����ֵ
		CC_SYNTHESIZE( unsigned int, _atk, ATK );		//������

	protected:

	};
}

#endif