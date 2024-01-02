#pragma once
#include "CommonDefines.h"
#include "BulletBase.h"

class BulletBottle :public BulletBase {
public:
	using _Base = BulletBase;
    static BulletBottle* create(VictimBase* target, int speed, int damage, const string& plist_path, const string& name, int frame_cnt) {
        BulletBottle* pRet = new(std::nothrow) BulletBottle(); if (pRet && pRet->init(target, speed, damage,plist_path, name, frame_cnt)) {
            pRet->autorelease(); return pRet;
        }
        else {
            delete pRet; pRet = nullptr; return nullptr;
        }
    };

    // Í¨¹ý BulletBase ¼Ì³Ð
    void explode() override;
};