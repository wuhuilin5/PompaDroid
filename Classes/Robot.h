#ifndef  _ROBOT_H_
#define  _ROBOT_H_

#include "ActionSprite.h"
#include "cocos2d.h"

namespace PompaDroid
{
	class Robot:public ActionSprite
	{
	public:
		 Robot();
		~ Robot();

		bool init();
		CREATE_FUNC( Robot );   //Static Rebot* create(); || init
	};
}

#endif