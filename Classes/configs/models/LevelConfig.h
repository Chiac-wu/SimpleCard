#pragma once
#ifndef __LEVELCONFIG_H__
#define __LEVELCONFIG_H__

#include <string>
#include "models/CardModel.h"
struct CardConfig
{
	int cardFace;
	int cardSuit;
	Vec2 position;
	CardConfig(int suit, int face, Vec2& pos) : cardSuit(suit), cardFace(face) { position = pos; }
};

struct LevelConfig
{
	std::vector<CardConfig*> playFieldCards;
	std::vector<CardConfig*> stackCards;
};

#endif // !__LEVELCONFIG_H__
