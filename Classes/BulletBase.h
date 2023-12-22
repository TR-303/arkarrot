#pragma once
#include "CommonDefines.h"
#include "VisibleBase.h"

class BulletBase :public VisibleBase {
protected:
    int damage;
    int speed;
    VisibleBase* target;


    CREATE_FUNC(BulletBase);

    virtual bool init()override {

    }

};