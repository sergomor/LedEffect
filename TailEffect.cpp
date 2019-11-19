#include "TailEffect.h"

template <class T>
inline Print &operator<<(Print &obj, T arg)
{
	obj.print(arg);
	return obj;
}

namespace sergomor
{

void TailEffect::begin(CRGB color = CRGB::Green, uint32_t speed = 100, uint8_t _tail = 0)
{
    LedEffect::begin(color, speed);

    tail = _tail ? _tail : size / 2;
    colors = new CRGB[tail + 1];

    CRGB step = color / tail;
    colors[0] = CRGB::Black;

    for (int i = 0; i < tail; i++)
    {
        colors[tail - i] = color;
        color -= step;
        Serial << i << ": " << colors[tail - i].r << " " << colors[tail - i].g << " " << colors[tail - i].b << "\n";
    }
}

void TailEffect::forward(int& num)
{
    static int idx = 0, i = 0;
    idx = num - tail;
    for (i = 0; i <= tail; i++) set(idx + i, colors[i]);
 
}

void TailEffect::backward(int& num)
{
    static int idx = 0, i = 0;
    idx = size - num + tail;
    for (i = 0; i <= tail; i++) set(idx - i, colors[i]);
}

void TailEffect::run()
{
    static int num = 0;
    static bool d = 0;

    d = dir == DIR_FORWARD ? 1 : (dir == DIR_BOTH ? (num == 0 ? !d : d) : 0);

    d ? forward(num) : backward(num);

    num = (++num % (size + 2 * tail));
}

} // namespace sergomor