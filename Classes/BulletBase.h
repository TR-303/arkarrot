#pragma once
#include "CommonDefines.h"
#include "VisibleBase.h"
#include "VictimBase.h"

class BulletBase :public VisibleBase {
protected:
    using _Base = VisibleBase;
    int damage;
    int speed;
    VictimBase* target;

    virtual bool init(VictimBase* target, int speed, int damage, const string& plist_path, const string& name, int frame_cnt);
    /*
    * @brief 回调函数，处理飞行，击中判定
    */
    virtual void update(float dt);
    /*
    * @brief 处理击中特效，目标血量扣除，自销毁
    */
    virtual void hit();

    virtual void explode() = 0;
};