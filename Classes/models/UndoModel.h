#pragma once
#ifndef __UNDOMODEL_H__
#define __UNDOMODEL_H__
#include "cocos2d.h"

USING_NS_CC;

class UndoModel
{
public:
	/**
	* 回退信息<目标块，目标位置>
	*	1: 桌面区
	*	2: 堆牌区
	*  -1: 空
	*/
	using LogType = std::pair<int, std::pair<int, Vec2>>;

	/**
	* 获取一条回退信息
	*/
	LogType getUndoLog();

	void pushUndoLog(LogType log) { _logs.push(log); };

private:
	std::stack<LogType> _logs;
};

#endif // !__UNDOMODEL_H__
