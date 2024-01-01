#include "CommonDefines.h"
#include "BulletBase.h"

USING_NS_CC;

bool BulletBase::init(VictimBase* target, int speed, int damage, const string& plist_path, const string& name, int frame_cnt) {
    this->target = target;
    this->speed = speed;
    this->damage = damage;
    if (!_Base::init(plist_path,name,frame_cnt))return false;
    this->schedule(CC_CALLBACK_1(BulletBase::update, this), 0, "flying");
    this->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(animationFrames, 0.1f))));
    return true;
}

void BulletBase::update(float dt)
{
    if (target == nullptr || target->getPosition().distance(getPosition()) > 1000) {
        hit();
        return;
    }
    Vec2 targetPos = target->getPosition(), myPos = getPosition();
    setRotation(90 - CC_RADIANS_TO_DEGREES((targetPos - myPos).getAngle()));
    if (targetPos.distance(myPos) <= 10) {
        hit();
        return;
    }
    Vec2 direction = (targetPos - myPos).getNormalized();
    setPosition(myPos + dt * speed * direction);
}

void BulletBase::hit()
{
    if (target != nullptr)target->getHit(damage);
    unschedule("flying");
    runAction(Hide::create());
    explode();
    setPosition(10000, 10000);
    removeFromParentAndCleanup(true);
}