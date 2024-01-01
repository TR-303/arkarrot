#include "TowerBase.h"
#include "LevelScene.h"

USING_NS_CC;

TowerBase::TowerBase()
{
}

bool TowerBase::init(const string& towerName)
{
	towerInfo = CSVDataManager::getInstance()->getTowerInfo(StringUtils::format("%s1", towerName.c_str()));
	if (!_Base::init(towerInfo.plist_path, towerInfo.name, towerInfo.frame_cnt)) {
		return false;
	}
	target = nullptr;
	level = 1;
	schedule(CC_CALLBACK_1(TowerBase::update, this), 1.0f / 30, "tower_update");
	return true;
}

void TowerBase::levelup()
{
	towerInfo = CSVDataManager::getInstance()->getTowerInfo(StringUtils::format("%s%d", towerInfo.name.substr(0, towerInfo.name.length() - 1).c_str(), ++level));
	loadAnimationFramesFromPlist(towerInfo.plist_path, towerInfo.name, towerInfo.frame_cnt);
}

const VictimBase* TowerBase::getTarget() const
{
	return target;
}

void TowerBase::setTarget(VictimBase* target)
{
	this->target = target;
}

bool TowerBase::aim(float dt)
{
	if (target == nullptr)return false;
	Vec2 targetPos = target->getPosition(), myPos = getPosition();
	float targetAngle = int(CC_RADIANS_TO_DEGREES((targetPos - myPos).getAngle()) + 360) % 360, pointingAngle = getPointingAngle();
	if (abs(targetAngle - pointingAngle) < towerInfo.rotate_speed * dt) {
		setPointingAngle(targetAngle);
		return true;
	}
	else if ((targetAngle < pointingAngle && pointingAngle - targetAngle < 180) || (targetAngle > pointingAngle && targetAngle - pointingAngle > 180)) {
		setPointingAngle(pointingAngle - towerInfo.rotate_speed * dt);
	}
	else {
		setPointingAngle(pointingAngle + towerInfo.rotate_speed * dt);
	}
	return false;
}

void TowerBase::fire()
{
	timeToFire = towerInfo.cooldown;
	auto fireSequence = Sequence::create(Animate::create(Animation::createWithSpriteFrames(animationFrames, 0.02f)), CallFunc::create(CC_CALLBACK_0(TowerBase::generateBullet, this)), nullptr);
	this->runAction(fireSequence);
}

void TowerBase::update(float dt)
{
	auto taunted = LevelScene::getInstance()->getTauntedTarget();
	if (taunted != nullptr && taunted->trueLP > 0 && taunted->getPosition().distance(getPosition()) < towerInfo.range) {
		target = taunted;
	}
	else {
		if (target == nullptr || target->trueLP == 0 || target->getPosition().distance(getPosition()) > towerInfo.range)target = nullptr;
		for (auto monster : LevelScene::getInstance()->getMonsters()) {
			if (monster->getPosition().distance(getPosition()) <= towerInfo.range && monster->trueLP > 0 && (target == nullptr || static_cast<Monster*>(target)->distance < monster->distance))target = monster;
		}
	}
	timeToFire = std::max(0.0f, timeToFire - dt);
	if (aim(dt) && timeToFire == 0) fire();
}

float TowerBase::getPointingAngle() const
{
	return (int(90 - getRotation()) % 360 + 360) % 360;
}

void TowerBase::setPointingAngle(float angle)
{
	setRotation(90 - angle);
}