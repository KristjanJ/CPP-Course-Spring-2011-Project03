#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <vector>
#include <string>
#include <sstream>
#include <ostream>
#include <cmath>

/*!
\brief An n-dimensional vector.
*/
template <unsigned short n>
class Vector
{
public:
    /*!
    \details Coordinates of this vector.
    */
    std::vector<float> coords;

    /*!
    \details Default constructor. Constructs a null vector.
    */
    Vector<n>();

    /*!
    \details Constructs a vector with given coordinates.
    \param crds Coordinates.
    */
    Vector<n>(std::vector<float> crds);

    /*!
    \details Returns the distance between this vector and an another vector.
    \param v Another vector.
    \returns The distance between this vector and an another vector.
    */
    float distanceFrom(Vector<n> v);

    /*!
    \details Returns the string representation of this vector.
    \returns The string representation of this vector.
    */
    std::string toString() const;
};

template <unsigned short n>
Vector<n>::Vector()
{
    for (int i = 0; i < n; i++)
    {
        coords.push_back(0);
    }
}

template <unsigned short n>
Vector<n>::Vector(std::vector<float> crds)
{
    if (crds.size() == n)
    {
        coords = crds;
    }
    else
    {
        std::string exceptionString("Vector: Invalid number of coordinates.");
        throw exceptionString;
    }
}

template <unsigned short n>
float Vector<n>::distanceFrom(Vector<n> v)
{
    float fNum = 0;

    std::vector<float>::iterator iterator1 = coords.begin();
    std::vector<float>::iterator iterator2 = v.coords.begin();
    std::vector<float>::iterator endIterator1 = coords.end();
    std::vector<float>::iterator endIterator2 = v.coords.end();

    for ( ; iterator1 != endIterator1 && iterator2 != endIterator2; iterator1++, iterator2++)
    {
        fNum = fNum + pow((*iterator1 - *iterator2), 2);
    }

    float distance = sqrt(fNum);

    return distance;
}

template <unsigned short n>
std::string Vector<n>::toString() const
{
    std::ostringstream outStringStream;

    std::vector<float>::const_iterator iterator = coords.begin();
    std::vector<float>::const_iterator endIterator = coords.end();

    outStringStream << "(";

    for (int i = 0; iterator != endIterator; i++, iterator++)
    {
        outStringStream << *iterator;

        if (i != n - 1)
        {
            outStringStream << ", ";
        }
    }

    outStringStream << ")";

    std::string stringRepresentation = outStringStream.str();

    return stringRepresentation;
}

template <unsigned short n>
std::ostream& operator << (std::ostream& out, const Vector<n>& vector)
{
    out << vector.toString();

    return out;
}

#endif // VECTOR_H_INCLUDED
