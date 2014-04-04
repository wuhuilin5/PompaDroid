#include "BaseCharactor.h"

namespace PompaDroid
{
	BaseCharactor::BaseCharactor(){}
	BaseCharactor::~BaseCharactor(){}

	void BaseCharactor::idle()
	{
		ActionSprite::idle();
	}

	void BaseCharactor::attack()
	{
		ActionSprite::attack();
	}

	void BaseCharactor::knockout()
	{
		ActionSprite::knockout();
	}

	void BaseCharactor::walk( cocos2d::Point direction, float distance )
	{
		ActionSprite::walk( direction, distance );

		setFlippedX( direction.x < 0 ? true : false );
		_velocity = direction*(distance < 96 ? 1: 2 );

		update();
	}

	void BaseCharactor::hurt(int demage )
	{
		ActionSprite::hurt( demage );

		_hp -= demage;
			
		if( _hp <= 0 ){
			_hp = 0;
			knockout();
		}
	}

	void BaseCharactor::update()
	{
		if( this->getActionState() == ActionState::ACTION_STATE_WALK ){
			this->setPosition(this->getPosition()+ _velocity );
		}
	}
}
