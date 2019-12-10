#pragma once

#include "LedStripEffect.h"

namespace sergomor
{

class TailEffect : public LedStripEffect
{
public:
    TailEffect(): LedStripEffect() {};
    virtual void run();
    void begin(CRGB, uint32_t, uint8_t);
   
    enum : uint8_t
    {
        DIR_FORWARD,
        DIR_BACKWARD,
        DIR_BOTH
    };

private:
    CRGB color(int);
    void forward(int &);
    void backward(int &);
    uint8_t tail = 0;
    CRGB tail_color, tail_color_step;
    uint8_t dir = DIR_BOTH;
};
}; // namespace sergomor
