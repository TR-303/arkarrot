#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class StartMenuScene :public cocos2d::Scene {
public:
	bool init()override;
	void nothing(Ref* sender);//delete it
	CREATE_FUNC(StartMenuScene);
};