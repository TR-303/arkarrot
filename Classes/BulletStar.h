#pragma once
#include "CommonDefines.h"
#include "BulletBase.h"
#include "Monster.h"

class LevelScene;

class BulletStar :public BulletBase {
public:
	using _Base = BulletBase;
    bool init(VictimBase* target, int speed, int damage, const string& plist_path, const string& name, int frame_cnt)override;
	void hit()override;
	void update(float dt)override;
    static BulletStar* create(VictimBase* target, int speed, int damage, const string& plist_path, const string& name, int frame_cnt) {
        BulletStar* pRet = new(std::nothrow) BulletStar(); if (pRet && pRet->init(target, speed, damage, plist_path, name, frame_cnt)) {
            pRet->autorelease(); return pRet;
        }
        else {
            delete pRet; pRet = nullptr; return nullptr;
        }
    };

    BulletStar() = default;

    void explode() override;
};