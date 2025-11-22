#pragma once
#ifndef __CARDVIEW_H__
#define __CARDVIEW_H__

#include "cocos2d.h"
#include "models/CardModel.h"

class CardView : public cocos2d::Sprite
{
private:
	CardModel *_cardModel;
	std::string *_suitFileNames;
	const int CARD_BORDER = 15;
	int CARD_WIDTH;
	int CARD_HEIGHT;

public:
	CardView() = default;
	static CardView* create();
	virtual bool init() override;
};

#endif