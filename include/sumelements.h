#ifndef SUMELEMENTS_H_INCLUDED
#define SUMELEMENTS_H_INCLUDED

/*!
\brief A functor that sums elements of type T.
*/
template <class T>
class SumElements
{
public:
    /*!
    \details result.
    */
    T m_result;

    /*!
    \details Default constructor.
    */
    SumElements<T>();

    /*!
    \details Overloaded () operator to handle this object as a function object.
    \param value Value of type T.
    */
    void operator () (T value);

    /*!
    \details Returns the sum.
    \returns The sum;
    */
    T result();

private:
    int counter;
};

template <class T>
SumElements<T>::SumElements()
{
    counter = 0;
}

template <class T>
void SumElements<T>::operator () (T value)
{
    //Type of m_result is unknown, so we can't set it to 0 in constructor.
    //However we also can't except it to contain 0 if it's a primitive type and we don't initialize it.
    if (counter == 0)
    {
        m_result = value;
    }
    else
    {
        m_result = m_result + value;
    }

    counter++;
}

template <class T>
T SumElements<T>::result()
{
    return m_result;
}

#endif // SUMELEMENTS_H_INCLUDED
