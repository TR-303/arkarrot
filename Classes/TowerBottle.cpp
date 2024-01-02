#include "TowerBottle.h"
#include "LevelScene.h"
USING_NS_CC;

TowerBottle::TowerBottle()
{
}

bool TowerBottle::init()
{
    if (!_Base::init("Bottle"))return false;
    return true;
}

void TowerBottle::generateBullet()
{
    target->preHit(towerInfo.attack);
    auto bullet = BulletBottle::create(target, towerInfo.bullet_speed, towerInfo.attack, towerInfo.plist_path, StringUtils::format("Bullet%s", towerInfo.name.c_str()), towerInfo.bullet_frame_cnt);
    bullet->setPosition(getPosition() + 30 * Vec2::forAngle(CC_DEGREES_TO_RADIANS(getPointingAngle())));
    bullet->setRotation(getRotation());
    LevelScene::getInstance()->addChild(bullet, 20);
    Sprite::setSpriteFrame(animationFrames.front());
    SFX::bottleFire();
}