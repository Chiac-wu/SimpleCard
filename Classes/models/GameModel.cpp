#include <algorithm>
#include <random>
#include "GameModel.h"

GameModel::GameModel()
{
	// Éú³ÉÅÆ×é
	for (CardSuitType s = CardSuitType::CST_CLUBS; s < CardSuitType::CST_SPADES; s = static_cast<CardSuitType>(s + 1))
	{
		for (CardFaceType f = CardFaceType::CFT_ACE; f < CardFaceType::CFT_KING; f = static_cast<CardFaceType>(f + 1))
		{
			CardModel card(s, f);
			this->_cards.emplace_back(card);
		}
	}

}