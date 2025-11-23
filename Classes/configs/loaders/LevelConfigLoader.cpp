#include "LevelConfigLoader.h"
#include "json/rapidjson.h"
#include "json/document.h"

LevelConfig& LevelConfigLoader::loadLevelConfig(const int &levelId)
{
	LevelConfig *config = new LevelConfig();
	std::string jsonFileName = "levels/level" + std::to_string(levelId) + ".json";
	std::string str = FileUtils::getInstance()->getStringFromFile(jsonFileName);
	rapidjson::Document d;
	d.Parse<rapidjson::kParseDefaultFlags>(str.c_str());
	if (d.HasParseError()) {
		CCLOG("GetParseError %s\n", d.GetParseError());
		return *config;
	}
	for (int i = 0; i < d["Playfield"].Size(); ++i)
	{
		int suit = d["Playfield"][i]["CardSuit"].GetInt();
		int face = d["Playfield"][i]["CardFace"].GetInt();
		Vec2 pos(d["Playfield"][i]["Position"]["x"].GetInt(), d["Playfield"][i]["Position"]["y"].GetInt());
		CardConfig* card = new CardConfig(suit, face, pos);
		config->playFieldCards.emplace_back(card);
	}
	for (int i = 0; i < d["Stack"].Size(); ++i)
	{
		int suit = d["Stack"][i]["CardSuit"].GetInt();
		int face = d["Stack"][i]["CardFace"].GetInt();
		Vec2 pos(d["Stack"][i]["Position"]["x"].GetInt(), d["Stack"][i]["Position"]["y"].GetInt());
		CardConfig* card = new CardConfig(suit, face, pos);
		config->stackCards.emplace_back(card);
	}
	return *config;
}