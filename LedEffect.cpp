#include "LedEffect.h"

namespace sergomor
{

void LedEffect::begin(CRGB _color = CRGB::Green, uint32_t _speed = 100)
{
    color = _color;
    speed = _speed;
    leds = FastLED.leds();
    size = FastLED.size();
}

void LedEffect::tick()
{
    if (waiting())
        return;

    run();
    FastLED.show();

    wait(speed);
}

} // namespace sergomor