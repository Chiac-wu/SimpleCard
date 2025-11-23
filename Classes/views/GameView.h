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

    virtual bool init();

    // implement the "static create()" method manually
    static GameView* create();

    void drawView();

    /**
    *   获取主牌区cardviews
    */
    Vector<Node*>& getPlayFieldCardViews() { return _playFieldViews; };

    bool TouchBegan(Touch* touch, Event* unused_event);
    bool TouchEnded(Touch* touch, Event* unused_event);

private:
    const GameController* _gameController;
    const GameModel* _gameModel;
    Vec2 stackLeftPos;  // 翻牌区起始位置
    Vec2 stackRightPos; // 手牌区位置
    Vector<Node*> _allViews;    // 所有牌views
    Vector<Node*> _playFieldViews;  // 主牌区cardviews
    Vector<Node*> _stackViewsLeft;  // 堆牌区cardviews
    std::stack<Node*> _stackViewsRight;  // 堆牌区右侧堆
};

#endif // __GAMEVIEW_SCENE_H__
