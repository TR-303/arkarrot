#include "Monster.h"
#include "LevelScene.h"
#include "Carrot.h"

USING_NS_CC;

bool Monster::init(const string& name, std::vector<cocos2d::Vec2>& checkpoints)
{
    monsterInfo = CSVDataManager::getInstance()->getMonsterInfo(name);
    maxLP = visibleLP = trueLP = monsterInfo.lifepoint;
    currentSpeed = monsterInfo.speed;
    this->checkpoints = checkpoints;
    currentCheckpoint = 1;
    distance = 0;
    schedule(CC_CALLBACK_1(Monster::move, this), 1.0f / 30, "monster_moving");
    if (!_Base::init(monsterInfo.plist_path, monsterInfo.name, monsterInfo.frame_cnt))return false;
    runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(animationFrames, 0.2))));
    return true;
}

void Monster::move(float dt)
{
    Vec2 myPos = getPosition();
    Vec2 direction = (checkpoints[currentCheckpoint] - myPos).getNormalized();
    setFlippedX(direction.x < 0);
    distance += currentSpeed * dt;
    setPosition(myPos + direction * currentSpeed * dt);
    if (myPos.distance(checkpoints[currentCheckpoint]) < 5) {
        if (++currentCheckpoint >= checkpoints.size()) {
            LevelScene::getInstance()->eraseMonster(this);
            unschedule("monster_moving");
            runAction(Hide::create());
            setPosition(10000, 10000);
            LevelScene::getInstance()->getCarrot()->getHurt(monsterInfo.damage);
        }
    }
}

void Monster::die()
{
    scheduleOnce(
        [&](float dt) {
            LevelScene::getInstance()->eraseMonster(this);
        }, 2.0f, "delay erase");
    LevelScene::getInstance()->addMonsy(monsterInfo.reward);
    setPosition(10000, 10000);
}
