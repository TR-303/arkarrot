#pragma once
#include "CommonDefines.h"

/*
* @brief 所有可见组件的基类，功能为加载所有动画帧
*/
class VisibleBase :public cocos2d::Sprite {
protected:
	using _Base = Sprite;
	//该可见对象包含的所有动画帧
	cocos2d::Animation* animationFrames;
	/*
	* @brief 从指定plist文件加载指定名称的素材集合，并用第一帧创建精灵
	* @param plist路径
	* @param 名称――帧命名要求：<名称>_<两位帧序号>.png
	* @param 帧数
	*/
	void loadAnimationFramesFromPlist(const string& plist_path, const string& name, int frame_cnt);
	
	virtual bool init(const string& plist_path, const string& name, int frame_cnt);

	VisibleBase();
};