#include "LedStripEffect.h"
#include "LedStrip.h"

namespace sergomor
{

void LedStripEffect::end()
{
    stateSet(STOPPED);
    for (int i = 0; i < size(); i++)
        set(i, CRGB::Black);
    LedStrip::instance().show();
}

void LedStripEffect::tick()
{
    if (stateGet() == STOPPED)
        return;

    if (waiting())
        return;

    run();
    LedStrip::instance().show();

    wait(speed);
}

} // namespace sergomor