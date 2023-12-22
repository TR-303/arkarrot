#include "TowerBase.h"
#include "CSVDataManager.h"
//#include "LevelScene"

USING_NS_CC;

bool TowerBase::aim(float dt)
{
	if (target == nullptr)return false;
	Vec2 targetPos = target->getPosition(), myPos = getPosition();
	float targetAngle = atan2(myPos.y - targetPos.y, myPos.x - targetPos.x) * 180.0f / M_PI, pointingAngle = getRotation();
	float deltaAngle = int(targetAngle - pointingAngle + 360) % 360;
	if (std::min(deltaAngle, 360 - deltaAngle) < towerInfo.rotate_speed * dt) {
		setRotation(targetAngle);
		return true;
	}
	else if (deltaAngle <= 180) {
		setRotation(pointingAngle + towerInfo.rotate_speed * dt);
	}
	else {
		setRotation(pointingAngle - towerInfo.rotate_speed * dt);
	}
	return false;
}

void TowerBase::fire()
{
	timeToFire = towerInfo.cooldown;
	auto* bullet = generateBullet();

}

void TowerBase::setTarget(VisibleBase* target)
{

}

void TowerBase::update(float dt)
{
	timeToFire = std::max(0.0f, timeToFire - dt);
	if (aim(dt) && timeToFire == 0) fire();
}

TowerBase::TowerBase(){}

bool TowerBase::init(const string& towerName)
{
	auto* csvDataManager = CSVDataManager::getInstance();
	auto towerInfo = csvDataManager->getTowerInfo(StringUtils::format("%s1", towerName.c_str()));
	if (!_Base::init(towerInfo.plist_path, towerInfo.name, towerInfo.frame_cnt)) {
		return false;
	}
	towerInfo = towerInfo;
	level = 1;
	return true;
}

void TowerBase::levelup()
{

}