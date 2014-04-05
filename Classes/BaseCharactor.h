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

		virtual void idle() override;
		virtual void attack() override;
		virtual void knockout() override;
		virtual void walk( cocos2d::Point direction, float distance ) override;
		virtual void hurt(int demage ) override;

		void update();

		CC_SYNTHESIZE( cocos2d::Point, _velocity, Velocity );		//�ƶ��ٶ�
		CC_SYNTHESIZE( cocos2d::Point, _direction, Direction );	//�ƶ�����
		CC_SYNTHESIZE( unsigned int, _hp, HP );			//����ֵ
		CC_SYNTHESIZE( unsigned int, _atk, ATK );		//������

	protected:

	};
}

#endif