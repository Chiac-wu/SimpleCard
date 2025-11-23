#pragma once

#include "cocos2d.h"

USING_NS_CC;

// 花色类型
enum CardSuitType
{
    CST_NONE = -1,
    CST_CLUBS,      // 梅花
    CST_DIAMONDS,   // 方块
    CST_HEARTS,     // 红桃
    CST_SPADES,     // 黑桃
    CST_NUM_CARD_SUIT_TYPES
};

// 正面类型
enum CardFaceType
{
    CFT_NONE = -1,
    CFT_ACE,
    CFT_TWO,
    CFT_THREE,
    CFT_FOUR,
    CFT_FIVE,
    CFT_SIX,
    CFT_SEVEN,
    CFT_EIGHT,
    CFT_NINE,
    CFT_TEN,
    CFT_JACK,
    CFT_QUEEN,
    CFT_KING,
    CFT_NUM_CARD_FACE_TYPES
};
class CardModel
{
private:
    int _id;
    void _setId();
    CardSuitType _suitType;
    CardFaceType _faceType;
    Vec2 _position;

public:
    CardModel();
    CardModel(CardSuitType suitType, CardFaceType faceType);
    CardModel(CardSuitType suitType, CardFaceType faceType, Vec2& pos);

    void setSuitType(CardSuitType type);
    void setFaceType(CardFaceType type);
    void setPosition(const Vec2& pos);
    int getId() { return _id; }
    CardModel::CardSuitType getSuitType();
    CardModel::CardFaceType getFaceType();
    Vec2 getPostion();
};