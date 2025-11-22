#include "CardView.h"

USING_NS_CC;

CardView::CardView()
{
    this->_suitFileNames = new std::string[5]{
        "suits/club.png",
        "suits/diamond.png",
        "suits/heart.png",
        "suits/spade.png"
        ""
    };
}

CardView* CardView::create()
{
    // 重写create，使用卡图创建sprite
    CardView* cardView = new (std::nothrow) CardView();
    if (cardView && cardView->initWithFile("card_general.png"))
    {
        cardView->autorelease();
        return cardView;
    }
    CC_SAFE_DELETE(cardView);
    return nullptr;
}

bool CardView::init()
{
    this->CARD_WIDTH = this->getContentSize().width;
    this->CARD_HEIGHT = this->getContentSize().height;

    this->_cardModel = new CardModel();
    if (!this->_cardModel)
    {
        return false;
    }

    auto suitType = this->_cardModel->getSuitType();
    auto faceType = this->_cardModel->getFaceType();

    // 处理数字
    std::string faceFileName = "";
    if (suitType == CardSuitType::CST_CLUBS || suitType == CardSuitType::CST_SPADES)
    {
        faceFileName += "black_";
    }
    else if (suitType == CardSuitType::CST_DIAMONDS || suitType == CardSuitType::CST_HEARTS)
    {
        faceFileName += "red_";
    }

    if (faceType >= 1 && faceType <= 9)
    {
        faceFileName += '0' + faceType + 1;
    }
    else
    {
        if (faceType == CardFaceType::CFT_ACE)
        {
            faceFileName += "A";
        }
        else if (faceType == CardFaceType::CFT_JACK)
        {
            faceFileName += "J";
        }
        else if (faceType == CardFaceType::CFT_QUEEN)
        {
            faceFileName += "Q";
        }
        else if (faceType == CardFaceType::CFT_KING)
        {
            faceFileName += "K";
        }
    }
    faceFileName += ".png";

    // 左上小数字
    std::string smallFaceFileName = "number/small_" + faceFileName;
    auto smallFaceSprite = Sprite::create(smallFaceFileName.data());
    if (!smallFaceSprite)
    {
        return false;
    }
    smallFaceSprite->setAnchorPoint(Vec2(0, 1));
    smallFaceSprite->setPosition(CARD_BORDER, CARD_HEIGHT - CARD_BORDER);
    this->addChild(smallFaceSprite);

    // 右上花色
    std::string& suitFileName = this->_suitFileNames[this->_cardModel->getSuitType()];
    auto suitSprite = Sprite::create(suitFileName.data());
    if (!suitSprite)
    {
        return false;
    }
    suitSprite->setAnchorPoint(Vec2(1, 1));
    suitSprite->setPosition(CARD_WIDTH - CARD_BORDER, CARD_HEIGHT - CARD_BORDER);
    this->addChild(suitSprite);

    // 中间大数字
    std::string bigFaceFileName = "number/big_" + faceFileName;
    auto bigFaceSprite = Sprite::create(bigFaceFileName.data());
    if (!bigFaceSprite)
    {
        return false;
    }
    bigFaceSprite->setPosition(CARD_WIDTH / 2, CARD_HEIGHT / 2);
    this->addChild(bigFaceSprite);

    return true;
}