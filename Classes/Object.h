#pragma once
#include "CommonDefines.h"
#include "VictimBase.h"
#include "CSVDataManager.h"

class Object :public VictimBase {
private:
    using _Base = VictimBase;

    ObjectInfo objectInfo;

    bool init(const string& name);
public:
    static Object* create(const string& name) {
        Object* pRet = new(std::nothrow) Object(); if (pRet && pRet->init(name)) {
            pRet->autorelease(); return pRet;
        }
        else {
            delete pRet; pRet = nullptr; return nullptr;
        }
    };


    // Í¨¹ý VictimBase ¼Ì³Ð
    void die() override;

};