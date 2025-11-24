#include "UndoManager.h"

void UndoManager::insertUndoLog(int from, Vec2 pos)
{
	_undoModel.pushUndoLog(UndoModel::LogType({ from, pos }));
}

void UndoManager::undo(GameView& gameView)
{
	auto log = _undoModel.getUndoLog();
	auto gameModel = GameController::getInstance()->getGameModel();
	if (log.first == 1)
	{
		auto card = gameModel->stackRightPop();
		gameModel->addPlayFieldCards(*card);
		gameView.moveStackTopToPlayField(log.second);
	}
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
	gameView.onBackTouchCallBack = std::bind(&UndoManager::undo, manager, std::placeholders::_1);
	return manager;
}