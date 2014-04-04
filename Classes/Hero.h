#ifndef  _HERO_H_
#define  _HERO_H_

#include "BaseCharactor.h"
#include "cocos2d.h"

namespace PompaDroid
{
	class Hero:public BaseCharactor
	{
	public:
		 Hero();
		~ Hero();

		bool init();
		CREATE_FUNC( Hero );
	};
}

#endif