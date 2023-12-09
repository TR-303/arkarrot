#include "StartMenuScene.h"

USING_NS_CC;

bool StartMenuScene::init()
{
	if (!Scene::init())return false;
	//add sprites below
	auto titile = Label::createWithTTF("Carrots", "fonts/arial.ttf", 50);
	titile->setPosition(240, 200);
	this->addChild(titile);
	return true;
}