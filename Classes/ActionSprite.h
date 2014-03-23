#ifndef  _ACTION_SPRITE_H_
#define  _ACTION_SPRITE_H_

#include "cocos2d.h"

namespace PompaDroid{
	//���������5��״̬
	typedef enum{
		ACTION_STATE_NONE = 0,
		ACTION_STATE_IDLE,
		ACTION_STATE_WALK,
		ACTION_STATE_ATTACK,
		ACTION_STATE_HURT,
		ACTION_STATE_KNOCKOUT,
	} ActionState;

	class ActionSprite :public cocos2d::Sprite
	{
	public:
		ActionSprite();
		~ActionSprite();

		void idle();
		void walk( cocos2d::Point direction );
		void attack();
		void hurt(int demage );
		void knockout();
		
		//����״̬
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _idleAction, IdleAction );
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _attackAction, AttackAction );
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _walkAction, WalkAction );
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _hurtAction, HurtAction );
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _knockoutAction, KnockOutAction );

		//����ĵ�ǰ״̬
		CC_SYNTHESIZE( ActionState, _currentState, ActionState);

		CC_SYNTHESIZE( float, _velocity, Velocity );		//�ƶ��ٶ�
		CC_SYNTHESIZE( cocos2d::Point, _direction, Direction );	//�ƶ�����
		CC_SYNTHESIZE( unsigned int, _hp, HP );			//����ֵ
		CC_SYNTHESIZE( unsigned int, _atk, ATK );		//������

	protected:
		static cocos2d::Animation* createAnimation( const char* fmt, int count, float fps );
			 
	private:
		bool changeState( ActionState state );
	};
}
#endif
