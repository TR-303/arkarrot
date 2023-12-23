#include "CommonDefines.h"
#include "VisibleBase.h"

USING_NS_CC;

VisibleBase::VisibleBase(){}

void VisibleBase::loadAnimationFramesFromPlist(const string& plist_path, const string& name, int frame_cnt)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plist_path);
	for (int i = 1; i <= frame_cnt; ++i) {
		animationFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("%s_%d.png", name.c_str(), i)));
	}
	Sprite::setSpriteFrame(animationFrames.front());
}

bool VisibleBase::init(const string& plist_path, const string& name, int frame_cnt)
{
	if (!_Base::init()) {
		return false;
	}
	loadAnimationFramesFromPlist(plist_path, name, frame_cnt);
	return true;
}
