#include "GameModel.h"

void GameModel::addPlayFieldCards(CardModel& card)
{
	this->_playFieldCards.emplace_back(&card);
}