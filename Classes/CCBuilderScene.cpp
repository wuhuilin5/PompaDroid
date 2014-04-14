
#include "CCBuilderScene.h"
#include "cocosbuilder\CocosBuilder.h"

using namespace cocosbuilder;
USING_NS_CC;

namespace PompaDroid
{
	CCBuilderScene::CCBuilderScene():_view(nullptr)
	{
	}

	CCBuilderScene::~CCBuilderScene()
	{
	}

	bool CCBuilderScene::init()
	{
		bool ret = false;

		do{
			CC_BREAK_IF( !Scene::init());

			CCBReader* pReader = new CCBReader( NodeLoaderLibrary::getInstance());

			_view = pReader->readNodeGraphFromFile( "HelloCocosBuilder", this );

			if( _view ){
				this->addChild( _view );
			}

			ret= true;
		}while( false );

		return ret;
	}
}

