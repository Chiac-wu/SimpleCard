#include "UndoModel.h"

UndoModel::LogType UndoModel::getUndoLog()
{
	if (_logs.empty())
	{
		return LogType({-1, Vec2()});
	}
	auto log = _logs.top(); 
	_logs.pop(); 
	return log;
}