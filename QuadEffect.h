#pragma once

#include "LedStripEffect.h"

namespace sergomor
{

class QuadEffect : public LedStripEffect
{
public:
    virtual void run();
    void begin(uint32_t);
    
    void quad(uint8_t&, CRGB);

private:
    uint8_t size;


};
}; // namespace sergomor
