#pragma once
#ifndef __CARDVIEW_H__
#define __CARDVIEW_H__

#include "cocos2d.h"
#include "models/CardModel.h"
#include "configs/models/CardResConfig.h"

class CardView : public cocos2d::Sprite
{
private:
	CardModel *_cardModel;
	// ui×ÊÔ´config
	CardResConfig *_cardResConfig;
	// card±ßÔµ¿í
	const int _CARD_BORDER = 15;
	int _CARD_WIDTH;
	int _CARD_HEIGHT;

	// »æÖÆ
	bool _drawCard();

public:
	CardView(CardModel& cardModel) { this->_cardModel = &cardModel; };
	static CardView* create(CardModel& cardModel);
	virtual bool init() override;

	CardModel& getCardModel() { return *_cardModel; }
};

#endif