#include "GameModel.h"

void GameModel::addPlayFieldCards(CardModel& card)
{
	this->_playFieldCards.insert(std::pair<int, CardModel*>({ card.getId(), &card }));
}

void GameModel::addStackCards(CardModel& card)
{
	this->_stackCards.insert(std::pair<int, CardModel*>({card.getId(), &card}));
}