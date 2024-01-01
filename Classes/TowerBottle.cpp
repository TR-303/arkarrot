#include "TowerBottle.h"

USING_NS_CC;

bool TowerBottle::init()
{
    if (!_Base::init("Bottle"))return false;
    return true;
}

BulletBase* TowerBottle::generateBullet()
{

    return nullptr;
}