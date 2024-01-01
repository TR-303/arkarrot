#pragma once
#include "CommonDefines.h"
#include "VictimBase.h"
#include "CSVDataManager.h"

class Monster :public VictimBase {
public:
    using _Base = VictimBase;
    static Monster* create(const string& name, std::vector<cocos2d::Vec2>& checkpoints) {
        Monster* pRet = new(std::nothrow) Monster(); if (pRet && pRet->init(name, checkpoints)) {
            pRet->autorelease(); return pRet;
        }
        else {
            delete pRet; pRet = nullptr; return nullptr;
        }
    };
    float distance;
private:
    bool init(const string& name, std::vector<cocos2d::Vec2>& checkpoints);

    void move(float dt);

    MonsterInfo monsterInfo;
    int currentSpeed;
    std::vector<cocos2d::Vec2> checkpoints;
    int currentCheckpoint;

    // Í¨¹ý VictimBase ¼Ì³Ð
    void die() override;
};