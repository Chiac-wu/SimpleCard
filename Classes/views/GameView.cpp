#include "GameView.h"
#include "CardView.h"

USING_NS_CC;

Scene* GameView::createScene()
{
    return GameView::create();
}

GameView* GameView::create() {
    GameView* pRet = new(std::nothrow) GameView();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    else {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool GameView::init()
{
    this->_gameController = GameController::getInstance();
    this->_gameModel = GameController::getInstance()->getGameModel();
    this->stackLeftPos = Vec2(290, 290);
    this->stackRightPos = Vec2(790, 290);
    if (!Scene::init())
    {
        return false;
    }
    return true;
}

void GameView::drawView()
{
    // Ö÷ÅÆÇø
    auto mainArea = LayerColor::create(Color4B::BLUE, 1080, 1500);
    mainArea->setPosition(0, 580);
    this->addChild(mainArea);
    for (auto card : _gameModel->getPlayFieldCards())
    {
        auto cardView = CardView::create(*card);
        cardView->setPosition(card->getPostion());
        mainArea->addChild(cardView);
        _allViews.pushBack(cardView);
    }
    this->_playFieldViews = mainArea->getChildren();

    // ¶ÑÅÆÇø
    auto stackArea = LayerColor::create(Color4B::GRAY, 1080, 580);
    stackArea->setPosition(0, 0);
    this->addChild(stackArea);
    for (auto card : _gameModel->getStackCards())
    {
        auto cardView = CardView::create(*card);
        cardView->setPosition(stackLeftPos);
        stackArea->addChild(cardView);
        stackLeftPos.x += 100;
        _allViews.pushBack(cardView);
    }
    this->_stackViewsLeft = stackArea->getChildren();
    // ¶¥ÅÆ·ÅÓÒ²à
    this->_stackViewsRight.push(_stackViewsLeft.back());
    _stackViewsLeft.erase(_stackViewsLeft.end() - 1);
    _stackViewsRight.top()->setPosition(stackRightPos);

    // ´¥ÃþÊÂ¼þ¼àÌýÆ÷
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameView::TouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameView::TouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool GameView::TouchBegan(Touch* touch, Event* unused_event)
{
    return true;
}

bool GameView::TouchEnded(Touch* touch, Event* unused_event)
{
    for (auto& node : _allViews)
    {
        auto card = static_cast<CardView*>(node);
        auto nodeLocation = card->convertToNodeSpace(touch->getLocation());
        Size cardSize = card->getContentSize();
        Rect rect = Rect(0, 0, cardSize.width, cardSize.height);
        if (rect.containsPoint(nodeLocation)) {
            onCardTouchCallBack(card->getCardModel().getId());
        }
        else {
            // touch ended outside
        }
    }
    return true;
}