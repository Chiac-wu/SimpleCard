#pragma once
#ifndef __GAMEMODELSERVICE_H__
#define __GAMEMODELSERVICE_H__

#include "models/GameModel.h"
#include "configs/models/LevelConfig.h"

class GameModelFromLevelGenerator
{
public:
	/**
	* 由关卡levelConfig生成GameModel
	*/
	static GameModel& generateGameModel(LevelConfig &config);
};

#endif // !__GAMEMODELSERVICE_H__
