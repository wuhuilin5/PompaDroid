#ifndef  _HERO_H_
#define  _HERO_H_

#include "ActionSprite.h"
#include "cocos2d.h"

#pragma comment(lib, "winmm.lib")

namespace PompaDroid
{
	class Hero:public ActionSprite
	{
	public:
		 Hero();
		~ Hero();

		bool init();
		CREATE_FUNC( Hero );
	};
}

#endif