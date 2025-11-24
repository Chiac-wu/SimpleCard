#pragma once
#ifndef __GAMEVIEW_SCENE_H__
#define __GAMEVIEW_SCENE_H__

#include "cocos2d.h"
#include "controllers/GameController.h"
#include "models/GameModel.h"
class GameController;

class GameView : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    // card点击后回调的controller函数
    std::function<void(int)> onCardTouchCallBack;
    // 点击回退的回调函数
    std::function<void(GameView&)> onBackTouchCallBack;

    virtual bool init();

    // implement the "static create()" method manually
    static GameView* create();

    void drawView();

    /**
    *   获取主牌区cardviews
    */
    Vector<Node*>& getPlayFieldCardViews() { return _playFieldViews; };

    /**
    * 将 @param cardId 对应的牌移动到 @param des 的位置
    */
    void moveCardToStack(int cardId);

    /**
    * 将stack顶牌移动到桌面的 @param pos 位置
    */
    void moveStackTopToPlayField(Vec2& pos);

    /**
    * 将stack顶牌移动到堆牌区的 @param pos 位置
    */
    void moveStackTopToStackLeft(Vec2& pos);

    /**
    * touch事件是否在card中，是则返回cardId
    */
    int touchInCard(Touch* touch);

    /**
    * touch事件是否在back按钮中
    */
    bool touchInBack(Touch* touch);

    /**
    * 根据cardId获取card的当前位置
    */
    Vec2 getPositionById(int cardId);

    bool TouchBegan(Touch* touch, Event* unused_event);
    bool TouchEnded(Touch* touch, Event* unused_event);

private:
    const GameController* _gameController;
    const GameModel* _gameModel;
    Label* _backLabel;
    Vec2 stackLeftPos;  // 翻牌区起始位置
    Vec2 stackRightPos; // 手牌区位置
    std::map<int, Node*> _allViews; // 所有牌views
    Vector<Node*> _playFieldViews;  // 主牌区cardviews
    Vector<Node*> _stackViewsLeft;  // 堆牌区cardviews
    std::stack<Node*> _stackViewsRight;  // 堆牌区右侧堆
};

#endif // __GAMEVIEW_SCENE_H__
