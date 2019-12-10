#pragma once

#include "LedStrip.h"

namespace sergomor
{

class LedStripMatrix: public LedStrip
{
public:

    uint8_t rows() { return 5; }
    uint8_t cols() { return 6; }

    void set(uint8_t row, uint8_t col, CRGB color)
    {
        LedStrip::set(matrix[row][col], color);
    }

    static LedStripMatrix &instance();
    LedStripMatrix(const LedStripMatrix &) = delete;
    LedStripMatrix &operator=(const LedStripMatrix) = delete;

protected:
    LedStripMatrix(): LedStrip() {};

    uint8_t matrix[5][6] = {

        {5, 4, 3, 2, 1, 0},
        {6, 7, 8, 9, 10, 11},
        {17, 16, 15, 14, 13, 12},
        {18, 19, 20, 21, 22, 23},
        {29, 28, 27, 26, 25, 24}\
        
    };  
};

}; // namespace sergomor
