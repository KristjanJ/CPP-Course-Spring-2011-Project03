#include "issquare.h"

#include <cmath>

bool IsSquare::operator () (unsigned long value)
{
    double squareRoot = sqrt(value);
    long integer = static_cast<long>(squareRoot);
    double fraction = squareRoot - integer;


    bool square = (fraction == 0);

    return square;
}
