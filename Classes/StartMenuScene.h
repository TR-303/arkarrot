#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "StartMenuScene.h"

class StartMenuScene :public cocos2d::Scene {
public:
	bool init()override;
	CREATE_FUNC(StartMenuScene);
	/*
	* @brief 开始按钮回调函数，功能为进入选关界面
	*/
	void StartMenuScene::goToChooseMenuScene(cocos2d::Ref* sender);
};