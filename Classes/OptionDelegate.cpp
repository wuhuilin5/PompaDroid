#include "OptionDelegate.h"
#include "ActionSprite.h"

namespace PompaDroid
{
	OptionDelegate::OptionDelegate()
	{
	}

	OptionDelegate::~OptionDelegate()
	{
		setTarget( nullptr );
	}

	OptionDelegate* OptionDelegate::create()
	{
		return new OptionDelegate();
	}

	void OptionDelegate::onWalk( cocos2d::Point direction, float distance )
	{
		_target->walk( direction, distance );
	}

	void OptionDelegate::onAttack()
	{
		_target->attack();
	}

	void OptionDelegate::onStop()
	{
		_target->idle();
	}
}