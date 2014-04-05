#include "OptionDelegate.h"
#include "ActionSprite.h"

namespace PompaDroid
{
	OptionDelegate::OptionDelegate():_target(nullptr)
	{
	}

	OptionDelegate::~OptionDelegate()
	{
		CC_SAFE_RELEASE(_target);
	}

	bool OptionDelegate::init()
	{
		return true;
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