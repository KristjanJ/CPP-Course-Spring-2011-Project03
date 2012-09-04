#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

#include <string>
#include <sstream>
#include <vector>

/*!
\brief An n-dimensional polygon.
*/
template <class T, int n>
class Polygon
{
public:
    /*!
    \details The tip points of this polygon.
    */
    std::vector<T> pts;

    /*!
    \details Default constructor.
    */
    Polygon<T, n>();

    /*!
    \details Constructs a polygon of given points.
    \param pts Tip points.
    */
    Polygon<T, n>(std::vector<T> pts);

    /*!
    \details Returns the circumference of this polygon.
    \returns The circumference of this polygon.
    */
    float circumference();

    /*!
    \details Returns the string representation of this polygon.
    \returns The string representation of this polygon.
    */
    std::string toString() const;
};

template <class T, int n>
Polygon<T, n>::Polygon()
{
    for (int i = 0; i < n; i++)
    {
        T t;
        pts.push_back(t);
    }
}

template <class T, int n>
Polygon<T, n>::Polygon(std::vector<T> pts)
{
    if (pts.size() == n)
    {
        this->pts = pts;
    }
    else
    {
        std::string exceptionString("Polygon: Invalid number of tip points.");
        throw exceptionString;
    }
}

template <class T, int n>
float Polygon<T, n>::circumference()
{
    float circumference = 0;

    int size = pts.size();

    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            circumference = circumference + pts.at(i).distanceFrom(pts.at(i + 1));
        }
        else
        {
            circumference = circumference + pts.at(i).distanceFrom(pts.at(0));
        }
    }

    return circumference;
}

template <class T, int n>
std::string Polygon<T, n>::toString() const
{
    std::ostringstream outStringStream;
    outStringStream << "(";

    int size = pts.size();

    for (int i = 0; i < size; i++)
    {
        outStringStream << pts.at(i).toString();

        if (i != size - 1)
        {
            outStringStream << ", ";
        }
    }

    outStringStream << ")";

    return outStringStream.str();
}

template <class T, int n>
std::ostream& operator << (std::ostream& out, const Polygon<T, n>& polygon)
{
    out << polygon.toString();

    return out;
}

#endif // POLYGON_H_INCLUDED
