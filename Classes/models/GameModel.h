#pragma once
#ifndef __GAMEMODEL_H__
#define __GAMEMODEL_H__

#include <vector>
#include "CardModel.h"

class GameModel
{
private:
	std::map<int, CardModel*> _playFieldCards;
	std::map<int, CardModel*> _stackCards;
public:
	GameModel(): _playFieldCards(), _stackCards() {}
	void addPlayFieldCards(CardModel& card);
	void addStackCards(CardModel& card);
	std::map<int, CardModel*> getPlayFieldCards() const { return this->_playFieldCards; }
	std::map<int, CardModel*> getStackCards() const { return this->_stackCards; };
};

#endif