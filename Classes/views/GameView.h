#pragma once
#ifndef __GAMEVIEW_SCENE_H__
#define __GAMEVIEW_SCENE_H__

#include "cocos2d.h"
#include "controllers/GameController.h"
#include "models/GameModel.h"

class GameView : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene(GameModel& gameModel);

    virtual bool init(GameModel& gameModel);

    // implement the "static create()" method manually
    static GameView* create(GameModel& gameModel);

private:
    const GameController* _gameController;
    const GameModel* _gameModel;
    Vec2 stackLeftPos;  // 翻牌区起始位置
    Vec2 stackRightPos; // 手牌区位置
};

#endif // __GAMEVIEW_SCENE_H__
