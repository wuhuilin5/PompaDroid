#ifndef  _ACTION_SPRITE_H_
#define  _ACTION_SPRITE_H_

#include "cocos2d.h"

namespace PompaDroid{
	//动作精灵的5种状态
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
		
		//动作状态
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _idleAction, IdleAction );
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _attackAction, AttackAction );
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _walkAction, WalkAction );
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _hurtAction, HurtAction );
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _knockoutAction, KnockOutAction );

		//精灵的当前状态
		CC_SYNTHESIZE( ActionState, _currentState, ActionState);

		CC_SYNTHESIZE( float, _velocity, Velocity );		//移动速度
		CC_SYNTHESIZE( cocos2d::Point, _direction, Direction );	//移动方向
		CC_SYNTHESIZE( unsigned int, _hp, HP );			//生命值
		CC_SYNTHESIZE( unsigned int, _atk, ATK );		//攻击力

	protected:
		static cocos2d::Animation* createAnimation( const char* fmt, int count, float fps );
			 
	private:
		bool changeState( ActionState state );
	};
}
#endif
