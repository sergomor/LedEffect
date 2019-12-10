#include "LedStripMatrix.h"

namespace sergomor
{

LedStripMatrix& LedStripMatrix::instance()
{
    static LedStripMatrix instance;
    return instance;
}

} // namespace sergomor