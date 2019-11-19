#pragma once

#include "LedEffect.h"

namespace sergomor
{

class TailEffect : public LedEffect
{
public:
    virtual void run();
    void begin(CRGB, uint32_t, uint8_t);
    ~TailEffect() { delete colors; }

    enum : uint8_t {
        DIR_FORWARD,
        DIR_BACKWARD,
        DIR_BOTH
    }; 

private:
    void forward(int&);
    void backward(int&);
    uint8_t tail = 0;
    CRGB* colors = nullptr;
    uint8_t dir = DIR_BOTH;
};
}; // namespace sergomor
