#ifndef __CC_BUILDER_SCENE_H__
#define __CC_BUILDER_SCENE_H__

#include "cocos2d.h"

namespace PompaDroid
{
	class CCBuilderScene : public cocos2d::Scene
	{
	public:
		CCBuilderScene();
		~CCBuilderScene();

		bool init();

		CREATE_FUNC( CCBuilderScene );
		
		CC_SYNTHESIZE_RETAIN( Node*, _view, View );
	};
}
	
#endif