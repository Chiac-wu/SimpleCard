#pragma once
#ifndef __GAMECONTROLLER_H__
#define __GAMECONTROLLER_H__

#include "configs/models/CardResConfig.h"
#include "configs/models/LevelConfig.h"
#include "models/GameModel.h"
#include "views/GameView.h"
class GameView;

// 单例controller
class GameController
{
public:
	static GameController* getInstance()
	{
		static GameController gameController;
		return &gameController;
	}

	void startGame(int levelId);
	GameModel*& getGameModel() { return _gameModel; }
	GameView*& getGameView() { return _gameView; }
	
	static LevelConfig *levelConfig;
	static CardResConfig *cardResConfig;

private:
	GameView* _gameView = nullptr;
	GameModel* _gameModel = nullptr;

	GameController() = default;
	GameController(const GameController&) = delete;
	GameController& operator=(const GameController&) = delete;
};

class PlayFieldController
{
public:
	/**
	* 初始化controller，向view注册回调函数
	*/
	static void init(GameView& gameView);

	/**
	* 处理card点击事件
	*/
	static void handleCardClick(int cardId);

	static bool isMatchToStack(int cardId);
};

#endif // !__GAMECONTROLLER_H__
