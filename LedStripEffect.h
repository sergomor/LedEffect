#pragma once

#include "ArduinoWiFiHost.h"

#include "LedStrip.h"

namespace sergomor
{

class LedStripEffect : public Tickable, public Stateable
{
public:
    LedStripEffect() { stateSet(STOPPED); }
    virtual void run() = 0;
    virtual void tick();
    inline void set(int i, CRGB color) { LedStrip::instance().set(i, color); }
    inline uint16_t size() { return LedStrip::instance().size; }
    void begin(uint32_t _speed) { speed = _speed; stateSet(RUNNING); }
    void end();

    enum : state_t
	{
		STOPPED,
		RUNNING,
		
		LAST // for child states
	};

private:
    uint32_t speed = 100;
};
}; // namespace sergomor
