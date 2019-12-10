#include "LedStrip.h"

namespace sergomor
{

LedStrip& LedStrip::instance()
{
    static LedStrip instance;
    return instance;
};

LedStrip::LedStrip()
{
    leds = FastLED.leds();
    size = FastLED.size();
}

void LedStrip::show()
{
    FastLED.show();
}

} // namespace sergomor