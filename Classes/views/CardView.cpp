#include "CardView.h"
#include "configs/loaders/CardResConfigLoader.h"
#include "controllers/GameController.h"

USING_NS_CC;

CardView* CardView::create(CardModel& cardModel)
{
    // 重写create，使用卡图创建sprite
    CardView* cardView = new (std::nothrow) CardView(cardModel);
    if (cardView && cardView->initWithFile("card_general.png"))
    {
        cardView->init();
        cardView->autorelease();
        return cardView;
    }
    CC_SAFE_DELETE(cardView);
    return nullptr;
}

bool CardView::init()
{
    auto& cardResConfig = *GameController::getInstance()->cardResConfig;

    this->CARD_WIDTH = this->getContentSize().width;
    this->CARD_HEIGHT = this->getContentSize().height;
    auto suitType = this->_cardModel->getSuitType();
    auto faceType = this->_cardModel->getFaceType();

    // 处理数字
    std::string *smallFaceFileName;
    std::string *bigFaceFileName;
    if (suitType == CardSuitType::CST_CLUBS || suitType == CardSuitType::CST_SPADES)
    {
        smallFaceFileName = cardResConfig.SMALL_BLACK_NUM_RES;
        bigFaceFileName = cardResConfig.BIG_BLACK_NUM_RES;
    }
    else if (suitType == CardSuitType::CST_DIAMONDS || suitType == CardSuitType::CST_HEARTS)
    {
        smallFaceFileName = cardResConfig.SMALL_RED_NUM_RES;
        bigFaceFileName = cardResConfig.BIG_RED_NUM_RES;
    }

    // 左上小数字
    auto smallFaceSprite = Sprite::create(smallFaceFileName[faceType]);
    if (!smallFaceSprite)
    {
        return false;
    }
    smallFaceSprite->setAnchorPoint(Vec2(0, 1));
    smallFaceSprite->setPosition(CARD_BORDER, CARD_HEIGHT - CARD_BORDER);
    this->addChild(smallFaceSprite);

    // 右上花色
    auto suitSprite = Sprite::create(cardResConfig.SUIT_RES[suitType]);
    if (!suitSprite)
    {
        return false;
    }
    suitSprite->setAnchorPoint(Vec2(1, 1));
    suitSprite->setPosition(CARD_WIDTH - CARD_BORDER, CARD_HEIGHT - CARD_BORDER);
    this->addChild(suitSprite);

    // 中间大数字
    auto bigFaceSprite = Sprite::create(bigFaceFileName[faceType].data());
    if (!bigFaceSprite)
    {
        return false;
    }
    bigFaceSprite->setPosition(CARD_WIDTH / 2, CARD_HEIGHT / 2 - 2 * CARD_BORDER);
    this->addChild(bigFaceSprite);
    return true;
}