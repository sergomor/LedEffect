#pragma once

#include "utils/Tickable.h"
#include <FastLED.h>

namespace sergomor
{

class LedEffect : public Tickable
{
public:
   virtual void run() = 0;
   void begin(CRGB, uint32_t);
   void tick();
   void set(int i, CRGB& color) { if (i < size && i >= 0) leds[i] = color; }

protected:
   uint32_t speed;
   CRGB color;
   uint8_t size = 0;
   CRGB *leds = nullptr;
};
}; // namespace sergomor
