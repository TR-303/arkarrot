#include "TowerStar.h"
#include "LevelScene.h"

USING_NS_CC;

TowerStar::TowerStar()
{
}

bool TowerStar::init()
{
    if (!_Base::init("Star"))return false;
    return true;
}

void TowerStar::generateBullet()
{
    auto bullet = BulletStar::create(target, towerInfo.bullet_speed, towerInfo.attack, towerInfo.plist_path, StringUtils::format("Bullet%s", towerInfo.name.c_str()), towerInfo.bullet_frame_cnt);
    bullet->setPosition(getPosition());
    LevelScene::getInstance()->addChild(bullet);
    Sprite::setSpriteFrame(animationFrames.front());
}

bool TowerStar::aim(float dt)
{
    if (target == nullptr)return false;
    return true;
}
