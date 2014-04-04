#include "OptionLayer.h"
#include "OptionDelegate.h"

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
		
			inActivityJoystick();
			
			auto dispatcher = Director::getInstance()->getEventDispatcher();
			auto listener = EventListenerTouchOneByOne::create();
			listener->setSwallowTouches( true);

			listener->onTouchBegan = CC_CALLBACK_2( OptionLayer::onTouchBegan, this ); //std::bind( &OptionLayer::onTouchBegan, this, std::placeholders::_1, std::placeholders::_2); 
			listener->onTouchMoved = CC_CALLBACK_2( OptionLayer::onTouchMoved, this );
			listener->onTouchEnded = CC_CALLBACK_2( OptionLayer::onTouchEnded, this );

			dispatcher->addEventListenerWithSceneGraphPriority( listener, this );
		
			ret = true;
		}while(0);

		return ret;
	}

	bool OptionLayer::onTouchBegan( Touch* touch, Event* e )
	{
		Size winSize = Director::getInstance()->getWinSize();
		Point pt = touch->getLocation();

		if( pt.x <= (winSize.width/2)){
			activityJoystick( pt );
		}else{
			_delegator->onAttack();
		}
	
		return true;
	}

	void OptionLayer::onTouchMoved( Touch* touch, Event* e )
	{
		Size winSize = Director::getInstance()->getWinSize();

		Point start = touch->getStartLocation();
		Point pt = touch->getLocation();

		float distance = start.getDistance(pt);
		Point direction = (pt-start).normalize();

		if( start.x >= winSize.width/2){
			_delegator->onWalk( direction, distance );
		}else{
			updateJoystick( direction, distance );
		}
	}

	void OptionLayer::onTouchEnded( Touch* touch, Event* e )
	{
		Size winSize = Director::getInstance()->getWinSize();

		Point start = touch->getStartLocation();
		if( start.x >= winSize.width/2 ){
			_delegator->onStop();
		}else{
			inActivityJoystick();
		}
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
		//else if( dis >= 64 ) dis = 64;
		else dis = 32;

		_joystick->setPosition( start+( direction*dis));
	}
}