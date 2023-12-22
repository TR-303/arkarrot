#pragma once
#include "CommonDefines.h"
#include "VisibleBase.h"
#include "BulletBase.h"
#include "CSVDataManager.h"

/*
* @brief 所有塔的基类
*/
class TowerBase :public VisibleBase {
public:
	using _Base = VisibleBase;

	int level;
	TowerInfo towerInfo;

	virtual bool init(const string& towerName);

	void levelup();

	float timeToFire;
	VisibleBase* target;

	virtual bool aim(float dt);

	virtual void fire();

	virtual BulletBase* generateBullet() = 0;

	void setTarget(VisibleBase* target);

	void update(float dt)override;

	TowerBase();
};