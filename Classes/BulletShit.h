#pragma once
#include "CommonDefines.h"
#include "BulletBase.h"
#include "Monster.h"

class LevelScene;

class BulletShit :public BulletBase {
public:
	using _Base = BulletBase;
    bool init(VictimBase* target, int speed, int damage, const string& plist_path, const string& name, int frame_cnt)override;
	void hit()override;
    static BulletShit* create(VictimBase* target, int speed, int damage, const string& plist_path, const string& name, int frame_cnt) {
        BulletShit* pRet = new(std::nothrow) BulletShit(); if (pRet && pRet->init(target, speed, damage, plist_path, name, frame_cnt)) {
            pRet->autorelease(); return pRet;
        }
        else {
            delete pRet; pRet = nullptr; return nullptr;
        }
    };

    BulletShit() = default;

    void explode() override;
};