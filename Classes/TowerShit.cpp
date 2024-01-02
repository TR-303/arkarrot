#include "TowerShit.h"
#include "LevelScene.h"

USING_NS_CC;

TowerShit::TowerShit()
{
}

bool TowerShit::init()
{
    if (!_Base::init("Shit"))return false;
    return true;
}

void TowerShit::generateBullet()
{
    auto bullet = BulletShit::create(target, towerInfo.bullet_speed, towerInfo.attack, towerInfo.plist_path, StringUtils::format("Bullet%s", towerInfo.name.c_str()), towerInfo.bullet_frame_cnt);
    bullet->setPosition(getPosition());
    LevelScene::getInstance()->addChild(bullet);
    Sprite::setSpriteFrame(animationFrames.front());
    SFX::shitFire();
}

bool TowerShit::aim(float dt)
{
    if (target == nullptr)return false;
    return true;
}
