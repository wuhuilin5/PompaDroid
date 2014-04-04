#include "ActionSprite.h"
#include "CCGeometry.h"

USING_NS_CC;

namespace PompaDroid
{
	ActionSprite::ActionSprite():
	_attackAction(NULL),
	_hurtAction(NULL),
	_idleAction(NULL),
	_knockoutAction(NULL),
	_walkAction(NULL)
	{
	}

	ActionSprite::~ActionSprite()
	{
	}

	void ActionSprite::attack()
	{
		if( changeState( ActionState::ACTION_STATE_ATTACK )){
			this->runAction( _attackAction );
		}
	}

	void ActionSprite::idle()
	{
		if( changeState( ActionState::ACTION_STATE_IDLE )){
			this->runAction( _idleAction );
		}
	}

	void ActionSprite::walk( cocos2d::Point direction, float distance )
	{
		if( changeState(ActionState::ACTION_STATE_WALK)){
			this->runAction(_walkAction);
		}
	}

	void ActionSprite::hurt( int demage )
	{
		if( changeState(ActionState::ACTION_STATE_HURT )){
			this->runAction(_hurtAction );
		}
	}

	void ActionSprite::knockout()
	{
		if( changeState(ActionState::ACTION_STATE_KNOCKOUT )){
			this->runAction( _knockoutAction );
		}
	}

	bool ActionSprite::changeState( ActionState state )
	{
		bool ret = false;

		if( _currentState == ActionState::ACTION_STATE_KNOCKOUT || _currentState == state )
			ret = false;
		else{
			this->stopAllActions();  
			_currentState = state;
			ret = true;
		}

		return ret;
	}

	cocos2d::Animation* ActionSprite::createAnimation( const char* fmt, int count, float fps )
	{
		cocos2d::Vector<cocos2d::SpriteFrame*> frames;

		for( int i = 0; i < count; i++ )
		{
			const char *png = String::createWithFormat( fmt, i )->getCString();
			cocos2d::SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(png);

			frames.pushBack( frame );
		}

		return Animation::createWithSpriteFrames( frames, 1/fps);
	}
}