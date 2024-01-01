#pragma once 
#include "CommonDefines.h";
#include "VisibleBase.h"

class LevelScene;

class VictimBase :public VisibleBase {
public:
	using _Base = VisibleBase;
	bool init(const string& plist_path, const string& name, int frame_cnt);
	bool setTaunt(cocos2d::Touch* touch, cocos2d::Event* event);

	bool preHit(int damage);
	bool getHit(int damage);
	void updateLifeBar();

	cocos2d::ProgressTimer* lifeBarFg;
	int maxLP;
	int visibleLP;
	int trueLP;

	virtual void die() = 0;
	bool isdead = false;

	cocos2d::Vector<cocos2d::SpriteFrame*> particleFrames;

	cocos2d::EventListenerTouchOneByOne* touchListener;

	void onExit()override;
};