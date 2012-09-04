#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include <string>
#include <sstream>

/*!
\brief An n-dimensional line.
*/
template <class T>
class Line
{
public:
    /*!
    \details Starting point of this line.
    */
    T p1;

    /*!
    \details Ending point of this line.
    */
    T p2;

    /*!
    \details Default constructor. Constructs a line with the length of zero.
    */
    Line<T>();

    /*!
    \details Constructs a line of two vectors.
    \param np1 Starting point.
    \param np2 Ending point.
    */
    Line<T>(T np1, T np2);

    /*!
    \details Returns the length of this line.
    \returns The length of this line.
    */
    float length();

    /*!
    \details Returns the string representation of this line.
    \returns The string representation of this line.
    */
    std::string toString() const;
};

template <class T>
Line<T>::Line()
{
    //member variables are created on the stack, so theres no need to call the default constructor for them.
}

template <class T>
Line<T>::Line(T np1, T np2)
{
    p1 = np1;
    p2 = np2;
}

template <class T>
float Line<T>::length()
{
    float length = p1.distanceFrom(p2);

    return length;
}

template <class T>
std::string Line<T>::toString() const
{
    std::ostringstream outStringStream;
    outStringStream << "(" << p1.toString() << "-" << p2.toString() << ")";

    return outStringStream.str();
}

template <class T>
std::ostream& operator << (std::ostream& out, const Line<T>& line)
{
    out << line.toString();

    return out;
}

#endif // LINE_H_INCLUDED
