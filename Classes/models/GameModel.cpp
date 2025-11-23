#include "GameModel.h"

void GameModel::addPlayFieldCards(CardModel& card)
{
	this->_playFieldCards.insert(std::pair<int, CardModel*>({ card.getId(), &card }));
}

void GameModel::addStackCards(CardModel& card)
{
	this->_stackCards.push_back(&card);
}

void GameModel::initStackCards()
{
	auto it = _stackCards.end();
	--it;
	_stackCardRight.push_back(*it);
	_stackCards.erase(it);
}

void GameModel::addStackRightCards(CardModel& card)
{
	_stackCardRight.push_back(&card);
}

CardModel* GameModel::removeByCardId(int cardId)
{
	auto it = _playFieldCards.find(cardId);
	if (it != _playFieldCards.end())
	{
		auto card = it->second;
		_playFieldCards.erase(cardId);
		return card;
	}
	if (_stackCards.back()->getId() == cardId)
	{
		auto card = _stackCards.back();
		_stackCards.erase(_stackCards.end() - 1);
		return card;
	}
}