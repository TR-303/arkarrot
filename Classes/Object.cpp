#include "Object.h"
#include "LevelScene.h"

USING_NS_CC;

bool Object::init(const string& name)
{
    objectInfo = CSVDataManager::getInstance()->getObjectInfo(name);
    if (!_Base::init(objectInfo.plist_path, name, 1))return false;
    maxLP = trueLP = visibleLP = objectInfo.lifepoint;
    return true;
}

void Object::die()
{
    if (isdead)return;
    isdead = true;
    if (getPosition().x > 10000)return;
    auto lvlscene = LevelScene::getInstance();
    int x = getPosition().x / 80, y = getPosition().y / 80;
    if (objectInfo.size == Vec2(1, 1)) {
        lvlscene->regionStates[y][x] = LevelScene::EMPTY;
    }
    else if (objectInfo.size == Vec2(1, 2)) {
        lvlscene->regionStates[y][x] = LevelScene::EMPTY;
        lvlscene->regionStates[y - 1][x] = LevelScene::EMPTY;
    }
    else if (objectInfo.size == Vec2(2, 1)) {
        lvlscene->regionStates[y][x] = LevelScene::EMPTY;
        lvlscene->regionStates[y][x - 1] = LevelScene::EMPTY;
    }
    else {
        lvlscene->regionStates[y][x] = LevelScene::EMPTY;
        lvlscene->regionStates[y - 1][x] = LevelScene::EMPTY;
        lvlscene->regionStates[y][x - 1] = LevelScene::EMPTY;
        lvlscene->regionStates[y - 1][x - 1] = LevelScene::EMPTY;
    }
    lvlscene->addMonsy(objectInfo.reward);
    setPosition(10000, 10000);
}
