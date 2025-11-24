#include "UndoModel.h"

UndoModel::LogType UndoModel::getUndoLog()
{
	if (_logs.empty())
	{
		return LogType({ -1, {0, Vec2(0, 0)} });
	}
	auto log = _logs.top(); 
	_logs.pop(); 
	return log;
}