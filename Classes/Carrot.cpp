#include "Carrot.h"
#include "LevelScene.h"

USING_NS_CC;

bool Carrot::init()
{
    if (!_Base::init("Items/carrot.plist", "carrot", 21))return false;
    auto shadow = Sprite::createWithSpriteFrameName("shadow.png");
    shadow->setPosition(58, 0);
    addChild(shadow, -1);

    lifepoint = 10;

    touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(Carrot::runAnimation, this);
    _eventDispatcher->addEventListenerWithFixedPriority(touchListener, 100);

    lifeLabel = LifeLabel::create();
    lifeLabel->setPosition(Vec2(getContentSize()) / 2 + Vec2(60, -20));
    this->addChild(lifeLabel);

    return true;
}

bool Carrot::runAnimation(Touch* touch, Event* event)
{
    if (lifepoint < 10)return false;
    auto touchLocation = touch->getLocation();
    if (getBoundingBox().containsPoint(touchLocation))
    {
        Vector<SpriteFrame*> frames;
        for (int i = 10; i < 18; ++i)frames.pushBack(animationFrames.at(i));
        for (int i = 17; i >= 10; --i)frames.pushBack(animationFrames.at(i));
        frames.pushBack(animationFrames.at(0));
        runAction(Animate::create(Animation::createWithSpriteFrames(frames, 0.1f)));
        return true;
    }
    return false;
}

void Carrot::getHurt(int damage)
{
    lifepoint -= damage;
    if (lifepoint <= 0) {
        //LevelScene::getInstance()->lose();
        return;
    }
    lifeLabel->update(lifepoint);
    setSpriteFrame(animationFrames.at(10 - lifepoint));
}

void Carrot::onExit()
{
    Node::onExit();
    _eventDispatcher->removeEventListener(touchListener);
}

bool Carrot::LifeLabel::init()
{
    if (!VisibleBase::init("Items/Items02-hd.plist", "BOSSHP", 10))return false;
    setSpriteFrame(animationFrames.back());
    return true;
}

bool Carrot::LifeLabel::update(int lifepoint)
{
    setSpriteFrame(animationFrames.at(lifepoint - 1));
    return lifepoint != 0;
}
