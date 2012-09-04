#ifndef ISSQUARE_H_INCLUDED
#define ISSQUARE_H_INCLUDED

/*!
\brief A functor that tests if a given number is a square of an integer.
*/
class IsSquare
{
public:
    /*!
    \details Tests if a given number is a square of an integer.
    \param value Input value.
    \returns true if value is a square, otherwize false.
    */
    bool operator () (unsigned long value);
};

#endif // ISSQUARE_H_INCLUDED
