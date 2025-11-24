#include "GameController.h"
#include "configs/loaders/LevelConfigLoader.h"
#include "configs/loaders/CardResConfigLoader.h"
#include "services/GameModelService.h"
#include "managers/UndoManager.h"
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
	_undoManager = UndoManager::init(*_gameView);

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
	if (PlayFieldController::isMatchToStack(cardId))
	{
		auto undoManager = GameController::getInstance()->getUndoManager();
		auto model = GameController::getInstance()->getGameModel();

		// 记录撤销操作
		auto pos = GameController::getInstance()->getGameView()->getPositionById(cardId);
		// 来自堆牌区的移动
		if (model->getStackCards().back()->getId() == cardId)
		{
			undoManager->insertUndoLog(2, pos.first, pos.second);
		}
		// 来自主牌区
		else
		{
			undoManager->insertUndoLog(1, pos.first, pos.second);
		}

		// 更新model数据
		auto cardInMoving = model->removeByCardId(cardId);
		model->addStackRightCards(*cardInMoving);

		// 调用相应的view执行动画
		GameController::getInstance()->getGameView()->moveCardToStack(cardId);
		CCLOG("id=%d", cardId);
	}
}

bool PlayFieldController::isMatchToStack(int cardId)
{
	auto gameModel = GameController::getInstance()->getGameModel();

	auto& playFieldCards = gameModel->getPlayFieldCards();
	auto& stackCards = gameModel->getStackCards();
	auto& stackRightCards = gameModel->getStackRightCards();

	// 点击的是桌面牌
	auto it = playFieldCards.find(cardId);
	if (it != playFieldCards.end())
	{
		auto target = static_cast<int>(stackRightCards.back()->getFaceType());
		auto value = static_cast<int>(it->second->getFaceType());
		if (abs(target - value) == 1)	// 匹配
		{
			return true;
		}
	}
	// 点击的是手牌顶
	if (stackCards.back()->getId() == cardId)
	{
		return true;
	}
	return false;
}