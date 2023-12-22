#include "CommonDefines.h"
#include "StartMenuScene.h"

//#include "SelectLevelScene.h"

USING_NS_CC;

bool StartMenuScene::init()
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("test_resources/mainscene1-hd.plist");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 center = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

	if (!Scene::init())return false;
	//add sprites below
    
    Sprite* health_notice = Sprite::create("test_resources/health_notice.png");
    Sprite* background = Sprite::createWithSpriteFrameName("mainbg.png");
    Sprite* title = Sprite::createWithSpriteFrameName("mainbg_CN.png");
    Sprite* carrot = Sprite::createWithSpriteFrameName("carrot.png");
    Sprite* leaf1 = Sprite::createWithSpriteFrameName("leaf-1.png");
    Sprite* leaf2 = Sprite::createWithSpriteFrameName("leaf-2.png");
    Sprite* leaf3 = Sprite::createWithSpriteFrameName("leaf-3.png");

    /*if (background == nullptr || title == nullptr || health_notice == nullptr)return false;*/

    Sequence* sequence = Sequence::create(DelayTime::create(2.0f), FadeOut::create(.5f), nullptr);
    health_notice->runAction(sequence);


    // 设置精灵位置
    background->setPosition(center);
    title->setPosition(center + Vec2(0, -15));
    health_notice->setPosition(center);
    carrot->setPosition(origin + Vec2(480, 357));
    leaf1->setPosition(origin+ Vec2(402, 464));
    leaf2->setPosition(origin + Vec2(479, 473));
    leaf3->setPosition(origin + Vec2(555, 456));

    // 将精灵添加到场景中
    this->addChild(health_notice, 110);
    this->addChild(background);
    this->addChild(title, 100);
    this->addChild(carrot,90);
    this->addChild(leaf1, 10);
    this->addChild(leaf2, 10);
    this->addChild(leaf3, 9);

    //button
    auto button = cocos2d::ui::Button::create();
    button->loadTextures("btn_adventure_normal_CN.png", "btn_adventure_pressed_CN.png", "", cocos2d::ui::Widget::TextureResType::PLIST);
    button->setPosition(center + Vec2(0, -280));
    button->addClickEventListener(CC_CALLBACK_0(StartMenuScene::startButtonCallBack, this));

    CREATE_POSITION_INDICATOR();

	return true;
}

/*
* @todo 编写selectlevelscene.h
*/
void StartMenuScene::startButtonCallBack()
{
    
}
