#pragma once
#include "CommonDefines.h"
#include "TowerBottle.h"

class TestScene :public cocos2d::Scene {
public:
	CREATE_FUNC(TestScene);

	virtual bool init()override {
		if (!Scene::init())return false;

		auto* tower = TowerBottle::create();
		this->addChild(tower);
	}
};