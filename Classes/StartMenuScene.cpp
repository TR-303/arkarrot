#include "StartMenuScene.h"
#include "CommonDefines.h"

USING_NS_CC;

bool StartMenuScene::init()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 center = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

	if (!Scene::init())return false;
	//add sprites below
    
    Sprite* health_notice = Sprite::create("Themes/scene/mainscene1-hd/health_notice.png");
    Sprite* background = Sprite::create("Themes/scene/mainscene1-hd/mainbg.png");
    Sprite* title = Sprite::create("Themes/scene/mainscene1-hd/mainbg_CN.png");

    if (background == nullptr || title == nullptr || health_notice == nullptr)return false;

    Sequence* sequence = Sequence::create(DelayTime::create(2.0f), FadeOut::create(.5f), nullptr);
    health_notice->runAction(sequence);


    // 设置精灵位置
    background->setPosition(center);
    title->setPosition(center + Vec2(0, 50));
    health_notice->setPosition(center);

    // 将精灵添加到场景中
    this->addChild(background);
    this->addChild(title, 1);
    this->addChild(health_notice, 3);


    //button
    auto button = cocos2d::ui::Button::create("Themes/scene/mainscene1-hd/btn_adventure_normal_CN.png", "Themes/scene/mainscene1-hd/btn_adventure_pressed_CN.png", "");
    button->setPosition(center - Vec2(0, 150));

    // 设置按钮回调
    //button->addTouchEventListener(CC_CALLBACK_2(HelloWorld::buttonCallback, this));

    // 添加按钮到场景
    this->addChild(button, 2);

    CREATE_POSITION_INDICATOR();

	return true;
}

