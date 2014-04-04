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

		virtual void idle();
		virtual void attack();
		virtual void knockout();
		virtual void walk( cocos2d::Point direction, float distance );
		virtual void hurt(int demage );

		//动作状态
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _idleAction, IdleAction );
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _attackAction, AttackAction );
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _walkAction, WalkAction );
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _hurtAction, HurtAction );
		CC_SYNTHESIZE_RETAIN( cocos2d::Action*, _knockoutAction, KnockOutAction );

		//精灵的当前状态
		CC_SYNTHESIZE( ActionState, _currentState, ActionState);

	protected:
		static cocos2d::Animation* createAnimation( const char* fmt, int count, float fps );
			 
	private:
		bool changeState( ActionState state );
	};
}
#endif
