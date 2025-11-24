#include "UndoManager.h"

void UndoManager::insertUndoLog(int from, int zOrder, Vec2 pos)
{
	_undoModel.pushUndoLog(UndoModel::LogType(from, { zOrder, pos }));
}

void UndoManager::undo(GameView& gameView)
{
	auto log = _undoModel.getUndoLog();
	auto gameModel = GameController::getInstance()->getGameModel();
	// 退回到主牌区
	if (log.first == 1)
	{
		auto card = gameModel->stackRightPop();
		gameModel->addPlayFieldCards(*card);
		gameView.moveStackTopToPlayField(log.second);
	}
	// 退回到堆牌区
	else if (log.first == 2)
	{
		auto card = gameModel->stackRightPop();
		gameModel->addStackCards(*card);
		gameView.moveStackTopToStackLeft(log.second);
	}
}

UndoManager* UndoManager::init(GameView& gameView)
{
	auto manager = new UndoManager();
	// 注册点击回退的回调函数
	gameView.onBackTouchCallBack = std::bind(&UndoManager::undo, manager, std::placeholders::_1);
	return manager;
}