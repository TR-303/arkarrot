#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class StartMenuScene :public cocos2d::Scene {
public:
	CREATE_FUNC(StartMenuScene);
private:
	virtual bool init();
	/*
	* @brief 역迦객큐돨쀼딧변鑒，학뻣돕朞밑끝쒼
	*/
	void startButtonCallBack();
};