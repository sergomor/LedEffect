#include "QuadEffect.h"
#include "LedStripMatrix.h"

#include "alphabet.h"

namespace sergomor
{

void QuadEffect::begin(uint32_t speed)
{
    size = min(LedStripMatrix::instance().rows(), LedStripMatrix::instance().cols());
    LedStripEffect::begin(speed);
    
}

void QuadEffect::quad(uint8_t& s, CRGB c)
{
   static LedStripMatrix& m = LedStripMatrix::instance();
   static uint8_t i;

   for(i = 0; i < s; i++) {
       m.set(i, 0, c);
       m.set(i, s-1, c);
       m.set(0, i, c);
       m.set(s-1, i, c);
   }    
}

void QuadEffect::run()
{
    static uint8_t s = 0;
    static int r = 1, g = 1, b = 1;
    static int max = 100, min = 1;
    static bool g_dir = 1, r_dir = 1, b_dir = 1;
    
    quad(s, CRGB(r, g, b));

    r_dir = r > max ? 0 : (r <= min ? 1 : r_dir);

    b_dir = r > max ? 0 : (b <= min ? 1 : b_dir);

    g_dir ? g++ : g--;
    r_dir ? r++ : r--;


    
    s = ++s % size + 1;
}
} // namespace sergomor