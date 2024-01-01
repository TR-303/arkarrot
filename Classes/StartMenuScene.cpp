#include "StartMenuScene.h"
#include "CommonDefines.h"
#include"ChooseMenuScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

bool StartMenuScene::init()
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scenes/startmenuscene/startmenuscene.plist");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 center = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

    if (!Scene::init())return false;

    Sprite* health_notice = Sprite::create("Scenes/startmenuscene/health_notice.png");
    Sprite* background = Sprite::createWithSpriteFrameName("mainbg.png");
    Sprite* title = Sprite::createWithSpriteFrameName("mainbg_CN.png");
    Sprite* carrot = Sprite::createWithSpriteFrameName("carrot.png");
    Sprite* leaf1 = Sprite::createWithSpriteFrameName("leaf-1.png");
    Sprite* leaf2 = Sprite::createWithSpriteFrameName("leaf-2.png");
    Sprite* leaf3 = Sprite::createWithSpriteFrameName("leaf-3.png");

    if (background == nullptr || title == nullptr || health_notice == nullptr) {
        throw std::exception("");
        return false;
    }

    Sequence* sequence = Sequence::create(DelayTime::create(2.0f), FadeOut::create(.5f), nullptr);
    health_notice->runAction(sequence);

    // 设置精灵位置
    background->setPosition(center);
    title->setPosition(center + Vec2(0, -15));
    health_notice->setPosition(center);
    carrot->setPosition(origin + Vec2(480, 357));
    leaf1->setPosition(origin + Vec2(402, 464));
    leaf2->setPosition(origin + Vec2(479, 473));
    leaf3->setPosition(origin + Vec2(555, 456));

    // 将精灵添加到场景中
    this->addChild(health_notice, 110);
    this->addChild(background);
    this->addChild(title, 100);
    this->addChild(carrot, 90);
    this->addChild(leaf1, 10);
    this->addChild(leaf2, 10);
    this->addChild(leaf3, 9);

    //button
    auto button = cocos2d::ui::Button::create();
    button->loadTextures("btn_adventure_normal_CN.png", "btn_adventure_pressed_CN.png", "", cocos2d::ui::Widget::TextureResType::PLIST);
    button->setPosition(center + Vec2(0, -230));

    // 设置按钮回调
    //button->addTouchEventListener(CC_CALLBACK_1(StartMenuScene::nothing, this));
    //button->addClickEventListener(CC_CALLBACK_1(StartMenuScene::nothing, this));
    // 
    // 
    //auto button = cocos2d::ui::Button::create("Themes/scene/stages_theme1-hd/ss_map01.png");
    //button->setPosition(cocos2d::Vec2(480, 320));
    button->addClickEventListener(CC_CALLBACK_1(StartMenuScene::goToChooseMenuScene, this));

    // 添加按钮到场景
    this->addChild(button, 2);

    CREATE_POSITION_INDICATOR();

    return true;
}

void StartMenuScene::goToChooseMenuScene(cocos2d::Ref* sender) {
    auto scene = ChooseMenuScene::create();
    cocos2d::Director::getInstance()->pushScene(cocos2d::TransitionFade::create(0.5, scene));
}