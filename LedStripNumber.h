#pragma once

#include "LedStripEffect.h"

namespace sergomor
{

class LedStripNumber : public LedStripEffect
{
public:
    virtual void run(){};
    void drawChar(char, CRGB);

private:


};
}; // namespace sergomor
