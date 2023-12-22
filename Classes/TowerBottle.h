#pragma once
#include "CommonDefines.h"
#include "TowerBase.h"

class TowerBottle :public TowerBase {
public:
	using _Base = TowerBase;

	CREATE_FUNC(TowerBottle);
	bool init()override;
};