#pragma once
#include "audio/include/AudioEngine.h"
#include "cocos2d.h"
USING_NS_CC;

namespace SFX {

	inline void towerBulid()
	{
		AudioEngine::play2d("SoundFx/TowerBulid.mp3", false, 0.5f);
	}

	inline void towerSelect()
	{
		AudioEngine::play2d("SoundFx/TowerSelect.mp3", false, 0.5f);
	}

	inline void towerUpdata()
	{
		AudioEngine::play2d("SoundFx/TowerUpdata.mp3", false, 0.5f);
	}

	inline void towerSell()
	{
		AudioEngine::play2d("SoundFx/TowerSell.mp3", false, 0.5f);
	}

	inline void towerDeselect()
	{
		AudioEngine::play2d("SoundFx/TowerDeselect.mp3", false, 0.5f);
	}

	inline void bottleFire()
	{
		AudioEngine::play2d("SoundFx/Bottle.mp3", false, 1.0f);
	}

	inline void shitFire()
	{
		AudioEngine::play2d("SoundFx/Shit.mp3", false, 1.0f);
	}

	inline void starFire()
	{
		AudioEngine::play2d("SoundFx/Star.mp3", false, 1.0f);
	}

	inline void monsterDie()
	{
		string filename = "SoundFx/monster (" + std::to_string(rand() % 8 + 1) + ").mp3";
		AudioEngine::play2d(filename, false, 0.5f);
	}
}
