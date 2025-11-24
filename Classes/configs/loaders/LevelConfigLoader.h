#pragma once
#ifndef __LEVELCONFIGLOADER_H__
#define __LEVELCONFIGLOADER_H__

#include "configs/models/LevelConfig.h"

class LevelConfigLoader
{
public:
	/**
	* ¥”jsonº”‘ÿπÿø®≈‰÷√
	*/
	static LevelConfig& loadLevelConfig(const int &levelId);
};

#endif // !__LEVELCONFIGLOADER_H__
