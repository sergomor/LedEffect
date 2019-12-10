#pragma once

#include <FastLED.h>

namespace sergomor
{

class LedStrip
{
public:
   inline void set(int i, CRGB &color)
   {
      if (i < size && i >= 0)
         leds[i] = color;
   }
   void show();

   uint16_t size = 0;
   CRGB *leds = nullptr;

   static LedStrip &instance();
   LedStrip(const LedStrip &) = delete;
   LedStrip &operator=(const LedStrip) = delete;

protected:
   LedStrip();
};
}; // namespace sergomor
