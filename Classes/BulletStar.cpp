#include "BulletStar.h"
#include "LevelScene.h"

USING_NS_CC;

bool BulletStar::init(VictimBase* target, int speed, int damage, const string& plist_path, const string& name, int frame_cnt)
{
    if (!_Base::init(target, speed, damage, plist_path, name, frame_cnt))return false;
    runAction(RepeatForever::create(RotateBy::create(1, 360)));
    return true;
}

void BulletStar::hit()
{
    if (target == nullptr) {
        setPosition(10000, 10000);
        removeFromParentAndCleanup(true);
        return;
    }
    target->getHit(damage);
	for (auto monster : LevelScene::getInstance()->getMonsters()) {
		if (monster->getPosition().distance(getPosition()) < 150)monster->getHit(damage);
	}
    unschedule("flying");
    runAction(Hide::create());
    explode();
    setPosition(10000, 10000);
    removeFromParentAndCleanup(true);
}

void BulletStar::update(float dt)
{
    if (target == nullptr || target->getPosition().x > 1000) {
        hit();
        return;
    }
    Vec2 targetPos = target->getPosition(), myPos = getPosition();
    if (targetPos.distance(myPos) <= 10) {
        hit();
        return;
    }
    Vec2 direction = (targetPos - myPos).getNormalized();
    setPosition(myPos + dt * speed * direction);
}

void BulletStar::explode()
{
    auto particle = Sprite::createWithSpriteFrameName("BulletStar-particle_1.png");
    Vector<SpriteFrame*> frames;
    for (int i = 1; i <= 6; ++i) {
        frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("BulletStar-particle_%d.png", i)));
    }
    particle->setPosition(getPosition());
    getParent()->addChild(particle, 500);
    particle->runAction(Sequence::create(Animate::create(Animation::createWithSpriteFrames(frames, 0.1f)), Hide::create(), nullptr));
}