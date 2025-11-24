#pragma once
#ifndef __UNDOMANAGER_H__
#define __UNDOMANAGER_H__
#include "models/UndoModel.h"
#include "views/GameView.h"
class UndoModel;

class UndoManager
{
private:
	UndoModel _undoModel;

public:
	/**
	* @param from: card所属的区
	*	1: 桌面区
	*	2: 堆牌区
	*  -1: 空
	* @param pos: 原位置
	*/
	void insertUndoLog(int from, int zOrder, Vec2 pos);

	/**
	* 执行一次回退
	*/
	void undo(GameView& gameView);

	static UndoManager* init(GameView& gameView);
};

#endif // !__UNDOMANAGER_H__
