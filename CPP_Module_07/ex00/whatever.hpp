#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap_(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min_(T a, T b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
T max_(T a, T b)
{
    if (a > b)
        return a;
    return b;
}

#endif
