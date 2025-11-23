#include "GameModelService.h"

GameModel& GameModelFromLevelGenerator::generateGameModel(LevelConfig& config)
{
	// ∂¡LevelConfig£¨º”‘ÿΩ¯GameModel
	GameModel *gameModel = new GameModel();
	for (auto cardConfig : config.playFieldCards)
	{
		auto suit = static_cast<CardSuitType>(cardConfig->cardSuit);
		auto face = static_cast<CardFaceType>(cardConfig->cardFace);
		CardModel* card = new CardModel(suit, face, cardConfig->position);
		gameModel->addPlayFieldCards(*card);
	}
	return *gameModel;
}