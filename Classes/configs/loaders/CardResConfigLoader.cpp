#include "CardResConfigLoader.h"
#include "models/CardModel.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "cocos2d.h"

USING_NS_CC;

CardResConfig& CardResConfigLoader::loadFromJson(const std::string& fileName)
{
	CardResConfig *config = new CardResConfig();
	std::string str = FileUtils::getInstance()->getStringFromFile(fileName);
	rapidjson::Document d;
	d.Parse<rapidjson::kParseDefaultFlags>(str.c_str());
	if (d.HasParseError()) {
		CCLOG("GetParseError %s\n", d.GetParseError());
		return *config;
	}
	config->SUIT_RES[CardSuitType::CST_CLUBS]	 = d["club"].GetString();
	config->SUIT_RES[CardSuitType::CST_DIAMONDS] = d["diamond"].GetString();
	config->SUIT_RES[CardSuitType::CST_HEARTS]	 = d["heart"].GetString();
	config->SUIT_RES[CardSuitType::CST_SPADES]	 = d["spade"].GetString();

	for (int i = 0; i < d["big"]["black"].Size(); ++i)
	{
		config->BIG_BLACK_NUM_RES[i] = d["big"]["black"][i].GetString();
	}
	for (int i = 0; i < d["big"]["red"].Size(); ++i)
	{
		config->BIG_RED_NUM_RES[i] = d["big"]["red"][i].GetString();
	}
	for (int i = 0; i < d["small"]["black"].Size(); ++i)
	{
		config->SMALL_BLACK_NUM_RES[i] = d["small"]["black"][i].GetString();
	}
	for (int i = 0; i < d["small"]["red"].Size(); ++i)
	{
		config->SMALL_RED_NUM_RES[i] = d["small"]["red"][i].GetString();
	}
	return *config;
}