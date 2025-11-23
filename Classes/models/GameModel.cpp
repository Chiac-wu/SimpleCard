#include "GameModel.h"

void GameModel::addPlayFieldCards(CardModel& card)
{
	this->_playFieldCards.emplace_back(&card);
}

void GameModel::addStackCards(CardModel& card)
{
	this->_stackCards.emplace_back(&card);
}