#include "BulletBottle.h"
#include "CommonDefines.h"

USING_NS_CC;

void BulletBottle::explode()
{
	auto particle = Sprite::createWithSpriteFrameName("BulletBottle-particle_1.png");
	Vector<SpriteFrame*> frames;
	frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("BulletBottle-particle_1.png"));
	frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("BulletBottle-particle_2.png"));
	particle->setPosition(getPosition());
	getParent()->addChild(particle,500);
	particle->runAction(Sequence::create(Animate::create(Animation::createWithSpriteFrames(frames, 0.1f)), Hide::create(), nullptr));
}