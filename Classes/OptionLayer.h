#ifndef __OPTION_LAYER_H__
#define __OPTION_LAYER_H__

#include "cocos2d.h"

namespace PompaDroid{
	class OptionLayer:public cocos2d::Layer
	{
	public:
		OptionLayer(void);
		~OptionLayer(void);

		virtual bool init();

		CREATE_FUNC(OptionLayer);
	};
}

#endif
