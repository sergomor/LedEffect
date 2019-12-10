#include "LedStripNumber.h"
#include "LedStripMatrix.h"

#include "alphabet.h"

namespace sergomor
{

void LedStripNumber::drawChar(char c, CRGB color = CRGB::Green)
{
    uint32_t mask = pow(2, c);
    for (int row = 0; row < LedStripMatrix::instance().rows(); row++)
    {
        for (int col = 0; col < 3; col++)
        {
            LedStripMatrix::instance().set(row, col, alphabet[row][col] & mask ? color : CRGB::Black);          
        }
    }
}

} // namespace sergomor