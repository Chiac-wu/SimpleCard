#include "GameController.h"
#include "configs/loaders/LevelConfigLoader.h"
#include "configs/loaders/CardResConfigLoader.h"
#include "services/GameModelService.h"
#include "views/GameView.h"
#include "cocos2d.h"

USING_NS_CC;

GameModel* GameController::gameModel = nullptr;
LevelConfig* GameController::levelConfig = nullptr;
CardResConfig* GameController::cardResConfig = nullptr;

void GameController::startGame(int levelId) const
{
	levelConfig = &LevelConfigLoader::loadLevelConfig(1);
	gameModel = &GameModelFromLevelGenerator::generateGameModel(*levelConfig);
	cardResConfig = &CardResConfigLoader::loadFromJson("card_res_config.json");

	auto gameView = GameView::createScene(*gameModel);
	Director::getInstance()->replaceScene(gameView);
}