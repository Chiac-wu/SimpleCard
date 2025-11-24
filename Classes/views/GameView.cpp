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
    // 主牌区
    auto mainArea = LayerColor::create(Color4B::BLUE, 1080, 1500);
    mainArea->setPosition(0, 580);
    this->addChild(mainArea);
    for (auto card : _gameModel->getPlayFieldCards())
    {
        auto cardView = CardView::create(*card.second);
        cardView->setPosition(Vec2(card.second->getPostion().x, card.second->getPostion().y + 580));
        this->addChild(cardView);
        _allViews.insert(std::pair<int, Node*>({ cardView->getCardModel().getId(), cardView }));
        _playFieldViews.pushBack(cardView);
    }
    this->_playFieldViews = mainArea->getChildren();

    // 堆牌区
    auto stackArea = LayerColor::create(Color4B::GRAY, 1080, 580);
    stackArea->setPosition(0, 0);
    this->addChild(stackArea);
    for (auto card : _gameModel->getStackCards())
    {
        auto cardView = CardView::create(*card);
        cardView->setPosition(stackLeftPos);
        this->addChild(cardView);
        stackLeftPos.x += 100;
        _allViews.insert(std::pair<int, Node*>({cardView->getCardModel().getId(), cardView}));
        _stackViewsLeft.pushBack(cardView);
    }
    this->_stackViewsLeft = stackArea->getChildren();
    // 顶牌放右侧
    for (auto card : _gameModel->getStackRightCards())
    {
        auto cardView = CardView::create(*card);
        cardView->setPosition(stackRightPos);
        this->addChild(cardView);
        _allViews.insert(std::pair<int, Node*>({ cardView->getCardModel().getId(), cardView }));
        _stackViewsRight.push(cardView);
    }

    // 回退按钮
    _backLabel = Label::createWithTTF(TTFConfig("fonts/Marker Felt.ttf", 60), "BACK");
    _backLabel->setTextColor(Color4B::BLACK);
    _backLabel->setPosition(Vec2(980, 290));
    this->addChild(_backLabel);

    // 触摸事件监听器
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameView::TouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameView::TouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameView::moveCardToStack(int cardId)
{
    auto node = _allViews.find(cardId)->second;
    node->setZOrder(_stackViewsRight.top()->getZOrder() + 1);
    auto moveTo = MoveTo::create(0.6, stackRightPos);
    auto easeOutIn = EaseElasticOut::create(moveTo, 1.2);
    node->runAction(easeOutIn);
    _stackViewsRight.push(node);
}

int GameView::touchInCard(Touch* touch)
{
    for (auto& node : _allViews)
    {
        auto card = static_cast<CardView*>(node.second);
        auto nodeLocation = card->convertToNodeSpace(touch->getLocation());
        Size cardSize = card->getContentSize();
        Rect rect = Rect(0, 0, cardSize.width, cardSize.height);
        if (rect.containsPoint(nodeLocation)) {
            return card->getCardModel().getId();
        }
        else {
            // touch ended outside
        }
    }
    return -1;
}

bool GameView::touchInBack(Touch* touch)
{
    auto nodeLocation = _backLabel->convertToNodeSpace(touch->getLocation());
    Size backSize = _backLabel->getContentSize();
    Rect rect = Rect(0, 0, backSize.width, backSize.height);
    if (rect.containsPoint(nodeLocation))
    {
        return true;
    }
    return false;
}

bool GameView::TouchBegan(Touch* touch, Event* unused_event)
{
    if (touchInCard(touch) == -1)
    {
        // 是否在back内
        return touchInBack(touch);
    }
    // touch开始在card内
    return true;
}

bool GameView::TouchEnded(Touch* touch, Event* unused_event)
{
    if (touchInBack(touch))
    {
        onBackTouchCallBack(*this);
        return true;
    }

    auto cardId = touchInCard(touch);
    // touch结束在card内
    if (cardId != -1)
    {
        onCardTouchCallBack(cardId);
    }
    return true;
}

void GameView::moveStackTopToPlayField(Vec2& pos)
{
    auto moveTo = MoveTo::create(0.6, pos);
    auto easeOutIn = EaseElasticOut::create(moveTo, 1.2);
    auto node = _stackViewsRight.top();
    _stackViewsRight.pop();
    _playFieldViews.pushBack(node);
    node->runAction(easeOutIn);
}

void GameView::moveStackTopToStackLeft(Vec2& pos)
{
    auto moveTo = MoveTo::create(0.6, pos);
    auto easeOutIn = EaseElasticOut::create(moveTo, 1.2);
    auto node = _stackViewsRight.top();
    _stackViewsRight.pop();
    _stackViewsLeft.pushBack(node);
    node->runAction(easeOutIn);
}

Vec2 GameView::getPositionById(int cardId)
{
    auto view = this->_allViews.find(cardId)->second;
    return view->getPosition();
}