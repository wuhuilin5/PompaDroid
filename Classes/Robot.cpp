#include "Robot.h"
#include "cocos2d.h"

USING_NS_CC;

namespace PompaDroid
{
	Robot::Robot()
	{
	}

	Robot::~Robot()
	{
	}

	bool Robot::init()
	{
		/*initWithSpriteFrameName( "robot_idle_00.png" );
		return true;*/

		bool ret = false;

		do{
			CC_BREAK_IF( !ActionSprite::initWithSpriteFrameName( "robot_idle_00.png" )); 

			CallFunc* callbackIdle = CallFunc::create( std::bind( &Robot::idle, this ));

			//���ж��������ú󷴸�����
			Animation* idle = ActionSprite::createAnimation( "robot_idle_%02d.png", 5, 12.f );
			setIdleAction( RepeatForever::create( Animate::create( idle )));
			
			//�������߶���
			Animation* walk = ActionSprite::createAnimation( "robot_walk_%02d.png", 6, 20 );
			setWalkAction( RepeatForever::create( Animate::create( walk )));

			//����������������ص�idle����
			Animation* attack = ActionSprite::createAnimation( "robot_attack_%02d.png", 5, 12.f );
			setAttackAction( Sequence::create( Animate::create( attack ), callbackIdle, NULL));

			//���˺�������������ص�idle����
			Animation* hurt = ActionSprite::createAnimation( "robot_hurt_%02d.png", 3, 12.f );
			setHurtAction( Sequence::create( Animate::create( hurt ), callbackIdle, NULL));

			//��ko������������ص�idle����
			Animation* knockout = ActionSprite::createAnimation( "robot_knockout_%02d.png", 5, 12.f );
			setKnockOutAction( Sequence::create( Animate::create( knockout ), NULL ));

			setATK(20);  //������
			setHP(100);		//����ֵ
			setDirection(Point::ZERO);

			ret = true;

		}while(0);

		return ret;
	}
}
