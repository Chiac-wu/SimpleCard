#pragma once
#ifndef __GAMEMODEL_H__
#define __GAMEMODEL_H__

#include <vector>
#include "CardModel.h"

class GameModel
{
private:
	std::vector<CardModel> _cards;

public:
	GameModel();
};

#endif