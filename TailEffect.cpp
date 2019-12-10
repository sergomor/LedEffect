#include "TailEffect.h"

namespace sergomor
{

void TailEffect::begin(CRGB color = CRGB::Green, uint32_t speed = 100, uint8_t _tail = 0)
{
    tail = _tail ? _tail : size() / 2;
    tail_color = color;
    tail_color_step = color / tail;
    LedStripEffect::begin(speed);
}

CRGB TailEffect::color(int i)
{
    return i <= 0 ? CRGB::Black : tail_color;
    /*
    if (i >= tail) return tail_color;
    if (i <= 0) return CRGB::Black;
    CRGB c = tail_color;
    while(tail > i++) c -= tail_color_step;
    Serial << c.r << "\n";
    return c;    
    */
}

void TailEffect::forward(int &num)
{
    static int idx = 0, i = 0;
    idx = num - tail;
    for (i = 0; i <= tail; i++)
        set(idx + i, color(i));
}

void TailEffect::backward(int &num)
{
    static int idx = 0, i = 0;
    idx = size() - num + tail;
    for (i = 0; i <= tail; i++)
        set(idx - i, color(i));
}

void TailEffect::run()
{
    static int num = 0;
    static bool d = 0;

    d = dir == DIR_FORWARD ? 1 : (dir == DIR_BOTH ? (num == 0 ? !d : d) : 0);

    d ? forward(num) : backward(num);

    num = (++num % (size() + 2 * tail));
}

} // namespace sergomor