#include "OptionLayer.h"

namespace PompaDroid{
	OptionLayer::OptionLayer()
	{
	}

	OptionLayer::~OptionLayer()
	{
	}

	bool OptionLayer::init()
	{
		bool ret = false;

		do{
			_joystick = Sprite::create("CloseNormal.png");
			this->addChild( _joystick );
			_joystick_bg = Sprite::create("CloseNormal.png");
			this->addChild( _joystick_bg );
		
			setTouchEnabled(true);
	
			ret = true;
		}while(0);

		return ret;

	}

	void OptionLayer::onTouchesBegan( cocos2d::Vector<cocos2d::Touch*>& touch, cocos2d::Event* e )
	{

	}

	void OptionLayer::onTouchesMoved( cocos2d::Vector<cocos2d::Touch*>& touch, cocos2d::Event* e )
	{

	}

	void OptionLayer::onTouchesEnded( cocos2d::Vector<cocos2d::Touch*>& touch, cocos2d::Event* e )
	{

	}

	void OptionLayer::activityJoystick( cocos2d::Point position )
	{
		_joystick->setPosition( position );
		_joystick->setVisible( true );

		_joystick_bg->setPosition( position );
		_joystick_bg->setVisible( true );
	}

	void OptionLayer::inActivityJoystick()
	{
		_joystick->setPosition( _joystick_bg->getPosition());
		_joystick->setVisible(false);
		_joystick_bg->setVisible(false);
	}
	
	void OptionLayer::updateJoystick( cocos2d::Point direction, float distance )
	{
		Point start = _joystick_bg->getPosition();
		float dis = distance;
		if( dis <= 32 ) dis = distance;
		else if( dis >= 96 ) dis = 64;
		else dis = 32;

		_joystick->setPosition( start+( direction*dis));
	}
}