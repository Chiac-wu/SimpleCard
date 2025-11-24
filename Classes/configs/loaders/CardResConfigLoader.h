#pragma once
#ifndef __CARDRESCONFIGLOADER_H__
#define __CARDRESCONFIGLOADER_H__

#include "configs/models/CardResConfig.h"

class CardResConfigLoader
{
public:
	/**
	* 从json加载卡牌ui资源配置
	*/
	static CardResConfig& loadFromJson(const std::string& fileName);
};

#endif // !__CARDRESCONFIGLOADER_H__
