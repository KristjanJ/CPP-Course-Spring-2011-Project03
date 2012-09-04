#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include <string>
#include <sstream>
#include <ostream>

#include "line.h"

/*!
\brief An n-dimensional sphere.
*/
template <class T>
class Sphere
{
public:
    /*!
    \details Center point of this sphere.
    */
    T o;

    /*!
    \details Radius of this sphere.
    */
    float r;

    /*!
    \details Default constructor. Constructs a sphere with a center point and radius of zero.
    */
    Sphere<T>();

    /*!
    \details Constructs a sphere with a given center point and radius. If a negative radius is given, it will default to 0.
    \param no Center point.
    \param nr Radius.
    */
    Sphere<T>(T no, float nr);

    /*!
    \details Checks if this sphere contains a given point.
    \param v A point.
    \returns true if the point is inside the sphere, otherwize false.
    */
    bool contains(T v);

    /*!
    \details Checks if this sphere contains a given line.
    \param l A line.
    \returns true if the line is inside the sphere, otherwize false.
    */
    bool contains(Line<T> l);

    /*!
    \details Scales this sphere to a new size. If a negative factor is given no scaling will be performed.
    \param factor Radius multiplier.
    */
    void scale(float factor);

    /*!
    \details Returns the string representation of this sphere.
    \returns The string representation of this sphere.
    */
    std::string toString() const;
};

template <class T>
Sphere<T>::Sphere()
{
    r = 0;
}

template <class T>
Sphere<T>::Sphere(T no, float nr)
{
    o = no;

    if (nr >= 0)
    {
        r = nr;
    }
    else
    {
        r = 0;
    }
}

template <class T>
bool Sphere<T>::contains(T v)
{
    bool contains = o.distanceFrom(v) <= r;

    return contains;
}

template <class T>
bool Sphere<T>::contains(Line<T> l)
{
    bool contains = (o.distanceFrom(l.p1) <= r) && (o.distanceFrom(l.p2) <= r);

    return contains;
}

template <class T>
void Sphere<T>::scale(float factor)
{
    if (factor >= 0)
    {
        r = r * factor;
    }
}

template <class T>
std::string Sphere<T>::toString() const
{
    std::ostringstream outStringStream;
    outStringStream << "(" << o.toString() << ", " << r << ")";

    std::string stringRepresentation = outStringStream.str();

    return stringRepresentation;
}

template <class T>
std::ostream& operator << (std::ostream& out, const Sphere<T>& sphere)
{
    out << sphere.toString();

    return out;
}

#endif // SPHERE_H_INCLUDED
