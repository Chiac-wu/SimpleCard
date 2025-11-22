#pragma once
#ifndef __CARDRESCONFIG_H__
#define __CARDRESCONFIG_H__

#include <string>

struct CardResConfig
{
	std::string BLANK_CARD_RES;
	std::string BIG_RED_NUM_RES[13];
	std::string BIG_BLACK_NUM_RES[13];
	std::string SMALL_RED_NUM_RES[13];
	std::string SMALL_BLACK_NUM_RES[13];
	std::string SUIT_RES[4];
};

#endif // !__CARDRESCONFIG_H__
