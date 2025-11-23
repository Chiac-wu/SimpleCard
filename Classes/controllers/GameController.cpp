#include "GameController.h"
#include "configs/loaders/LevelConfigLoader.h"
#include "configs/loaders/CardResConfigLoader.h"
#include "services/GameModelService.h"
#include "cocos2d.h"

USING_NS_CC;

LevelConfig* GameController::levelConfig = nullptr;
CardResConfig* GameController::cardResConfig = nullptr;

void GameController::startGame(int levelId)
{
	// 初始化关卡数据
	levelConfig = &LevelConfigLoader::loadLevelConfig(1);
	cardResConfig = &CardResConfigLoader::loadFromJson("card_res_config.json");

	_gameModel = &GameModelFromLevelGenerator::generateGameModel(*levelConfig);
	_gameView = static_cast<GameView*>(GameView::createScene());

	// 初始化子控制器
	PlayFieldController::init(*_gameView);

	// 创建gameView
	_gameView->drawView();
	Director::getInstance()->replaceScene(_gameView);
}

void PlayFieldController::init(GameView& gameView)
{
	// 注册view回调函数
	gameView.onCardTouchCallBack = PlayFieldController::handleCardClick;
}

void PlayFieldController::handleCardClick(int cardId)
{
	CCLOG("id=%d", cardId);
}