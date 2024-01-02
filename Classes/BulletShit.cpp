#include "BulletShit.h"
#include "LevelScene.h"

USING_NS_CC;

bool BulletShit::init(VictimBase* target, int speed, int damage, const string& plist_path, const string& name, int frame_cnt)
{
    if (!_Base::init(target, speed, damage, plist_path, name, frame_cnt))return false;
    runAction(RepeatForever::create(RotateBy::create(1, 360)));
    return true;
}

void BulletShit::hit()
{
    if (target == nullptr || target->getPosition().x > 1000)
    {
        this->removeFromParentAndCleanup(true);
        return;
    }
    target->getHit(damage);
    unschedule("flying");
    runAction(Hide::create());
    target->debuff(damage / 10.0f);
    auto shitted = Sprite::createWithSpriteFrameName("BulletShit-shitted-1.png");
    Vector<SpriteFrame*> frames;
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("BulletShit-shitted-1.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("BulletShit-shitted-2.png"));
    shitted->setPosition(Vec2(target->getContentSize()) / 2);
    shitted->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(frames, 0.1f))));
    shitted->scheduleOnce([=](float dt)->bool {
        shitted->removeFromParentAndCleanup(true);
        return true;
        }, damage / 10.0f, "shitted");
    target->addChild(shitted, 1);
    explode();
    setPosition(10000, 10000);
    removeFromParentAndCleanup(true);
}


void BulletShit::explode()
{
    auto particle = Sprite::createWithSpriteFrameName("BulletShit-particle_1.png");
    Vector<SpriteFrame*> frames;
    for (int i = 1; i <= 2; ++i) {
        frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("BulletShit-particle_%d.png", i)));
    }
    particle->setPosition(getPosition());
    getParent()->addChild(particle, 500);
    particle->runAction(Sequence::create(Animate::create(Animation::createWithSpriteFrames(frames, 0.1f)), Hide::create(), nullptr));
}