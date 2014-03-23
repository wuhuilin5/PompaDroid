#include "Hero.h"
#include "cocos2d.h"

USING_NS_CC;

namespace PompaDroid
{
	Hero::Hero()
	{
	}

	Hero::~Hero()
	{
	}

	bool Hero::init()
	{
		bool ret = false;

		do{
			CC_BREAK_IF( !ActionSprite::initWithSpriteFrameName( "hero_idle_00.png" )); 

			CallFunc* callbackIdle = CallFunc::create( std::bind( &Hero::idle, this ));

			//空闲动画，调用后反复播放
			Animation* idle = ActionSprite::createAnimation( "hero_idle_%02d.png", 6, 12.f );
			setIdleAction( RepeatForever::create( Animate::create( idle )));
			
			//创建行走动画
			Animation* walk = ActionSprite::createAnimation( "hero_walk_%02d.png", 8, 24.f );
			setWalkAction( RepeatForever::create( Animate::create( walk )));

			//攻击动画，播放完回调idle动画
			Animation* attack = ActionSprite::createAnimation( "hero_attack_00_%02d.png", 3, 12.f );
			setAttackAction( Sequence::create( Animate::create( attack ), callbackIdle, NULL));

			//受伤害动画，播放完回调idle动画
			Animation* hurt = ActionSprite::createAnimation( "hero_hurt_%02d.png", 3, 12.f );
			setHurtAction( Sequence::create( Animate::create( hurt ), callbackIdle, NULL));

			//被ko动画，播放完回调idle动画
			Animation* knockout = ActionSprite::createAnimation( "hero_knockout_%02d.png", 5, 12.f );
			setKnockOutAction( Sequence::create( Animate::create( knockout ), NULL ));

			setATK(20);
			setHP(100);
			setVelocity(1);
			setDirection(Point::ZERO);

			ret = true;

		}while(0);

		return ret;
	}
}
