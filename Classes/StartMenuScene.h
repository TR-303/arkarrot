#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "StartMenuScene.h"

class StartMenuScene :public cocos2d::Scene {
public:
	bool init()override;

	CREATE_FUNC(StartMenuScene);
	void StartMenuScene::goToChooseMenuScene(cocos2d::Ref* sender);

};