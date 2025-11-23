#pragma once
#ifndef __GAMEMODEL_H__
#define __GAMEMODEL_H__

#include <vector>
#include "CardModel.h"

class GameModel
{
private:
	std::vector<CardModel*> _playFieldCards;
	std::vector<CardModel*> _stackCards;
public:
	GameModel(): _playFieldCards(), _stackCards() {}
	void addPlayFieldCards(CardModel& card);
	std::vector<CardModel*> getPlayFieldCards() const { return this->_playFieldCards; }
	std::vector<CardModel*> getStackCards() const { return this->_stackCards; };
};

#endif