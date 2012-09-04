#include "randomnumbergenerator.h"

#include <cstdlib>
#include <ctime>

RandomNumberGenerator::RandomNumberGenerator()
{
    srand(time(0));
}

unsigned long RandomNumberGenerator::operator () ()
{
    unsigned long random = rand();

    return random;
}
