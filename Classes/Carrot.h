#pragma once
#include "CommonDefines.h"
#include "VisibleBase.h"

class Carrot :public VisibleBase {
private:
	using _Base = VisibleBase;
	bool init();
	int lifepoint;
	bool runAnimation(cocos2d::Touch* touch, cocos2d::Event* event);

	class LifeLabel :public VisibleBase {
	public:
		static LifeLabel* create() {
			LifeLabel* pRet = new(std::nothrow) LifeLabel(); if (pRet && pRet->init()) {
				pRet->autorelease(); return pRet;
			}
			else {
				delete pRet; pRet = nullptr; return nullptr;
			}
		};
		bool init();
		bool update(int lifepoint);
	};

	LifeLabel* lifeLabel;

	cocos2d::EventListenerTouchOneByOne* touchListener;

public:
	CREATE_FUNC(Carrot);
	void getHurt(int damage);

	void onExit()override;
};