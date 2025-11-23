#include "CardModel.h"

void CardModel::_setId()
{
	static int id = 0;
	this->_id = id++;
}

CardModel::CardModel()
{
	_setId();
	this->_suitType = CardSuitType::CST_CLUBS;
	this->_faceType = CardFaceType::CFT_ACE;
}

CardModel::CardModel(CardSuitType suitType, CardFaceType faceType)
{
	_setId();
	this->_suitType = suitType;
	this->_faceType = faceType;
}

CardModel::CardModel(CardSuitType suitType, CardFaceType faceType, Vec2& pos)
{
	_setId();
	this->_suitType = suitType;
	this->_faceType = faceType;
	this->_position = pos;
}

void CardModel::setSuitType(CardSuitType type)
{
	this->_suitType = type;
}

void CardModel::setFaceType(CardFaceType type)
{
	this->_faceType = type;
}

void CardModel::setPosition(const Vec2& pos)
{
	this->_position = pos;
}

CardSuitType CardModel::getSuitType()
{
	return this->_suitType;
}

CardFaceType CardModel::getFaceType()
{
	return this->_faceType;
}

Vec2 CardModel::getPostion()
{
	return this->_position;
}