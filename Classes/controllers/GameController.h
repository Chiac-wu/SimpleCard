#pragma once
#ifndef __GAMECONTROLLER_H__
#define __GAMECONTROLLER_H__

#include "configs/models/CardResConfig.h"
#include "configs/models/LevelConfig.h"
#include "models/GameModel.h"

// µ¥Àýcontroller
class GameController
{
public:
	static GameController* getInstance()
	{
		static GameController gameController;
		return &gameController;
	}
	void startGame(int levelId) const;

	static GameModel *gameModel;
	static LevelConfig *levelConfig;
	static CardResConfig *cardResConfig;

private:
	GameController() = default;
	GameController(const GameController&) = delete;
	GameController& operator=(const GameController&) = delete;
};

#endif // !__GAMECONTROLLER_H__
