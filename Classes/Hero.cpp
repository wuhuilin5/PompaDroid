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

			CallFunc *callbackIdle = CallFunc::create( std::bind( &Hero::idle, this ));

			//���ж��������ú󷴸�����
			Animation *idle = createAnimation( "hero_idle_%2d.png", 6, 12 );
			setIdleAction( RepeatForever::create( Animate::create( idle )));
		
			//�������߶���
			Animation *walk = createAnimation( "hero_walk_%2d.png", 8, 24 );
			setWalkAction( RepeatForever::create( Animate::create( walk )));

			//����������������ص�idle����
			Animation *attack = createAnimation( "hero_attack_%2d.png", 3, 12 );
			setAttackAction( Sequence::create( Animate::create( attack ), callbackIdle, NULL));

			//���˺�������������ص�idle����
			Animation *hurt = createAnimation( "hero_hurt_%2d.png", 3, 12 );
			setHurtAction( Sequence::create( Animate::create( hurt ), callbackIdle, NULL));

			//��ko������������ص�idle����
			Animation *knockout = createAnimation( "hero_attack_%2d.png", 3, 12 );
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
