#pragma once
#ifndef __GAMEMODEL_H__
#define __GAMEMODEL_H__

#include <vector>
#include "CardModel.h"

class GameModel
{
private:
	std::map<int, CardModel*> _playFieldCards;
	std::vector<CardModel*> _stackCards;
	// 手牌右侧堆栈
	std::vector<CardModel*> _stackCardRight;
public:
	GameModel(): _playFieldCards(), _stackCards() {}
	void addPlayFieldCards(CardModel& card);
	void addStackCards(CardModel& card);
	void addStackRightCards(CardModel& card);
	std::map<int, CardModel*> getPlayFieldCards() const { return this->_playFieldCards; }
	std::vector<CardModel*> getStackCards() const { return this->_stackCards; };
	std::vector<CardModel*> getStackRightCards() const { return this->_stackCardRight; }

	/**
	* 从桌面牌或牌堆移除牌
	*/
	CardModel* removeByCardId(int cardId);

	/**
	* 手牌右侧堆栈pop并返回
	*/
	CardModel* stackRightPop();

	/**
	* 整理堆牌，将顶牌放入右侧stack
	*/
	void initStackCards();
};

#endif