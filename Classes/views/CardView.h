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
	CardResConfig *_cardResConfig;
	std::string *_suitFileNames;
	const int CARD_BORDER = 15;
	int CARD_WIDTH;
	int CARD_HEIGHT;

	// »æÖÆ
	bool _drawCard();

public:
	CardView(CardModel& cardModel) { this->_cardModel = &cardModel; };
	static CardView* create(CardModel& cardModel);
	virtual bool init() override;

	CardModel& getCardModel() { return *_cardModel; }
};

#endif