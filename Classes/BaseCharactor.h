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

		CC_SYNTHESIZE( cocos2d::Point, _velocity, Velocity );		//移动速度
		CC_SYNTHESIZE( cocos2d::Point, _direction, Direction );	//移动方向
		CC_SYNTHESIZE( unsigned int, _hp, HP );			//生命值
		CC_SYNTHESIZE( unsigned int, _atk, ATK );		//攻击力

	protected:

	};
}

#endif