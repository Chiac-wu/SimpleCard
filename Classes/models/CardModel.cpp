#include "CardModel.h"

CardModel::CardModel()
{
	this->_suitType = CardSuitType::CST_CLUBS;
	this->_faceType = CardFaceType::CFT_ACE;
}

CardModel::CardModel(CardSuitType suitType, CardFaceType faceType)
{
	this->_suitType = suitType;
	this->_faceType = faceType;
}

void CardModel::setSuitType(CardSuitType type)
{
	this->_suitType = type;
}

void CardModel::setFaceType(CardFaceType type)
{
	this->_faceType = type;
}

CardSuitType CardModel::getSuitType()
{
	return this->_suitType;
}

CardFaceType CardModel::getFaceType()
{
	return this->_faceType;
}