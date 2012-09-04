#ifndef RANDOMNUMBERGENERATOR_H_INCLUDED
#define RANDOMNUMBERGENERATOR_H_INCLUDED

/*!
\brief A functor that generates random numbers.
*/
class RandomNumberGenerator
{
public:
    /*!
    \details Default constructor. Uses srand() to seed rand().
    */
    RandomNumberGenerator();

    /*!
    \details Returns a random number.
    \returns A random number.
    */
    unsigned long operator () ();
};

#endif // RANDOMNUMBERGENERATOR_H_INCLUDED
