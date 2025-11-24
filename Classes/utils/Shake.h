#pragma once
#ifndef __SHAKE_H__
#define __SHAKE_H__
#include "cocos2d.h"

/**
* 外部工具，x方向抖动效果
*/
class CCShake : public cocos2d::ActionInterval {
public:
  CCShake();
  // Create the action with a time and a strength (same in x and y)
  static CCShake *create(float d, float strength);
  // Create the action with a time and strengths (different in x and y)
  static CCShake *createWithStrength(float d, float strength_x,
                                     float strength_y);
  bool initWithDuration(float d, float strength_x, float strength_y);

protected:
  virtual void startWithTarget(cocos2d::CCNode *pTarget);
  virtual void update(float time);
  virtual void stop(void);
  // Initial position of the shaked node
  float m_initial_x, m_initial_y;
  // Strength of the action
  float m_strength_x, m_strength_y;
};


class CCFallOffShake : public CCShake {
public:
  CCFallOffShake();
  // Create the action with a time and a strength (same in x and y)
  static CCFallOffShake *create(float d, float strength);
  // Create the action with a time and strengths (different in x and y)
  static CCFallOffShake *createWithStrength(float d, float strength_x,
                                            float strength_y);

protected:
  virtual void update(float time);
};
#endif //__SHAKE_H__