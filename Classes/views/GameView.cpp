#include "GameView.h"
#include "CardView.h"

USING_NS_CC;

Scene* GameView::createScene(GameModel& gameModel)
{
    return GameView::create(gameModel);
}

GameView* GameView::create(GameModel& gameModel) {
    GameView* pRet = new(std::nothrow) GameView();
    if (pRet && pRet->init(gameModel)) {
        pRet->autorelease();
        return pRet;
    }
    else {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool GameView::init(GameModel& gameModel)
{
    this->_gameController = GameController::getInstance();
    this->_gameModel = &gameModel;
    if (!Scene::init())
    {
        return false;
    }

    // Ö÷ÅÆÇø
    auto mainArea = LayerColor::create(Color4B::BLUE, 1080, 1500);
    mainArea->setPosition(0, 580);
    this->addChild(mainArea);
    for (auto card : _gameModel->getPlayFieldCards())
    {
        auto cardView = CardView::create(*card);
        cardView->setPosition(card->getPostion());
        mainArea->addChild(cardView);
    }

    // ¶ÑÅÆÇø
    auto heapArea = LayerColor::create(Color4B::GRAY, 1080, 580);
    heapArea->setPosition(0, 0);
    this->addChild(heapArea);

    return true;
}